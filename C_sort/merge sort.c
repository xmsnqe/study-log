#include <stdio.h>

// 合并两个有序子数组(归并排序)
/*
归并排序的基本思想是：先递归地将数组拆分成两半，然后再合并两个有序数组。
时间复杂度：O(nlogn)
空间复杂度：O(n)
*/
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;  // 左子数组长度
    int n2 = right - mid;     // 右子数组长度

    // 创建临时数组
    int L[n1], R[n2];

    // 复制数据到临时数组
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // 合并临时数组到原数组
    i = 0;    // 左子数组起始索引
    j = 0;    // 右子数组起始索引
    k = left; // 合并后数组起始索引
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 处理剩余元素
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 归并排序主函数
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // 计算中间位置（避免溢出）
        int mid = left + (right - left) / 2;

        // 递归排序左右两部分
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // 合并已排序部分
        merge(arr, left, mid, right);
    }
}

// 输出数组
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7, 9, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("排序前的数组: ");
    printArray(arr, size);

    // 调用归并排序（排序整个数组，从索引0到size-1）
    mergeSort(arr, 0, size - 1);

    printf("排序后的数组: ");
    printArray(arr, size);

    return 0;
}
