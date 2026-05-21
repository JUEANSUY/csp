# 029-lc416-partition-equal-subset-sum

## 题目信息

- 来源：LeetCode 416 Partition Equal Subset Sum
- 链接：https://leetcode.cn/problems/partition-equal-subset-sum/
- 类型：0/1 背包 DP
- 难度：中等
- 状态：练习中

## 题意

给一个只包含正整数的数组，判断能不能把它分成两个子集，使两个子集的元素和相等。

## 思路提示

如果数组总和是 `sum`：

- 如果 `sum` 是奇数，不可能平分，直接返回 `false`。
- 如果 `sum` 是偶数，问题就变成：能不能从数组里选出一些数，让它们的和等于 `sum / 2`。

这就是 0/1 背包问题。

可以先想：

- 每个数只能选一次。
- 背包容量是 `target = sum / 2`。
- `dp[j]` 可以表示是否能凑出和 `j`。
- 遍历每个数时，为什么 `j` 要从大到小更新？

## 关键边界

- 总和是奇数。
- 一个数就超过 `sum / 2`。
- 有多个重复数字。
- 刚好可以凑出 `sum / 2`。
- 完全凑不出 `sum / 2`。

## 错误记录

-

## 复杂度

- 时间复杂度：
- 空间复杂度：

## 本地输入格式

```text
n
nums[0] nums[1] ... nums[n-1]
```

样例：

```text
4
1 5 11 5
```

正确输出应该是：

```text
true
```
