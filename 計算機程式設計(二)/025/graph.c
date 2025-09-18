#include <stdio.h>
#include<math.h>

#define ShapeText(TYPE) char name[10]; double (*perimeter)(struct TYPE*); double (*area)(struct TYPE*)

typedef struct shape_s {
ShapeText(shape_s);
} shape_t;

typedef struct circle_s {
ShapeText(circle_s);
int radius;
int length;
int width;
int edge1;
int edge2;
int edge3;
} circle_t;

double getCperimeter(circle_t *obj){
    return 2 * 3.14 * obj->radius;
}

double getCarea(circle_t *obj){
    return 3.14 * obj->radius * obj->radius;
}

double getRperimeter(circle_t *obj){
    return 2 * (obj->length+obj->width);
}

double getRarea(circle_t *obj){
    return obj->length * obj->width;
}

double getSperimeter(circle_t *obj){
    return 4 * obj->edge1;
}

double getSarea(circle_t *obj){
    return obj->edge1 * obj->edge1;
}

double getTperimeter(circle_t *obj){
    return obj->edge1 + obj->edge2 + obj->edge3;
}

double getTarea(circle_t *obj){
    double s = (double)(obj->edge1 + obj->edge2 + obj->edge3)/2;
    return  sqrt(s*(s-obj->edge1)*(s-obj->edge2)*(s-obj->edge3));
}

int main(){
    int graph_number;
    char graph;
    int radius,length,width,edge1,edge2,edge3;
    scanf("%d",&graph_number);
    getchar();
    circle_t graphs[graph_number];
    for(int i=0;i<graph_number;i++){
        scanf("%c",&graph);
        if(graph == 'C'){
            scanf(" %d",&graphs[i].radius);
            getchar();
            graphs[i].area = getCarea;
            graphs[i].perimeter = getCperimeter;
        }
        else if(graph == 'R'){
            scanf(" %d %d",&graphs[i].length,&graphs[i].width);
            getchar();
            graphs[i].area = getRarea;
            graphs[i].perimeter = getRperimeter;
        }
        else if(graph == 'S'){
            scanf(" %d",&graphs[i].edge1);
            getchar();
            graphs[i].area = getSarea;
            graphs[i].perimeter = getSperimeter;
        }
        else if(graph == 'T'){
            scanf(" %d %d %d",&graphs[i].edge1,&graphs[i].edge2,&graphs[i].edge3);
            getchar();
            graphs[i].area = getTarea;
            graphs[i].perimeter = getTperimeter;
        }
    }

    double total_area=0,total_perimeter=0;
    double temp_area,temp_perimeter;

    for(int i=0;i<graph_number;i++){
        temp_area = graphs[i].area(&graphs[i]);
        temp_perimeter = graphs[i].perimeter(&graphs[i]);
        total_area = total_area + temp_area;
        total_perimeter = total_perimeter + temp_perimeter;
        printf("%.2f %.2f\n",temp_perimeter,temp_area);
    }
    printf("%.2f %.2f\n",total_perimeter,total_area);

}
