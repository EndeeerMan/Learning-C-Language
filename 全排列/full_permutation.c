#include <stdio.h>
#include <stdlib.h>

// 函数：交换两个字符的位置
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// 函数：判断是否需要交换（初步去重逻辑）
// 返回 0 表示相同，不交换；返回 1 表示不同，允许交换
int should_swap(char *a, char *b) {
    if (*a == *b) return 0;
    return 1;
}

/**
 * 递归函数：生成并打印全排列
 * @param arr 待排列的字符串数组
 * @param l   当前需要确定的字符位置（左边界）
 * @param r   数组的末尾索引（右边界）
 */
void shuffle_and_print(char *arr, int l, int r) {
    // 递归终止条件：当左边界等于右边界时，说明所有位置已确定
    if (l == r) {
        // 针对数字排列的特殊处理：排除以 '0' 开头的情况
        if (*arr == '0') return;
        printf("%s\n", arr);
        return;
    }

    for (int i = l; i <= r; i++) {
        // 去重尝试：如果当前位置 l 的字符和我们要换过来的字符 i 相同，则跳过
        if (should_swap(&arr[l], &arr[i]) == 0 && i != l) continue;

        // 1. 交换：将第 i 个字符选定到当前位置 l
        swap(&arr[l], &arr[i]);

        // 2. 递归：固定 l 位置，去排列 l+1 之后的子串
        shuffle_and_print(arr, l + 1, r);

        // ⚠️ 注意：这里的回溯逻辑需要保证无条件执行
        // 如果这里加了 continue，会导致数组状态无法恢复，从而破坏后续的排列
        swap(&arr[i], &arr[l]); 
    }
}

int main() {
    char *arr = NULL;
    int size = 0;
    int capacity = 1;

    // 初始分配内存
    arr = malloc(sizeof(char) * capacity);
    if (arr == NULL) exit(1);

    int temp;
    // 循环读取字符直到换行或文件末尾
    while (1) {
        temp = getchar();
        if (temp == '\n' || temp == EOF) break;

        // 动态扩容逻辑：当 size 达到 capacity 时，容量翻倍
        if (++size >= capacity) {
            capacity *= 2;
            char *mem = realloc(arr, sizeof(char) * capacity);
            if (mem == NULL) {
                free(arr); // 失败前释放原有内存
                exit(1);
            }
            arr = mem;
        }
        arr[size - 1] = (char)temp; // 存入读到的字符
    }

    // 最后一次微调：为字符串结束符 '\0' 预留空间
    char *mem = realloc(arr, sizeof(char) * (size + 1));
    if (mem == NULL) {
        free(arr);
        exit(1);
    }
    arr = mem;
    arr[size] = '\0'; // 放置字符串结束符

    // 执行全排列
    shuffle_and_print(arr, 0, size - 1);

    // 释放动态分配的堆内存
    free(arr);
    return 0;
}