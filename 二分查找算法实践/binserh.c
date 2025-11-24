#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int Normal_Search(int a,int b,int num){
    int counter = 0;
    for(int i=a;i<=b;i++){
        counter++;
        if(i == num){
            return counter;
        }
        printf("%d\n",i);
    }
    return -1;
}

int Binary_Search(int a,int b,int num){
    int counter = 0;
    int lower = a, higher = b;
    int i = 0;
    while(lower <= higher){
        i = lower + (higher - lower)/2;
        counter++;
        if(i < num){
            lower = i + 1;
            printf("%d\n",i);
        }else if(i > num){
            higher = i - 1;
            printf("%d\n",i);
        }else{
            printf("%d\n",i);
            return counter;
        }
    }
    return -1;
}

int main(){
    int num = 0;
    int a = 0;
    int b = 0;
    printf("输入范围，空格隔开: ");
    scanf("%d %d",&a,&b);
    printf("输入需要查找的数: ");
    scanf("%d",&num);
    assert(a <= num && num <= b);
    printf("1.顺序遍历 2.二分查找\n");
    printf("选择算法: ");
    int sw = 0;
    scanf("%d",&sw);
    assert(sw == 1 || sw == 2);
    switch(sw){
        case 1:
            printf("计算机一共猜了 %d 次。\n",Normal_Search(a,b,num));
            break;
        case 2:
            printf("计算机一共猜了 %d 次。\n",Binary_Search(a,b,num));
            break;
    }
    return 0;
}