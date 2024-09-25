#include <stdio.h>  
#include <stdlib.h>  
  
// 函数声明  
void insertElement(int **array, int *size, int *capacity, int newElement, int index);  
void printArray(int *array, int size);  
void freeArray(int *array);  
  
int main() {  
    int *array = NULL; // 初始化为NULL，稍后会动态分配内存  
    int size = 0; // 当前数组中的元素数量  
    int capacity = 5; // 数组的初始容量  
  
    // 分配初始内存  
    array = (int *)malloc(capacity * sizeof(int));  
    if (!array) {  
        fprintf(stderr, "Memory allocation failed\n");  
        return EXIT_FAILURE;  
    }  
  
    // 填充数组（仅作为示例）  
    for (int i = 0; i < 3; i++) {  
        array[i] = i * 10; // 假设我们填充了0, 10, 20  
        size++;  
    }  
  
    // 打印原始数组  
    printf("Original array:\n");  
    printArray(array, size);  
  
    // 询问用户想要插入的索引位置  
    int index;  
    printf("Enter the index to insert the new element (0-based): ");  
    scanf("%d", &index);  
  
    // 检查索引是否有效  
    if (index < 0 || index > size) {  
        printf("Invalid index for insertion. Insertion will be cancelled.\n");  
        freeArray(array); // 释放已分配的内存  
        return EXIT_FAILURE; // 或其他适当的错误处理  
    }  
  
    // 询问用户想要插入的新元素值  
    int newElement;  
    printf("Enter the new element to insert: ");  
    scanf("%d", &newElement);  
  
    // 在用户指定的索引处插入新元素  
    insertElement(&array, &size, &capacity, newElement, index);  
  
    // 打印插入后的数组  
    printf("Array after insertion:\n");  
    printArray(array, size);  
  
    // 释放动态数组占用的内存  
    freeArray(array);  
  
    return 0;  
}  
  
// 插入元素的函数  
void insertElement(int **array, int *size, int *capacity, int newElement, int index) {  
    // 如果数组已满，则增加容量  
    if (*size == *capacity) {  
        *capacity *= 2; // 容量加倍  
        *array = (int *)realloc(*array, *capacity * sizeof(int));  
        if (!*array) {  
            fprintf(stderr, "Memory reallocation failed\n");  
            exit(EXIT_FAILURE);  
        }  
    }  
  
    // 将从index开始到数组末尾的元素向后移动一位  
    for (int i = *size; i > index; i--) {  
        (*array)[i] = (*array)[i - 1];  
    }  
  
    // 在指定位置插入新元素  
    (*array)[index] = newElement;  
  
    // 更新数组大小  
    (*size)++;  
}  
  
// 打印数组的函数  
void printArray(int *array, int size) {  
    for (int i = 0; i < size; i++) {  
        printf("%d ", array[i]);  
    }  
    printf("\n");  
}  
  
// 释放动态数组占用的内存  
void freeArray(int *array) {  
    free(array);  
}