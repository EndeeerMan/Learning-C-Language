#include <stdio.h>
#include <windows.h>

int i1,i2;
boolean flag=0;

int main(){
    for(i1=100;i1<=200;i1++){
        flag=0;
        for(i2=2;i2<i1;i2++){
            if(i1%i2==0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            printf("%d ",i1);
        } 
    }
    printf("\n");
    system("pause");
    return 0;
}