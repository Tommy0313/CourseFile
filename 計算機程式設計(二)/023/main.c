#include <stdio.h>
#include <string.h>

//評分類別:
typedef enum scoreType_s{G,GPA,S}scoreType_t;
//等第評分:
typedef enum G_s{Aplus=95,A=87,Aduce=82,Bplus=78,B=75,Bduce=70,Cplus=68,C=65,Cduce=60,F=50,X=0}G_t;
//GPA評分:
typedef enum GPA_s{b4dot3=95,b4dot0=87,b3dot7=82,b3dot3=78,b3dot0=75,b2dot7=70,b2dot3=68,b2dot0=65,b1dot7=60,b1=50,b0=0}GPA_t;
//百分制區間評分:
typedef enum S_s{b90to100=95,b85to89=87,b80to84=82, b77to79=78,b73to76=75,b70to72=70,b67to69=68,b63to66=65,b60to62=60,b1to59=50,b0to0=0}S_t;
//學生分數類型:
typedef union student_s{
int score;
G_t G;
GPA_t GPA;
S_t S;
}student_t;
//一個班級有N位同學及M門課程，每一門課可以設定分數的評分方式。

scoreType_t scan_score_method(char score_method[4]){
    char str1[4] = "G";
    char str2[4] = "GPA";
    if(strcmp(score_method,str1) == 0){
        return G;
    }
    else if(strcmp(score_method,str2) == 0){
        return GPA;
    }
    else{
        return S;
    }
}

G_t G_trans(char temp_score[20]){
    char str1[4] = "A+";
    char str2[4] = "A";
    char str3[4] = "A-";
    char str4[4] = "B+";
    char str5[4] = "B";
    char str6[4] = "B-";
    char str7[4] = "C+";
    char str8[4] = "C";
    char str9[4] = "C-";
    char str10[4] = "F";
    char str11[4] = "X";
    if(strcmp(temp_score,str1) == 0) return Aplus;
    if(strcmp(temp_score,str2) == 0) return A;
    if(strcmp(temp_score,str3) == 0) return Aduce;
    if(strcmp(temp_score,str4) == 0) return Bplus;
    if(strcmp(temp_score,str5) == 0) return B;
    if(strcmp(temp_score,str6) == 0) return Bduce;
    if(strcmp(temp_score,str7) == 0) return Cplus;
    if(strcmp(temp_score,str8) == 0) return C;
    if(strcmp(temp_score,str9) == 0) return Cduce;
    if(strcmp(temp_score,str10) == 0) return F;
    if(strcmp(temp_score,str11) == 0) return X;
}

GPA_t GPA_trans(char temp_score[20]){
    char str1[4] = "4.3";
    char str2[4] = "4.0";
    char str3[4] = "3.7";
    char str4[4] = "3.3";
    char str5[4] = "3.0";
    char str6[4] = "2.7";
    char str7[4] = "2.3";
    char str8[4] = "2.0";
    char str9[4] = "1.7";
    char str10[4] = "1";
    char str11[4] = "0";
    if(strcmp(temp_score,str1) == 0) return b4dot3;
    if(strcmp(temp_score,str2) == 0) return b4dot0;
    if(strcmp(temp_score,str3) == 0) return b3dot7;
    if(strcmp(temp_score,str4) == 0) return b3dot3;
    if(strcmp(temp_score,str5) == 0) return b3dot0;
    if(strcmp(temp_score,str6) == 0) return b2dot7;
    if(strcmp(temp_score,str7) == 0) return b2dot3;
    if(strcmp(temp_score,str8) == 0) return b2dot0;
    if(strcmp(temp_score,str9) == 0) return b1dot7;
    if(strcmp(temp_score,str10) == 0) return b1;
    if(strcmp(temp_score,str11) == 0) return b0;
}

S_t S_trans(char temp_score[20]){
    char str1[10] = "90-100";
    char str2[10] = "85-89";
    char str3[10] = "80-84";
    char str4[10] = "77-79";
    char str5[10] = "73-76";
    char str6[10] = "70-72";
    char str7[10] = "67-69";
    char str8[10] = "63-66";
    char str9[10] = "60-62";
    char str10[10] = "1-59";
    char str11[10] = "0";
    if(strcmp(temp_score,str1) == 0) return b90to100;
    if(strcmp(temp_score,str2) == 0) return b85to89;
    if(strcmp(temp_score,str3) == 0) return b80to84;
    if(strcmp(temp_score,str4) == 0) return b77to79;
    if(strcmp(temp_score,str5) == 0) return b73to76;
    if(strcmp(temp_score,str6) == 0) return b70to72;
    if(strcmp(temp_score,str7) == 0) return b67to69;
    if(strcmp(temp_score,str8) == 0) return b63to66;
    if(strcmp(temp_score,str9) == 0) return b60to62;
    if(strcmp(temp_score,str10) == 0) return b1to59;
    if(strcmp(temp_score,str11) == 0) return b0to0;
}

int transform_score(char temp_score[20],student_t student,char score_method[4]){
    scoreType_t type;
    type = scan_score_method(score_method);
    if(type == G){
        student.G = G_trans(temp_score);
        return student.score;
    }
    else if(type == GPA){
        student.GPA = GPA_trans(temp_score);
        return student.score;
    }
    else{
        student.S = S_trans(temp_score);
        return student.score;
    }
}

int main(){
    int course_number;
    scanf("%d",&course_number);
    getchar();
    char score_method[course_number][4];
    for(int i=0;i<course_number;i++){
        scanf("%s",score_method[i]);
        getchar();
    }
    int student_number;
    scanf("%d",&student_number);
    getchar();
    student_t students[student_number][course_number];
    int student_id[student_number];
    int scores[student_number];
    char temp_score[20];
    float total_score=0;
    for(int i=0;i<student_number;i++){
        scanf("%d",&student_id[i]);
        total_score = 0;
        for(int j=0;j<course_number;j++){
            scanf(" %s",temp_score);
            total_score = total_score + transform_score(temp_score,students[i][j],score_method[j]);
        }
        scores[i] = total_score / course_number;
    }

    int index;
    for(int i=0;i<student_number;i++){
        index = 0;
        for(int j=0;j<student_number;j++){
            if(scores[index] > scores[j]) index = j;
        }
        printf("%d %d\n",student_id[index],scores[index]);
        scores[index] = 1000;
    }
}
