#include <stdio.h>
#include <windows.h>

float time;

int main(){
    printf("快交代吧，你究竟上了多长时间的因特网！（小时）\n请输入：");
    scanf("%f",&time);
    if(time<=10){
        printf("30元，请~\n");
        system("pause");
        return 0;
    }else if(time>10&&time<50){
        printf("%.2f元，请~\n",time*3);
        system("pause");
        return 0;
    }else if(time>=50){
        printf("%.2f元，请~\n",time*2.5);
        system("pause");
        return 0;
    }else{
        printf("滚！\n");
        system("pause");
        return 0;
    }
    return 0;
}