#include <stdio.h>
#include <math.h>

double cal1(double a,double b,double c){
    double x1;
    x1 = (-b+sqrt(b*b-4*a*c))/(2*a);
    return x1;
}
double cal2(double a,double b,double c){
    double x2;
    x2 = (-b-sqrt(b*b-4*a*c))/(2*a);
    return x2;
}

int main(){
    double a,b,c;
    scanf("%lf %lf %lf",&a,&b,&c);
    printf("r1=  %.2f\nr2=  %.2f\n",cal1(a,b,c),cal2(a,b,c));
}