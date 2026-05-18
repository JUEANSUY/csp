# LeetCode CSP 备考刷题清单

这个清单按 CSP 备考优先级整理，建议用 C 语言完成。每道题做完后，可以在 `problems/` 目录里建对应题目文件夹，并在这里更新状态。

## 使用建议

每道题尽量完成三步：

1. 在 LeetCode 上用 C 语言通过。
2. 在本地写成 CSP 风格：自己写 `main()`、`scanf`、`printf`。
3. 在 `notes.md` 里记录思路、错因、复杂度。

状态可以写：

- `未开始`
- `已通过`
- `待复盘`
- `需重做`

## 第一阶段：基础必刷

目标：练熟输入输出、数组、二分、前缀和、栈、排序和简单模拟。

| 优先级 | 题号 | 题目 | 类型 | 状态 | 本地记录 |
|---|---:|---|---|---|---|
| 高 | 704 | [Binary Search](https://leetcode.cn/problems/binary-search/) | 二分 | LeetCode 已通过 | `problems/001-lc704-binary-search/` |
| 高 | 35 | [Search Insert Position](https://leetcode.cn/problems/search-insert-position/) | 二分 | LeetCode 已通过 | `problems/002-lc35-search-insert-position/` |
| 高 | 27 | [Remove Element](https://leetcode.cn/problems/remove-element/) | 数组/双指针 | LeetCode 已通过 | `problems/003-lc27-remove-element/` |
| 高 | 283 | [Move Zeroes](https://leetcode.cn/problems/move-zeroes/) | 数组/双指针 | LeetCode 已通过 | `problems/004-lc283-move-zeroes/` |
| 高 | 303 | [Range Sum Query - Immutable](https://leetcode.cn/problems/range-sum-query-immutable/) | 前缀和 | LeetCode 已通过 | `problems/005-lc303-range-sum-query-immutable/` |
| 中 | 977 | [Squares of a Sorted Array](https://leetcode.cn/problems/squares-of-a-sorted-array/) | 数组/双指针 | LeetCode 已通过 | `problems/006-lc977-squares-of-a-sorted-array/` |
| 中 | 20 | [Valid Parentheses](https://leetcode.cn/problems/valid-parentheses/) | 栈 | LeetCode 已通过 | `problems/007-lc20-valid-parentheses/` |
| 中 | 54 | [Spiral Matrix](https://leetcode.cn/problems/spiral-matrix/) | 矩阵/模拟 | LeetCode 已通过 | `problems/008-lc54-spiral-matrix/` |
| 中 | 56 | [Merge Intervals](https://leetcode.cn/problems/merge-intervals/) | 排序/区间 | LeetCode 已通过 | `problems/009-lc56-merge-intervals/` |
| 中 | 560 | [Subarray Sum Equals K](https://leetcode.cn/problems/subarray-sum-equals-k/) | 前缀和/哈希 | LeetCode 已通过 | `problems/010-lc560-subarray-sum-equals-k/` |

## 第二阶段：CSP 常见题型

目标：练模拟、字符串、贪心和简单动态规划，主要面向 CSP 前 3 题。

| 优先级 | 题号 | 题目 | 类型 | 状态 | 本地记录 |
|---|---:|---|---|---|---|
| 高 | 121 | [Best Time to Buy and Sell Stock](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/) | 贪心/数组 | LeetCode 已通过 | `problems/011-lc121-best-time-to-buy-and-sell-stock/` |
| 高 | 70 | [Climbing Stairs](https://leetcode.cn/problems/climbing-stairs/) | 动态规划 | 练习中 | `problems/012-lc70-climbing-stairs/` |
| 高 | 53 | [Maximum Subarray](https://leetcode.cn/problems/maximum-subarray/) | 动态规划 | 未开始 |  |
| 中 | 14 | [Longest Common Prefix](https://leetcode.cn/problems/longest-common-prefix/) | 字符串 | 未开始 |  |
| 中 | 28 | [Find the Index of the First Occurrence in a String](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/) | 字符串 | 未开始 |  |
| 中 | 415 | [Add Strings](https://leetcode.cn/problems/add-strings/) | 字符串模拟 | 未开始 |  |
| 中 | 455 | [Assign Cookies](https://leetcode.cn/problems/assign-cookies/) | 贪心 | 未开始 |  |
| 中 | 746 | [Min Cost Climbing Stairs](https://leetcode.cn/problems/min-cost-climbing-stairs/) | 动态规划 | 未开始 |  |
| 低 | 48 | [Rotate Image](https://leetcode.cn/problems/rotate-image/) | 矩阵模拟 | 未开始 |  |
| 低 | 55 | [Jump Game](https://leetcode.cn/problems/jump-game/) | 贪心 | 未开始 |  |
| 低 | 198 | [House Robber](https://leetcode.cn/problems/house-robber/) | 动态规划 | 未开始 |  |

## 第三阶段：冲高分题型

目标：练搜索、图、并查集、堆、单调栈、背包和更完整的动态规划，主要面向 CSP 第 4、5 题。

| 优先级 | 题号 | 题目 | 类型 | 状态 | 本地记录 |
|---|---:|---|---|---|---|
| 高 | 200 | [Number of Islands](https://leetcode.cn/problems/number-of-islands/) | DFS/BFS | 未开始 |  |
| 高 | 695 | [Max Area of Island](https://leetcode.cn/problems/max-area-of-island/) | DFS/BFS | 未开始 |  |
| 高 | 994 | [Rotting Oranges](https://leetcode.cn/problems/rotting-oranges/) | BFS | 未开始 |  |
| 中 | 547 | [Number of Provinces](https://leetcode.cn/problems/number-of-provinces/) | 并查集/DFS | 未开始 |  |
| 中 | 207 | [Course Schedule](https://leetcode.cn/problems/course-schedule/) | 拓扑排序 | 未开始 |  |
| 中 | 215 | [Kth Largest Element in an Array](https://leetcode.cn/problems/kth-largest-element-in-an-array/) | 堆/快速选择 | 未开始 |  |
| 中 | 739 | [Daily Temperatures](https://leetcode.cn/problems/daily-temperatures/) | 单调栈 | 未开始 |  |
| 中 | 416 | [Partition Equal Subset Sum](https://leetcode.cn/problems/partition-equal-subset-sum/) | 背包 DP | 未开始 |  |
| 中 | 322 | [Coin Change](https://leetcode.cn/problems/coin-change/) | 动态规划 | 未开始 |  |
| 中 | 300 | [Longest Increasing Subsequence](https://leetcode.cn/problems/longest-increasing-subsequence/) | 动态规划 | 未开始 |  |
| 低 | 84 | [Largest Rectangle in Histogram](https://leetcode.cn/problems/largest-rectangle-in-histogram/) | 单调栈 | 未开始 |  |
| 低 | 1143 | [Longest Common Subsequence](https://leetcode.cn/problems/longest-common-subsequence/) | 动态规划 | 未开始 |  |
| 低 | 307 | [Range Sum Query - Mutable](https://leetcode.cn/problems/range-sum-query-mutable/) | 树状数组/线段树 | 未开始 |  |

## 推荐刷题顺序

先按这个顺序刷前 10 题：

1. 704 Binary Search
2. 35 Search Insert Position
3. 27 Remove Element
4. 283 Move Zeroes
5. 303 Range Sum Query - Immutable
6. 20 Valid Parentheses
7. 121 Best Time to Buy and Sell Stock
8. 70 Climbing Stairs
9. 53 Maximum Subarray
10. 415 Add Strings

## 本地记录命名建议

例如做第 704 题，可以建：

```text
csp-practice/problems/001-lc704-binary-search/
  main.c
  notes.md
  input.txt
```

`notes.md` 里重点记录：

- 这题属于什么类型。
- 为什么可以用这个算法。
- 最容易错的边界是什么。
- 时间复杂度和空间复杂度是多少。
