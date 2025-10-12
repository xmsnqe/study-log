#include <stdio.h>

/*时间复杂度：
最佳情况：O (n log n)（每次分区都能将数组均匀分为两部分）
最坏情况：O (n²)（数组已排序或逆序，每次分区只能减少一个元素）
平均情况：O (n log n)
空间复杂度：O (log n)（递归调用栈的深度）
稳定性：不稳定排序（相等元素的相对位置可能改变）*/

// 使用指针交换两个元素的值
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 分区操作：选择最后一个元素作为基准，将小于基准的放左边，大于基准的放右边
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // 选择基准值
    int i = (low - 1);      // 小于基准区域的边界索引

    for (int j = low; j <= high - 1; j++) {
        // 如果当前元素小于或等于基准值，扩展小于区域并交换
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // 将基准值放到正确的位置（小于区域和大于区域之间）
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);  // 返回基准值的索引
}

// 快速排序函数
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // 获得基准值的位置，将数组分为两部分
        int pi = partition(arr, low, high);

        // 递归排序基准值左边的子数组
        quickSort(arr, low, pi - 1);
        // 递归排序基准值右边的子数组
        quickSort(arr, pi + 1, high);
    }
}

// 输出数组
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("排序前的数组: ");
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1);
    
    printf("排序后的数组: ");
    printArray(arr, n);
    
    return 0;
}
