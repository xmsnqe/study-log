#include <stdio.h>
#include <stdlib.h>

int main(){
    //冒泡排序
    int arr1[] = {4,5,7,2,54,65,456,345,234,2};
    //时间复杂度：O(n^2)
    //空间复杂度：O(1)
    int len = sizeof(arr1) / sizeof(arr1[0]);
        for(int i = 0; i < len; i++){
        scanf("%d", &arr1[i]);
    }
    int term = 0;
        for(int i = 0; i < len-1; i++){
            for(int j = 0; j < len - i -1;j++){
                if(arr1[j] < arr1[j+1]){
                    term = arr1[j];
                    arr1[j] = arr1[j+1];
                    arr1[j+1] = term;
                }

            }

        }
    printf("排序后的数组为：");
        for(int i = 0; i < len; i++){
            printf("%d ", arr1[i]);
        }

    return 0;
}