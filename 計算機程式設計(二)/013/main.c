#include<stdio.h>

int gcd(int m,int n){
    if(n==0){
        return m;
    }
    else{
        return gcd(n, m%n);
    }
}

int print(int x1,int y1,int x2,int y2){
    int m_mother,m_child,b_mother,b_child;
    m_child = (y1 - y2);
    m_mother = (x1 - x2);
    b_child = (x2 * y1 - x1 * y2) ;
    b_mother = (x2 - x1);

    int m_change = gcd(m_child,m_mother);
    m_child = m_child/m_change;
    m_mother = m_mother/m_change;
    int b_change = gcd(b_child,b_mother);
    b_child = b_child/b_change;
    b_mother = b_mother/b_change;

    printf("y = ");

    if(m_child/m_mother==1  && m_child%m_mother == 0){
        printf("x");
    }
    else if(m_child/m_mother==-1 && m_child%m_mother == 0){
        printf("-x");
    }
    else if(m_child % m_mother == 0 && m_child / m_mother ==0){
        if(b_child%b_mother == 0){
            printf("%d",b_child/b_mother);
        }
        else{
            if(b_child*b_mother>0){
                if(b_child > 0){
                    printf("%d/%d",b_child,b_mother);
                }
                else{
                    printf("-%d/%d",-b_child,-b_mother);
                }
            }
            else{
                if(b_child > 0){
                    printf("-%d/%d",b_child,-b_mother);
                }
                else{
                    printf("-%d/%d",-b_child,b_mother);
                }
            }
        }
    }
    else if(m_child % m_mother == 0){
        printf("%dx",m_child / m_mother);
    }
    else{
        if(m_child*m_mother>0){
            if(m_child > 0){
                printf("%d/%dx",m_child,m_mother);
            }
            else{
                printf("%d/%dx",-m_child,-m_mother);
            }
        }
        else{
            if(m_child > 0){
                printf("-%d/%dx",m_child,-m_mother);
            }
            else{
                printf("-%d/%dx",-m_child,m_mother);
            }
        }
    }


    if(!(m_child % m_mother == 0 && m_child / m_mother ==0)){
        if(!(b_child%b_mother==0 && b_child/b_mother==0)){
            if(b_child%b_mother == 0){
                if(b_child/b_mother>0){
                   printf(" + %d",b_child/b_mother);
                }
                else{
                    printf(" - %d",-b_child/b_mother);
                }
            }
            else{
                if(b_child*b_mother>0){
                    if(b_child > 0){
                        printf(" + %d/%d",b_child,b_mother);
                    }
                    else{
                        printf(" + %d/%d",-b_child,-b_mother);
                    }
                }
                else{
                    if(b_child > 0){
                        printf(" - %d/%d",b_child,-b_mother);
                    }
                    else{
                        printf(" - %d/%d",-b_child,b_mother);
                    }
                }
            }
        }
    }

    printf("\n");
}

int main(){
    int numbers,x1,y1,x2,y2;
    scanf("%d",&numbers);
    getchar();
    for(int i = 0;i<numbers;i++){
        scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
        print(x1, y1, x2, y2);
    }
}
