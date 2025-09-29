#include <stdio.h>

int main(){
    /*
    插入排序
    时间复杂度：O(n^2)
    空间复杂度：O(1)
    */
    int arr1[] = {4,5,7,2,54,65,456,345,234,2};
    int len = sizeof(arr1) / sizeof(arr1[0]);
    int term = 0;
    for(int i = 1; i < len; i++){
        term = arr1[i];
        int j = i-1;
        while(j >= 0 && arr1[j] < term){
            arr1[j+1] = arr1[j];
            j--;
        }
        arr1[j+1] = term;
    }
    printf("排序后的数组为：");
    for(int i = 0; i < len; i++){
        printf("%d ", arr1[i]);
    }
    return 0;
}