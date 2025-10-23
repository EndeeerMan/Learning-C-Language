#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL;   // 指针，初始为空
    int size = 0;      // 当前元素个数
    int capacity = 0;  // 初始元素容量（可根据需要调整）
    int num;

    arr = (int *)malloc(capacity * sizeof(int));
    if (arr == NULL) {
        printf("内存分配失败！\n");
        return 1;
    }

    printf("请输入若干整数，以非数字或 EOF 结束：\n");
    while (scanf("%d", &num) == 1) {  // 一直读，直到输入不是数字
        // 检查是否需要扩容
        if (size >= capacity) {
            capacity ++;
            if(realloc(arr, capacity * sizeof(int)) == NULL){
				printf("内存扩容失败！\n");
				free(arr);
				return 1;
			}
        }
        arr[size++] = num;
    }

    printf("\n读取到 %d 个数：\n", size);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);  // 释放内存
    return 0;
}
