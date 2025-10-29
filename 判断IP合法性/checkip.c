#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int judge(char *ip){
    int num = 0;
    if(sscanf(ip,"%d",&num) != 1){
        printf("N\n");
        exit(0);
    }
    if(0<=num && num<=255){
        return 1;
    }else{
        printf("N\n");
        exit(0);
    }
}

int main(){
    char *address = NULL;
    int size = 0;
    int capacity = 20;
    address = malloc(sizeof(char)*capacity);
    if(address == NULL){
        printf("FATAL ERROR!\n");
        exit(1);
    }
    char temp_char;
    while(scanf("%c",&temp_char) == 1 && temp_char !='\0' && temp_char !='\n'){
        if(capacity<=size){
            printf("N\n");
            return 0;
        }
        address[size++] = temp_char;
    }
    char *ip = NULL;
    ip = malloc(sizeof(char)*20);
    char *splitflag = ".\n ";
    char *address_backup = strdup(address);
    int counter = 0;

    char *temp_str = strtok(address_backup,splitflag);
    if(temp_str == NULL){
        printf("FATAL ERROR!\n");
        free(address);
        exit(1);
    }else{
        counter++;
    }
    temp_str = strtok(NULL,splitflag);
    while(temp_str !=  NULL){
        counter ++;
        temp_str = strtok(NULL,splitflag);
    }
    if(counter != 4){
        printf("N\n");
        return 0;
    }else{
        ip = strtok(address,splitflag);
        judge(ip);
        for(int i=0;i<3;i++){
            judge(strtok(NULL,splitflag));
        }
    }
    printf("Y\n");
    return 0;
}