#include <stdio.h>
#include <stdlib.h>

int routeInroutes(int throughed_route[101], int route){
    for(int i=1;i<=throughed_route[0];i++){
        if(route == throughed_route[i]) return 1;
    }
    return 0;
}

void copy(int smallest_throughed_route[101], int throughed_route[101]){
    for(int i=0;i<=throughed_route[0];i++){
        smallest_throughed_route[i] = throughed_route[i];
    }
}

void runRoute(int city[21][16],int *smallest_route_number,int smallest_throughed_route[101],int throughed_route[101],int X,int Z,int Y){
    throughed_route[0]++;
    throughed_route[throughed_route[0]] = X;
    if(Z == X){
        if(throughed_route[0] < *smallest_route_number){
            if(Y == NULL){
                *smallest_route_number = throughed_route[0];
                copy(smallest_throughed_route,throughed_route);
            }
            else if(routeInroutes(throughed_route,Y) == 1){
                *smallest_route_number = throughed_route[0];
                copy(smallest_throughed_route,throughed_route);
            }
        }
    }
    else{
        for(int i=1;i<=city[X][0];i++){
            if(routeInroutes(throughed_route,city[X][i]) == 0){
                runRoute(city,smallest_route_number,smallest_throughed_route,throughed_route,city[X][i],Z,Y);
            }
        }
    }
    throughed_route[0]--;
}


int main(){
    int city[21][16] = {0};
    int N,X,Z,Y=NULL;
    char keyword;
    scanf("%d %d %d",&N,&X,&Z);
    keyword = getchar();
    if(keyword == ' '){
        scanf("%d",&Y);
        getchar();
    }
    int route1,route2;
    for(int i=0;i<N;i++){
        scanf("%d %d",&route1,&route2);
        city[route1][0]++;
        city[route2][0]++;
        city[route1][city[route1][0]] = route2;
        city[route2][city[route2][0]] = route1;
    }

    int throughed_route[101] = {0};
    int smallest_throughed_route[101] = {0};
    int smallest_route_number = 999;

    runRoute(city, &smallest_route_number, smallest_throughed_route, throughed_route, X, Z, Y);
    if(smallest_route_number == 999){
        printf("NO");
    }
    else{
        printf("%d\n",smallest_route_number-1);
        printf("%d",smallest_throughed_route[1]);
        for(int i=2;i<=smallest_route_number;i++){
            printf(" %d",smallest_throughed_route[i]);
        }
    }

}
