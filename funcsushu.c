#include <stdio.h>
#include <windows.h>

int num;

boolean judge(num){
    boolean flag = 0;
    for(int i=2;i<num;i++){
        if(num%i==0){
            flag = 1;
            break;
        }
    }
    return flag;
}

int main(){
    printf("请输入一个自然数以判断其是否为素数：");
    scanf("%d",&num);
    if(num>=0){
        if(judge(num)==1){
            printf("不是质数！\n");
            system("pause");
            return 0;
        }else{
            printf("是质数！\n");
            system("pause");
            return 0;
        }
    }else{
        printf("让你输入自然数你是不是听不懂啊？！\n");
        system("pause");
        return 0;
    }
}