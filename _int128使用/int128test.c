#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void print_int128(__int128 num){
    if(num == 0){
        printf("0\n");
        return;
    }
    if(num < 0){putchar('-');num = -num;};
    int arr[50];
    int i = 0;
    while(num > 0){
        arr[i++] = num % 10;
        num /= 10;
    }
    for(i-=1;i>=0;i--){
        printf("%d",arr[i]);
    }
    return;
}

__int128 read_int128_from_string(char *cnum){
    __int128 num = 0;
    cnum = &cnum[0];
    while (*cnum == ' ' || *cnum == '\t' || *cnum == '\n') cnum++;
    if(*cnum == '0') return 0;
    int flag = 1;
    if(*cnum == '-'){cnum++;flag = -1;}
    if(*cnum == '+') cnum++;
    int digit = 0;
    while(isdigit((unsigned char)*cnum) && *cnum){
        digit = *cnum++ - '0';
        num = num*10 + digit;
    }
    return num*flag;
}

int main(){
    char *cnum = NULL;
    cnum = malloc(sizeof(char)*51);
    scanf("%50s",cnum);
    __int128 num = read_int128_from_string(cnum);
    print_int128(num);
    putchar('\n');
    return 0;
}