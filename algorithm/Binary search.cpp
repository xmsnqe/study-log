/* 二分查找（双闭区间） */
int binarySearch(vector<int> &nums, int target) {
    // 初始化双闭区间 [0, n-1] ，即 i, j 分别指向数组首元素、尾元素
    int i = 0, j = nums.size() - 1;
    
    // 循环，当搜索区间为空时跳出（当 i > j 时为空）
    while (i <= j) {
        int m = i + (j - i) / 2; // 计算中点索引 m // 防止溢出，等价于 (i + j) / 2
        if (nums[m] < target)    // 此情况说明 target 在区间 [m+1, j] 中
            i = m + 1;
        else if (nums[m] > target) // 此情况说明 target 在区间 [i, m-1] 中
            j = m - 1;
        else // 找到目标元素，返回其索引
            return m;
    }
    // 未找到目标元素，返回 -1
    return -1;
}
/*
1.二分查找仅适用于有序数据

2.二分查找仅适用于数组。二分查找需要跳跃式（非连续地）访问元素，
而在链表中执行跳跃式访问的效率较低，因此不适合应用在链表或基于链表实现的数据结构.

3.小数据量下，线性查找性能更佳

4.二分查找的平均时间复杂度为 O(log n)，最坏情况下时间复杂度为 O(n)

5.二分查找的空间复杂度为 O(1)，不占用额外空间

6.二分查找的适用场景：

- 对于有序数组，查找元素，查找范围为 [0, n-1]
- 对于有序链表，查找元素，查找范围为 [head, tail] // 注意：链表不能随机访问，只能顺序访问 （一般不用二分查找）
- 对于有序矩阵，查找元素，查找范围为 [0, m-1][0, n-1]



/* 二分查找插入点（无重复元素） */
int binarySearchInsertionSimple(vector<int> &nums, int target) {
    int i = 0, j = nums.size() - 1; // 初始化双闭区间 [0, n-1]
    while (i <= j) {
        int m = i + (j - i) / 2; // 计算中点索引 m
        if (nums[m] < target) {
            i = m + 1; // target 在区间 [m+1, j] 中
        } else if (nums[m] > target) {
            j = m - 1; // target 在区间 [i, m-1] 中
        } else {
            return m; // 找到 target ，返回插入点 m
        }
    }
    // 未找到 target ，返回插入点 i
    return i;
}

/* 二分查找插入点（有重复元素） */
int binarySearchInsertion(vector<int> &nums, int target) {
    int i = 0, j = nums.size() - 1; // 初始化双闭区间 [0, n-1]
    while (i <= j) {
        int m = i + (j - i) / 2; // 计算中点索引 m
        if (nums[m] < target) {
            i = m + 1; // target 在区间 [m+1, j] 中
        } else if (nums[m] > target) {
            j = m - 1; // target 在区间 [i, m-1] 中
        } else {
            j = m - 1; // 首个小于 target 的元素在区间 [i, m-1] 中
        }
    }
    // 未找到 target ，返回插入点 i
    return i;
}