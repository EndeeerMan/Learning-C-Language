#include <stdio.h>
#include <ctype.h>

void print_int128(__int128 num){
    if(num == 0){
        printf("0\n");
        return;
    }
    if(num < 0){
        putchar('-');
        num = -num;
    }
    char arr[50];
    int counter = 0;
    while(num > 0){
        arr[counter++] = '0' + (num % 10);
        num /= 10;
    }
    for(int i=counter-1;i>=0;i--){
        putchar(arr[i]);
    }
    printf("\n");
}

__int128 read_int128(char *cnum){
    __int128 num = 0;
    int flag = 1;
    if(*cnum == '-') flag = -1;
    int i = 0;
    while(isdigit(cnum[i++])){

    }
}

int main(){
    const char *num1 = "17014118346046923173168730371588410572";
    __int128 num = 
}