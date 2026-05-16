# 005-lc303-range-sum-query-immutable

## 题目信息

- 来源：LeetCode 303 Range Sum Query - Immutable
- 链接：https://leetcode.cn/problems/range-sum-query-immutable/
- 类型：前缀和
- 难度：简单
- 完成日期：2026-05-16
- 状态：LeetCode 已通过

## 题意

给定一个整数数组 `nums`，数组不会被修改。需要多次查询区间 `[left, right]` 的元素和，也就是：

```text
nums[left] + nums[left + 1] + ... + nums[right]
```

要求每次查询尽量快。

## 我的思路

使用前缀和。

让 `prefix[i]` 表示原数组前 `i` 个数的和：

```text
prefix[0] = 0
prefix[1] = nums[0]
prefix[2] = nums[0] + nums[1]
...
prefix[i + 1] = prefix[i] + nums[i]
```

这样区间 `[left, right]` 的和可以用两个前缀和相减：

```text
sumRange(left, right) = prefix[right + 1] - prefix[left]
```

前缀和数组比原数组多一位，可以统一处理从下标 `0` 开始的区间，不需要额外判断 `left == 0`。

## C 语言内存写法

LeetCode 的 C 模板使用 `NumArray*` 指针对象，所以最终使用动态内存版本：

```c
typedef struct {
    int *prefix;
} NumArray;
```

创建时：

```c
NumArray* obj = malloc(sizeof(NumArray));
obj->prefix = malloc(sizeof(int) * (numsSize + 1));
```

释放时：

```c
free(obj->prefix);
free(obj);
```

核心原则：

```text
malloc 得到的地址，最后要用 free 释放。
```

## 另一种解法

可以把原数组原地改成前缀和，这样额外空间更少：

- 初始化时直接修改 `nums[i] += nums[i - 1]`。
- 查询 `[left, right]` 时，如果 `left == 0`，返回 `nums[right]`。
- 否则返回 `nums[right] - nums[left - 1]`。

这个方法额外空间是 O(1)，但是会修改传入的数组。备考 CSP 时，默认更推荐单独开一个前缀和数组，逻辑更清楚，也不容易影响原数据。

## 关键边界

- 查询单个元素。
- 查询从下标 `0` 开始的区间。
- 查询到最后一个元素。
- 查询整个数组。
- 数组中有负数。
- 多次查询同一个数组。

## 错误记录

- 曾经把固定数组 `int prefix[MAXN]` 和动态分配 `malloc` 混在一起，导致 `obj->prefix = malloc(...)` 编译失败。
- LeetCode 提交时出现过数组越界，原因是前缀和需要 `numsSize + 1` 个位置，而不是 `numsSize` 个位置。
- 使用 `malloc/free` 时需要包含 `<stdlib.h>`。

## 复杂度

- 预处理时间复杂度：O(n)
- 单次查询时间复杂度：O(1)
- 空间复杂度：O(n)

## 本地输入格式

```text
n
nums[0] nums[1] ... nums[n-1]
q
left1 right1
left2 right2
...
```

样例：

```text
6
-2 0 3 -5 2 -1
3
0 2
2 5
0 5
```

输出：

```text
1
-1
-3
```

## 测试记录

本地用 `gcc -Wall -Wextra -std=c11` 编译通过。

测试过的情况：

- LeetCode 样例：通过。
- 查询单个元素：通过。
- 查询整个数组：通过。
- 查询中间区间：通过。
- 单元素数组：通过。
- 数组中有负数：通过。

## 复盘

这题的核心是 `prefix[right + 1] - prefix[left]`。前缀和多开一位可以减少边界判断，是以后做区间和、二维前缀和、差分数组时都很常用的写法。
