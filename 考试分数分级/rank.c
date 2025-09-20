#include <stdio.h>
#include <windows.h>

float score;
int rank;

int main(){
    printf("说吧，你考了多少？(满分100) ： ");
    scanf("%f",&score);
    rank = score/10;
    switch(rank){
        case 10:
        case 9:
            printf("等级A\n");
            break;
        case 8:
            printf("等级B\n");
            break;
        case 7:
            printf("等级C\n");
            break;
        case 6:
            printf("等级D\n");
            break;
        case 5:
        case 4:
        case 3:
        case 2:
        case 1:
        case 0:
            printf("等级E\n");
            break;
        default:
            printf("孩子啊，你是输错成绩了还是怎么了？\n");
    }
    system("pause");
    return 0;
}