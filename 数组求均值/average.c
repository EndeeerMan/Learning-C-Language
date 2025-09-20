#include <windows.h>
#include <stdio.h>

float a[10]={1.2,7,5,1.8,1.6,0.8,4,1.0,6,2.2};
float b;
int highest;
int main(){
    for(int i=0;i<=9;i++){
        b += a[i];
    }
    printf("平均值是：%.2f\n",b/10);
    for(int i=0;i<=9;i++){
        if(a[i]<b/10){
            printf("%.2f\n",a[i]);
        }
    }
    system("pause");
    return 0;
}