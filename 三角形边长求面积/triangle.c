#include <stdio.h>
#include <math.h>

double area(double a,double b,double c){
    if(a+b<=c || a+c<=b || b+c<=a){
        return -1;
    }else{
        double mem;
        mem = (a+b+c)/2;
        double mem1 = mem*(mem-a)*(mem-b)*(mem-c);
        return sqrt(mem1);
    }
}

int main(){
    double a,b,c;
    scanf("%lf %lf %lf",&a,&b,&c);
    printf("area=%.15lf\n",area(a,b,c));
}