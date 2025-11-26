#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int judgement(char *num){
    int counter = 0;
    if(*num != '1') return 0;
    for(int i=0;i<=10;i++){
        if(!(isdigit((unsigned char)num[i]))) exit(1);
        if(num[i] == '4'){
            return 0;
        }else if(num[i] == '6' || num[i] == '8'){
            counter++;
        }
    }
    if(counter >= 5) return 1;
    return 0;
}
int main(){
    const int cols = 12;
    int rows = 1;
    int size = 0;
    char **num = NULL;
    num = malloc(rows * sizeof(char*));
    if(num == NULL) exit(1);
    char buf[12];
    while(scanf("%11s",buf) != EOF){
        for(int i=0;i<=10;i++){
            if(!(isdigit((unsigned char)buf[i]))) exit(1);
        }
        if(size >= rows){
            rows *= 2;
            num = realloc(num,rows*sizeof(char*));
            if(num == NULL) exit(1);
        }
        num[size] = malloc(cols*sizeof(char));
        if(num[size] == NULL) exit(1);
        strncpy(num[size],buf,cols-1);
        num[size][11] = '\0';
        size++;
    }
    int counter = 0;
    for(int i=0;i<=size-1;i++){
        if(judgement(num[i])){
            counter++;
            printf("%11s\n",num[i]);
        }
        free(num[i]);
    }
    free(num);
    printf("%d\n",counter);
}