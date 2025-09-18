void main(){
    float w, h;
    float BMI,float_h;
    scanf("%f",&w);
    getchar();
    scanf("%f",&h);
    h = h/100;
    BMI = w/(h*h);
    printf("%.1f",BMI);
}
