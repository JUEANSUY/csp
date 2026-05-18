# 009-lc56-merge-intervals

## 题目信息

- 来源：LeetCode 56 Merge Intervals
- 链接：https://leetcode.cn/problems/merge-intervals/
- 类型：排序 / 区间
- 难度：中等
- 完成日期：2026-05-18
- 状态：LeetCode 已通过

## 题意

给定若干区间，把所有有重叠的区间合并，返回合并后的区间列表。

例如：

```text
[1,3], [2,6], [8,10], [15,18]
```

其中 `[1,3]` 和 `[2,6]` 重叠，合并后得到：

```text
[1,6], [8,10], [15,18]
```

## 我的思路

先按区间左端点排序。

排序后，从左到右遍历区间，只需要把当前区间和结果数组里的最后一个区间比较：

- 如果当前区间左端点 `<=` 最后一个结果区间右端点，说明重叠。
- 重叠时，只需要把最后一个结果区间的右端点更新为较大值。
- 如果不重叠，就把当前区间作为新区间加入结果。

核心判断：

```c
if (intervals[i][0] <= result[count - 1][1])
```

更新右端点：

```c
if (intervals[i][1] > result[count - 1][1]) {
    result[count - 1][1] = intervals[i][1];
}
```

## qsort 记录

本地版区间数组是：

```c
int intervals[MAXN][2]
```

每个区间是两个连续的 `int`，所以比较函数可以写成：

```c
int cmpInterval(const void *a, const void *b) {
    const int *x = (const int *)a;
    const int *y = (const int *)b;
    return x[0] - y[0];
}
```

排序调用：

```c
qsort(intervals, intervalsSize, sizeof(intervals[0]), cmpInterval);
```

## LeetCode C 签名

LeetCode 的 C 版本使用：

```c
int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColumnSizes)
```

和本地版不同：

- 本地 `intervals[MAXN][2]` 是二维数组。
- LeetCode `intervals` 是 `int**`。
- LeetCode 返回值要用 `malloc` 构造 `int** result`。
- 还要设置 `*returnSize` 和 `*returnColumnSizes`。

LeetCode 版 `qsort` 比较函数要写成：

```c
int cmpInterval(const void *a, const void *b) {
    int *x = *(int **)a;
    int *y = *(int **)b;
    return x[0] - y[0];
}
```

如果在 `merge` 里调用 `cmpInterval`，`cmpInterval` 要写在 `merge` 前面，或者先写函数声明。

## 关键边界

- 没有重叠的区间。
- 多个区间连续重叠。
- 一个区间完全包含另一个区间。
- 区间刚好首尾相接，比如 `[1,4]` 和 `[4,5]`，也要合并。
- 输入区间原本是乱序的。
- 只有一个区间。

## 错误记录

- 一开始在 `cmpInterval` 里试图手动交换 `a` 和 `b`，这是错误的。比较函数只返回比较结果，交换由 `qsort` 完成。
- 曾写过 `result = intervals[0]`，这不能复制二维数组内容，应该手动赋值 `result[0][0]` 和 `result[0][1]`。
- 重叠条件曾写成 `>`，导致 `[1,4]` 和 `[4,5]` 没有合并。正确应使用 `<=` 或 `>=` 的包含边界判断。
- 合并时曾直接覆盖右端点，导致 `[1,10]` 被 `[2,3]` 缩小。正确做法是取更大的右端点。
- LeetCode 提交时遇到本地 `MAXN` 未定义和 `cmpInterval` 未声明问题，原因是本地函数签名和 LeetCode C 模板不同。

## 复杂度

- 时间复杂度：O(n log n)，主要来自排序。
- 空间复杂度：O(n)，用于结果数组。

## 本地输入格式

```text
n
start1 end1
start2 end2
...
```

样例：

```text
4
1 3
2 6
8 10
15 18
```

输出：

```text
1 6
8 10
15 18
```

## 测试记录

本地用 `gcc -Wall -Wextra -std=c11` 编译通过。

测试过的情况：

- LeetCode 样例：通过。
- `[1,4]` 和 `[4,5]` 首尾相接：通过。
- 区间包含：通过。
- 多个区间连续重叠：通过。
- 乱序输入：通过。

## 复盘

区间合并题先排序，再维护结果数组最后一个区间。判断重叠时要包含边界，更新右端点时要取最大值，不能直接覆盖。
