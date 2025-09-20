#include <stdio.h>
int main(){
    /*
    选择排序
    时间复杂度：O(n^2) 2 * t(for())
    空间复杂度：O(1)
    */
    
    int arr1[] = {4,5,7,2,54,65,456,345,234,2};
    int len = sizeof(arr1) / sizeof(arr1[0]);
    int term = 0;
    for(int i = 0; i < len-1; i++){
        int min = i;
        for(int j = i+1; j < len; j++){
            if(arr1[j] < arr1[min]){
                min = j;
            }
        }
        if(min != i){
            term = arr1[i];
            arr1[i] = arr1[min];
            arr1[min] = term;
        }
    }
    printf("排序后的数组为：");
    for(int i = 0; i < len; i++){
        printf("%d ", arr1[i]);
    }
    return 0;
}