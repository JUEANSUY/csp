# 005-lc303-range-sum-query-immutable

## 题目信息

- 来源：LeetCode 303 Range Sum Query - Immutable
- 链接：https://leetcode.cn/problems/range-sum-query-immutable/
- 类型：前缀和
- 难度：简单
- 状态：练习中

## 题意

用自己的话写一遍题意：

-

## 我的思路

先回答这几个问题：

- 如果每次查询都用循环求和，时间复杂度是多少？
- 能不能提前把某些和算好？
- `prefix[i]` 如果表示前 `i` 个数的和，那么 `prefix[0]` 应该是多少？
- 区间 `[left, right]` 的和应该用哪两个前缀和相减？
- 为什么建议让前缀和数组比原数组多一位？

## 关键边界

- 查询单个元素。
- 查询从下标 `0` 开始的区间。
- 查询到最后一个元素。
- 多次查询同一个数组。
- 数组中有负数。

## 错误记录

-

## 复杂度

- 预处理时间复杂度：
- 单次查询时间复杂度：
- 空间复杂度：

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

正确输出应该是：

```text
1
-1
-3
```
