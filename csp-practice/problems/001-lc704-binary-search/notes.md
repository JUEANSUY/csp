# 001-lc704-binary-search

## 题目信息

- 来源：LeetCode 704 Binary Search
- 链接：https://leetcode.cn/problems/binary-search/
- 类型：二分查找
- 难度：简单
- 完成日期：2026-05-16
- 状态：LeetCode 已通过

## 题意

给定一个升序数组 `nums` 和一个目标值 `target`。如果 `target` 存在于数组中，返回它的下标；如果不存在，返回 `-1`。

## 我的思路

数组已经按升序排列，所以可以用二分查找。

这道题使用闭区间 `[left, right]`：

- 初始时 `left = 0`，`right = numsSize - 1`。
- 每次取中间位置 `mid = left + (right - left) / 2`。
- 如果 `nums[mid] == target`，说明找到了，返回 `mid`。
- 如果 `nums[mid] < target`，说明目标值只可能在右半边，让 `left = mid + 1`。
- 如果 `nums[mid] > target`，说明目标值只可能在左半边，让 `right = mid - 1`。
- 如果循环结束还没找到，返回 `-1`。

## 关键边界

- `n = 1` 且能找到：返回 `0`。
- `n = 1` 且找不到：返回 `-1`。
- `target` 在第一个位置：返回 `0`。
- `target` 在最后一个位置：返回 `numsSize - 1`。
- `target` 比所有数都小：返回 `-1`。
- `target` 比所有数都大：返回 `-1`。

## 错误记录

- 暂无。

## 复杂度

- 时间复杂度：O(log n)
- 空间复杂度：O(1)

## 本地输入格式

为了方便本地练 CSP 风格输入输出，`main.c` 使用下面的输入格式：

```text
n
nums[0] nums[1] ... nums[n-1]
target
```

样例：

```text
6
-1 0 3 5 9 12
9
```

输出：

```text
4
```

## 测试记录

本地用 `gcc -Wall -Wextra -std=c11` 编译通过。

测试过的情况：

- LeetCode 样例：通过。
- 找不到目标值：通过。
- 单元素数组：通过。
- 目标值在第一个位置：通过。
- 目标值在最后一个位置：通过。
- 目标值小于所有元素：通过。
- 目标值大于所有元素：通过。

## 复盘

这题最重要的是明确区间写法。我这次使用的是闭区间 `[left, right]`，所以循环条件是 `left <= right`。每次移动边界时必须跳过 `mid`，也就是 `left = mid + 1` 或 `right = mid - 1`，否则可能死循环。
