#include <stdio.h>
#include <windows.h>

struct human{
    char* name;
    int age;
    float height;
};

int main(){
    char name1[50];
    int age1;
    float height1;
    printf("请依次输入姓名、年龄、身高（米），并使用空格隔开：\n");
    scanf("%49s %d %f",name1,&age1,&height1);
    struct human human1 = {name1,age1,height1};
    struct human *human1p = &human1;
    printf("--- 读取到的信息 ---\n");
    printf("姓名：%s\n",(human1p->name));
    printf("年龄：%d\n",(human1p->age));
    printf("身高：%.2f\n",(human1p->height));
    system("pause");
    return 0;
}