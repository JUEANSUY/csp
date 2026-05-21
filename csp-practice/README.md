# CSP C Practice

这个目录用来记录 CSP / LeetCode 备考时写过的 C 语言代码、思路和错误。

LeetCode 备考题单见：[leetcode-practice-list.md](./leetcode-practice-list.md)

## 使用方式

每做一道题，就在 `problems/` 下新建一个文件夹：

```text
problems/
  001-lc704-binary-search/
    main.c
    notes.md
    input.txt
```

建议每题至少记录三样东西：

- `main.c`：本地可编译运行的代码。
- `notes.md`：题目思路、错因、复杂度、复盘。
- `input.txt`：自己手写的测试数据。

## 编译运行

推荐使用根目录脚本：

```powershell
.\scripts\run.ps1 012-lc70-climbing-stairs
```

脚本会自动编译对应题目的 `main.c`，并把 `input.txt` 作为输入运行。

也可以手动运行：

```powershell
gcc -Wall -Wextra -std=c11 .\csp-practice\problems\000-sample-sum\main.c -o .\csp-practice\problems\000-sample-sum\main.exe
Get-Content .\csp-practice\problems\000-sample-sum\input.txt | .\csp-practice\problems\000-sample-sum\main.exe
```

## 刷题记录

| 编号 | 题目 | 类型 | 状态 | 错因/备注 |
|---|---|---|---|---|
| 000 | sample-sum | 输入输出 | 已完成 | 用来测试编译运行流程 |
| 001 | lc704-binary-search | 二分查找 | LeetCode 已通过 | 闭区间二分 |
| 002 | lc35-search-insert-position | 二分查找 | LeetCode 已通过 | 找不到时返回插入位置 |
| 003 | lc27-remove-element | 数组/双指针 | LeetCode 已通过 | 保序双指针 |
| 004 | lc283-move-zeroes | 数组/双指针 | LeetCode 已通过 | 两趟保序写法 |
| 005 | lc303-range-sum-query-immutable | 前缀和 | LeetCode 已通过 | `prefix[right + 1] - prefix[left]` |
| 006 | lc977-squares-of-a-sorted-array | 数组/双指针 | LeetCode 已通过 | 双指针从后往前填结果 |
| 007 | lc20-valid-parentheses | 栈 | LeetCode 已通过 | 栈匹配最近左括号 |
| 008 | lc54-spiral-matrix | 矩阵/模拟 | LeetCode 已通过 | 四边界螺旋遍历 |
| 009 | lc56-merge-intervals | 排序/区间 | LeetCode 已通过 | 排序后合并重叠区间 |
| 010 | lc560-subarray-sum-equals-k | 前缀和/哈希 | LeetCode 已通过 | 前缀和 + 开放寻址哈希 |
| 011 | lc121-best-time-to-buy-and-sell-stock | 数组/贪心 | LeetCode 已通过 | 维护历史最低价 |
| 012 | lc70-climbing-stairs | 动态规划 | LeetCode 已通过 | 滚动变量优化 |
| 013 | lc53-maximum-subarray | 动态规划 | LeetCode 已通过 | Kadane：维护以当前位置结尾的最大连续和 |
| 014 | lc14-longest-common-prefix | 字符串 | LeetCode 已通过 | 截断 `strs[0]` 得到公共前缀 |
| 015 | lc28-find-the-index-of-the-first-occurrence-in-a-string | 字符串 | LeetCode 已通过 | 暴力字符串匹配，失败后继续尝试下一个起点 |
| 016 | lc415-add-strings | 字符串模拟 | LeetCode 已通过 | 从后往前竖式加法，处理进位和反转 |
| 017 | lc455-assign-cookies | 贪心/排序 | LeetCode 已通过 | 排序后用双指针贪心匹配 |
| 018 | lc746-min-cost-climbing-stairs | 动态规划 | LeetCode 已通过 | `dp[i]` 表示到达位置 i 前的最小花费 |
| 019 | lc48-rotate-image | 矩阵模拟 | LeetCode 已通过 | 转置后每行反转 |
| 020 | lc55-jump-game | 贪心 | LeetCode 已通过 | 维护当前最远可达位置 |
| 021 | lc198-house-robber | 动态规划 | LeetCode 已通过 | `dp[i]` 在偷/不偷当前房子中取最大值 |
| 022 | lc200-number-of-islands | DFS/BFS | LeetCode 已通过 | DFS 原地标记连通陆地 |
| 023 | lc695-max-area-of-island | DFS/BFS | LeetCode 已通过 | DFS 返回当前岛屿面积 |
| 024 | lc994-rotting-oranges | BFS | LeetCode 已通过 | 多源 BFS 按分钟扩散 |
| 025 | lc547-number-of-provinces | DFS/并查集 | 练习中 | 图的连通块数量 |
| 026 | lc207-course-schedule | 拓扑排序/图 | LeetCode 已通过 | 入度 BFS 判断有向图是否有环 |
| 027 | lc215-kth-largest-element-in-an-array | 快速选择 | LeetCode 已通过 | 三路 Quickselect 处理重复元素 |
| 028 | lc739-daily-temperatures | 单调栈 | 练习中 | 栈里存等待更高温度的下标 |
| 029 | lc416-partition-equal-subset-sum | 0/1 背包 DP | LeetCode 已通过 | 判断能否凑出总和的一半 |
| 030 | lc322-coin-change | 完全背包 DP | LeetCode 已通过 | 求凑出金额的最少硬币数 |
| 031 | lc300-longest-increasing-subsequence | 动态规划 | LeetCode 已通过 | 求最长严格递增子序列长度 |
| 032 | lc84-largest-rectangle-in-histogram | 单调栈 | 练习中 | 求柱状图中的最大矩形面积 |

## 常见复盘点

- 输入是否读完整。
- 数组大小是否足够。
- `int` 是否会溢出，需要不要用 `long long`。
- 边界情况是否考虑，比如 `n = 0`、`n = 1`、最大数据。
- 时间复杂度是否能通过题目数据范围。
