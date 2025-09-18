#include <math.h>
#include <stdio.h>

void main(){
    float a,b,c;
    scanf("%f",&a);
    getchar();
    scanf("%f",&b);
    getchar();
    scanf("%f",&c);
    if(b*b-4*a*c <0){
        printf("%.1f+%.1fi",round(( -b ) / ( 2 * a )*10)/10,round( ( sqrt( -1 * ( b * b - 4 * a * c )) / ( 2 * a ))*10 )/10 );
        printf("\n%.1f-%.1fi",round(( -b ) / ( 2 * a )*10)/10,round(( sqrt( -1 * ( b * b - 4 * a * c )) / ( 2 * a ))*10 )/10);
    }
    else{
        if((((-b) + sqrt(b * b - 4 * a * c)) / (2 * a))==0){
            printf("%.1f",0);
            printf("\n%.1f",0);
        }
        else{
            printf("%.1f",round((((-b) + sqrt(b * b - 4 * a * c)) / (2 * a))*10)/10);
            printf("\n%.1f",round((((-b) - sqrt(b * b - 4 * a * c)) / (2 * a))*10 )/10);
        }
    }
}
