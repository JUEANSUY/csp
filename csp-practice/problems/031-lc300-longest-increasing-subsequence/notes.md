# 031-lc300-longest-increasing-subsequence

## 题目信息

- 来源：LeetCode 300 Longest Increasing Subsequence
- 链接：https://leetcode.cn/problems/longest-increasing-subsequence/
- 类型：动态规划
- 难度：中等
- 状态：LeetCode 已通过

## 题意

给一个整数数组，求最长严格递增子序列的长度。

子序列不要求连续，但要保持原来的相对顺序。

## 思路提示

建议先写 O(n^2) 动态规划版本。

可以先想：

- `dp[i]` 表示以 `nums[i]` 结尾的最长递增子序列长度。
- 每个数字自己单独成一个子序列，所以 `dp[i]` 初始是 1。
- 对于每个 `i`，枚举它前面的 `j`。
- 如果 `nums[j] < nums[i]`，说明 `nums[i]` 可以接在 `nums[j]` 后面。
- 这时可以尝试更新：`dp[i] = max(dp[i], dp[j] + 1)`。
- 最后答案不是固定的 `dp[n - 1]`，而是所有 `dp[i]` 里的最大值。

## 关键边界

- 数组只有一个元素。
- 完全递增。
- 完全递减。
- 有重复数字，注意题目要求严格递增，所以相等不能接上。

## 错误记录

- `int dp[MAXN] = {1};` 只会让 `dp[0] = 1`，后面的元素会被初始化成 0；这题每个 `dp[i]` 都应该手动初始化成 1。
- 答案不是固定的 `dp[n - 1]`，而是所有 `dp[i]` 中的最大值。

## 复杂度

- 时间复杂度：O(n^2)。
- 空间复杂度：O(n)。

## 本地输入格式

```text
n
nums[0] nums[1] ... nums[n-1]
```

样例：

```text
8
10 9 2 5 3 7 101 18
```

正确输出应该是：

```text
4
```
