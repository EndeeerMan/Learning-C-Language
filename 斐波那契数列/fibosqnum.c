#include <stdio.h>
#include <stdlib.h>

void print_int128(__int128 num){
    int digits[50];
    int d = 0;
    int counter = 0;
    if(num == 0){
        printf("0");
        return;
    }
    if(num < 0){putchar('-'); num = -num;}
    while(num > 0){
        d = num % 10;
        num /= 10;
        digits[counter++] = d;
    }
    for(int i=counter-1;i>=0;i--){
        printf("%d",digits[i]);
    }
}

int main(){
    __int128 num[3] = {1,1,2};
    int n = 0;
    scanf("%d",&n);
    switch(n){
        case 0:
            exit(0);
        case 1:
            printf("1\n");
            exit(0);
        case 2:
            printf("1\n1\n");
            exit(0);
        default:
            printf("1\n1\n");
            n -= 2;
            for(int i=1;i<=n;i++){
                num[2] = num[0] + num[1];
                print_int128(num[2]);
                printf("\n");
                num[0] = num[1];
                num[1] = num[2];
            }
    }
    exit(0);
}