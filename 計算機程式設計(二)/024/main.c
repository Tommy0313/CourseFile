#include <stdio.h>


typedef struct student_s{
char name[50];
int score;
}student_t;

//新增n位學生的資料
void input(student_t s[], int n);
//回傳班級內分數最高的姓名(使用參數char name[])
void getHigh(student_t s[], int n, char name[]);
//回傳班級內所有學生的平均成績無條件捨去至整數
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
