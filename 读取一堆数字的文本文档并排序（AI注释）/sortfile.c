#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 冒泡排序函数（使用goto循环实现）
// 参数：arr — 待排序的数组指针，length — 数组长度
// 返回：排序后的数组指针（升序）
long long *sorting(long long *arr, long long length) {
    long long swapper = 0; // 用于交换元素的临时变量

swap: // 标签，用于 goto 返回到重新排序
    for (int i = 0; i < length - 1; i++) {
        if (arr[i] > arr[i + 1]) { // 如果前一个比后一个大，就交换
            swapper = arr[i + 1];
            arr[i + 1] = arr[i];
            arr[i] = swapper;
            swapper = 0;
        }
    }

    // 检查是否仍有逆序对，如果有则再次排序
    for (int i = 0; i < length - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            goto swap; // 继续循环
        }
    }

    return arr;
}

// 字符串转 long long 整数
long long str2int(char *str_num) {
    long long num = 0;
    sscanf(str_num, "%lld", &num);
    return num;
}

// long long 整数转字符串（动态分配内存，调用者负责释放）
char *int2str(long long num) {
    char *str = malloc(32); // 预留32字节足够存放long long
    sprintf(str, "%lld", num);
    return str;
}

int main() {
    const char *raw_file = "raw.txt";      // 输入文件
    const char *output_file = "output.txt"; // 输出文件
    const char *read_mode = "r";
    const char *write_mode = "w";

    FILE *raw = fopen(raw_file, read_mode);
    FILE *output = fopen(output_file, write_mode);

    // 检查文件是否成功打开
    if (raw == NULL || output == NULL) {
        printf("遇到了一个严重的错误，程序即将终止！(code:1)\n");
        if (raw) fclose(raw);
        if (output) fclose(output);
        exit(1);
    }

    long long *arr = NULL;
    char *raw_numbers = NULL;

    // 获取文件长度
    fseek(raw, 0, SEEK_END);
    long long raw_length = ftell(raw);
    raw_numbers = malloc(raw_length + 1); // +1 用于存放 '\0'
    fseek(raw, 0, SEEK_SET);

    // 读取整个文件内容到 raw_numbers
    fread(raw_numbers, 1, raw_length, raw);
    raw_numbers[raw_length] = '\0';

    // 定义分隔符（空格、换行、制表符）
    char *split_flag = " \n\t";

    // strtok 会破坏原字符串，所以复制一份
    char *raw_numbers_copy = strdup(raw_numbers);

    // 检查文件中是否至少有一个数字
    if (strtok(raw_numbers, split_flag) == NULL) {
        printf("遇到了一个严重的错误，程序即将终止！(code:2)\n");
        if (raw) fclose(raw);
        if (output) fclose(output);
        free(raw_numbers);
        free(raw_numbers_copy);
        exit(1);
    }

    // 计算文件中数字的个数
    long long counter = 1;
    while (strtok(NULL, split_flag) != NULL) {
        counter++;
    }

    // 分配数组空间
    arr = malloc(counter * sizeof(long long));
    if (arr == NULL) {
        printf("遇到了一个严重的错误，程序即将终止！(code:3)\n");
        if (raw) fclose(raw);
        if (output) fclose(output);
        free(raw_numbers);
        free(raw_numbers_copy);
        exit(1);
    }

    // 使用 strtok 从复制的字符串中提取每个数字并转换为 long long
    arr[0] = str2int(strtok(raw_numbers_copy, split_flag));
    for (int i = 1; i < counter; i++) {
        arr[i] = str2int(strtok(NULL, split_flag));
    }

    // 排序
    long long *result = sorting(arr, counter);

    // 输出到文件（空格分隔）
    for (int i = 0; i < counter; i++) {
        fprintf(output, "%lld ", result[i]);
    }

    // 释放资源
    if (raw) fclose(raw);
    if (output) fclose(output);
    free(raw_numbers);
    free(arr);
    free(raw_numbers_copy);

    printf("Completed!\n");
    return 0;
}
