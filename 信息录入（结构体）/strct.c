#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct human{
    char name[50];
    int age;
    float height;
};

int main(){
    char name1[50];
    int age1;
    float height1;
    printf("请依次输入姓名、年龄、身高（米），并使用空格隔开：\n");
    scanf("%49s %d %f",name1,&age1,&height1);
    struct human human1;
    strcpy(human1.name,name1);
    human1.age = age1;
    human1.height = height1;

    struct human *human1p = &human1;
    printf("--- 读取到的信息 ---\n");
    printf("姓名：%s\n",(human1p->name));
    printf("年龄：%d\n",(human1p->age));
    printf("身高：%.2f\n",(human1p->height));
    system("pause");
    return 0;
}
