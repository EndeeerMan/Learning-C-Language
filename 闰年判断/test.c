#include <stdio.h>
#include <windows.h>
//本程序为闰年的判断
int year;
int main(){
    printf("请输入一个有效的公元年份\n（只取整数，且限定在0~9999）:");
    scanf("%d",&year);
    if(year<=9999&&year>=0){
        if(((year%4==0)&&(year%100!=0))||(year%400==0)){
            printf("你输入的是闰年！\n");
            system("pause");
            return 0;
        }else{
            printf("你输入的不是闰年！\n");
            system("pause");
            return 0;
        }
    }else{
        printf("输入的什么玩意啊这是！\n");
        system("pause");
        return 0;
    }
}
    