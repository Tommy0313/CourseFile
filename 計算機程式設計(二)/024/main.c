#include <stdio.h>


typedef struct student_s{
char name[50];
int score;
}student_t;

//�s�Wn��ǥͪ����
void input(student_t s[], int n);
//�^�ǯZ�Ť����Ƴ̰����m�W(�ϥΰѼ�char name[])
void getHigh(student_t s[], int n, char name[]);
//�^�ǯZ�Ť��Ҧ��ǥͪ��������Z�L����˥h�ܾ��
int getAverage(student_t s[], int n);


int main(){
    int student_number,highest_score=0,index=0,total_score=0;
    scanf("%d", &student_number);
    student_t students[student_number];

    for(int i=0;i<student_number;i++){
        scanf("%s",students[i].name);
        getchar();
        scanf("%d",&students[i].score);
        getchar();
        total_score = total_score + students[i].score;
        if(students[i].score>highest_score){
            index = i;
            highest_score = students[i].score;
        }
    }
    printf("%s\n",students[index].name);
    printf("%d",total_score/student_number);

}
