#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node_s {
    int machine;
    int time;
    struct node_s* next;
} node_t;

typedef struct {
    node_t* head;
    node_t* tail;
    int num_steps;
    int next_step_index;
    int completion_time;
} job_t;

typedef struct {
    job_t* jobs;
    int num_jobs;
    int* machine_end_time;
    int num_machines;
} schedule_t;

node_t* create_node(int machine, int time) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->machine = machine;
    new_node->time = time;
    new_node->next = NULL;
    return new_node;
}

job_t create_job() {
    job_t job;
    job.head = job.tail = NULL;
    job.num_steps = 0;
    job.next_step_index = 0;
    job.completion_time = 0;
    return job;
}

void add_step(job_t* job, int machine, int time) {
    node_t* new_node = create_node(machine, time);
    if (job->tail) {
        job->tail->next = new_node;
    } else {
        job->head = new_node;
    }
    job->tail = new_node;
    job->num_steps++;
}

schedule_t create_schedule(int num_machines, int num_jobs) {
    schedule_t schedule;
    schedule.num_machines = num_machines;
    schedule.num_jobs = num_jobs;
    schedule.jobs = (job_t*)malloc(sizeof(job_t) * num_jobs);
    schedule.machine_end_time = (int*)malloc(sizeof(int) * num_machines);
    for (int i = 0; i < num_machines; i++) {
        schedule.machine_end_time[i] = 0;
    }
    for (int i = 0; i < num_jobs; i++) {
        schedule.jobs[i] = create_job();
    }
    return schedule;
}

void free_schedule(schedule_t* schedule) {
    for (int i = 0; i < schedule->num_jobs; i++) {
        node_t* current = schedule->jobs[i].head;
        while (current) {
            node_t* next = current->next;
            free(current);
            current = next;
        }
    }
    free(schedule->jobs);
    free(schedule->machine_end_time);
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int calculate_earliest_completion_time(schedule_t* schedule, int job_index) {
    job_t* job = &schedule->jobs[job_index];
    if (job->next_step_index >= job->num_steps) return INT_MAX;

    node_t* step = job->head;
    for (int i = 0; i < job->next_step_index; i++) {
        step = step->next;
    }

    int machine = step->machine;
    int start_time = max(schedule->machine_end_time[machine], job->completion_time);
    int completion_time = start_time + step->time;
    return completion_time;
}

void schedule_jobs(schedule_t* schedule) {
    int total_completion_time = 0;
    int completed_jobs = 0;

    while (completed_jobs < schedule->num_jobs) {
        int min_completion_time = INT_MAX;
        int job_to_schedule = -1;

        for (int i = 0; i < schedule->num_jobs; i++) {
            int completion_time = calculate_earliest_completion_time(schedule, i);
            if (completion_time < min_completion_time) {
                min_completion_time = completion_time;
                job_to_schedule = i;
            }
        }

        job_t* job = &schedule->jobs[job_to_schedule];
        node_t* step = job->head;
        for (int i = 0; i < job->next_step_index; i++) {
            step = step->next;
        }

        int machine = step->machine;
        int start_time = max(schedule->machine_end_time[machine], job->completion_time);
        job->completion_time = start_time + step->time;
        schedule->machine_end_time[machine] = job->completion_time;

        job->next_step_index++;
        if (job->next_step_index == job->num_steps) {
            total_completion_time += job->completion_time;
            completed_jobs++;
        }
    }

    printf("%d\n", total_completion_time);
}

void read_input(schedule_t* schedule) {
    int num_jobs = schedule->num_jobs;

    for (int i = 0; i < num_jobs; i++) {
        int num_steps;
        scanf("%d", &num_steps);
        for (int j = 0; j < num_steps; j++) {
            int machine, time;
            scanf("%d %d", &machine, &time);
            add_step(&schedule->jobs[i], machine, time);
        }
    }
}

int main() {
    int num_machines, num_jobs;
    scanf("%d %d", &num_machines, &num_jobs);

    schedule_t schedule = create_schedule(num_machines, num_jobs);
    read_input(&schedule);
    schedule_jobs(&schedule);

    free_schedule(&schedule);
    return 0;
}
