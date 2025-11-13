#include <stdio.h>

int leap(int year){
    if(((year%4==0)&&(year%100!=0))||(year%400==0)){
        return 1;
    }else{
        return 2;
    }
}

int modays(int month){
    if(month == 1 || month == 3|| month == 5|| month == 7|| month == 8|| month == 10|| month == 12){
        return 1;
    }else if(month == 2){
        return 2;
    }else{
        return 3;
    }
}

int main(){
    int year,month,day;
    int sum = 0;
    scanf("%d %d %d",&year,&month,&day);
    for(int i=1;i<=month-1;i++){
        switch(leap(year)){
            case 1:
                if(modays(i) == 2){
                    sum += 29;
                }else if(modays(i) == 1){
                    sum += 31;
                }else{
                    sum += 30;
                }
                break;
            case 2:
                if(modays(i) == 2){
                    sum += 28;
                }else if(modays(i) == 1){
                    sum += 31;
                }else{
                    sum += 30;
                }
                break;
        }
    }
    sum += day;
    printf("%d\n",sum);
}