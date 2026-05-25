# 033-lc1143-longest-common-subsequence

## 题目信息

- 来源：LeetCode 1143 Longest Common Subsequence
- 链接：https://leetcode.cn/problems/longest-common-subsequence/
- 类型：动态规划
- 难度：中等
- 状态：LeetCode 已通过

## 题意

给两个字符串 `text1` 和 `text2`，求它们的最长公共子序列长度。

子序列不要求连续，但要保持原来的相对顺序。

## 思路提示

这题建议先写二维 DP。

可以先想：

- `dp[i][j]` 表示 `text1` 的前 `i` 个字符和 `text2` 的前 `j` 个字符的最长公共子序列长度。
- 注意这里的 `i`、`j` 是“前几个字符”，所以访问真实字符时通常是 `text1[i - 1]` 和 `text2[j - 1]`。
- 如果 `text1[i - 1] == text2[j - 1]`，说明这两个字符可以一起加入公共子序列。
- 如果不相等，就只能在“少看 text1 一个字符”和“少看 text2 一个字符”里取更大值。

## 关键边界

- 其中一个字符串为空。
- 两个字符串完全相同。
- 两个字符串完全没有相同字符。
- 有重复字符时，要注意子序列顺序。

## 错误记录

- `dp[i][j]` 表示“前 i 个字符”和“前 j 个字符”，所以访问真实字符时要用 `text1[i - 1]`、`text2[j - 1]`。
- `dp[0][j]` 和 `dp[i][0]` 表示其中一个字符串为空，应该为 0。
- `int dp[MAXN][MAXN]` 这种二维大数组如果放在函数内部，本地 Windows 环境可能栈溢出；可以改成 `static int dp[MAXN][MAXN]` 或全局数组。

## 复杂度

- 时间复杂度：O(m * n)，其中 `m` 和 `n` 是两个字符串长度。
- 空间复杂度：O(m * n)。

## 本地输入格式

```text
text1
text2
```

样例：

```text
abcde
ace
```

正确输出应该是：

```text
3
```
