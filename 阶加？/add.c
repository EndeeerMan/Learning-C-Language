#include <stdio.h>
#include <windows.h>

int num1,num2,i;

int main(){
    printf("输入一个整数：");
    scanf("%d",&num1);
    for(i=1;i<=num1;i++){
        num2 += i;
    }
    printf("%d\n",num2);
    system("pause");
    return 0;
}