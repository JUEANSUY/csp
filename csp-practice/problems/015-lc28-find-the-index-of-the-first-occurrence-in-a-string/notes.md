# 015-lc28-find-the-index-of-the-first-occurrence-in-a-string

## 题目信息

- 来源：LeetCode 28 Find the Index of the First Occurrence in a String
- 链接：https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/
- 类型：字符串匹配
- 难度：简单
- 状态：LeetCode 已通过

## 题意

给两个字符串 `haystack` 和 `needle`，判断 `needle` 第一次出现在 `haystack` 的哪个位置。

如果出现，返回第一次出现的起始下标；如果没有出现，返回 `-1`。

## 我的思路

先用暴力匹配：

1. 枚举 `haystack` 中每一个可能的起点 `i`。
2. 从这个起点开始，用 `needle[j]` 和 `haystack[i + j]` 逐个比较。
3. 如果所有字符都匹配成功，返回 `i`。
4. 如果当前起点匹配失败，继续尝试下一个起点。
5. 所有起点都试完还没找到，返回 `-1`。

## 关键边界

- `needle` 比 `haystack` 长。
- 两个字符串完全相等。
- `needle` 出现在开头。
- `needle` 出现在中间或结尾。
- 前面有部分匹配失败，但后面还有真正答案，例如 `mississippi` 和 `issip`。
- 找不到匹配。

## 错误记录

- 内层匹配失败时，不能直接 `return -1`，否则会漏掉后面的起点。
- 正确做法是把当前起点标记为失败，然后 `break` 内层循环，继续外层循环。

## 复杂度

- 时间复杂度：暴力匹配最坏是 `O(n * m)`。
- 空间复杂度：`O(1)`。

## 进阶

更优解法是 KMP，时间复杂度可以做到 `O(n + m)`。

KMP 的核心是先给 `needle` 构造 `next` / `lps` 数组，让匹配失败时不用把 `haystack` 指针退回去。

这题当前先掌握暴力匹配即可，KMP 可以后面单独学习。

## 本地输入格式

```text
haystack
needle
```

样例：

```text
sadbutsad
sad
```

正确输出应该是：

```text
0
```
