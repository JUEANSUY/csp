# 025-lc547-number-of-provinces

## 题目信息

- 来源：LeetCode 547 Number of Provinces
- 链接：https://leetcode.cn/problems/number-of-provinces/
- 类型：DFS / 并查集
- 难度：中等
- 状态：LeetCode 已通过

## 题意

有 `n` 个城市，`isConnected[i][j] == 1` 表示城市 `i` 和城市 `j` 直接相连。

如果城市之间直接或间接相连，它们就属于同一个省份。

求一共有多少个省份。

## 我的思路

这题可以看成“图的连通块数量”。

城市是点，`isConnected[i][j] == 1` 表示城市 `i` 和城市 `j` 之间有边。

准备一个 `visited` 数组：

```c
int visited[MAXN] = {0};
```

从每个城市开始扫描：

- 如果城市 `i` 已经访问过，说明它属于之前某个省份，跳过。
- 如果城市 `i` 没访问过，说明发现一个新省份，`count++`。
- 然后从 `i` 开始 DFS，把和它直接或间接相连的所有城市都标记为访问过。

DFS 里遍历所有城市 `next`：

```c
if (isConnected[city][next] == 1 && visited[next] == 0) {
    dfs(isConnected, next, n, visited);
}
```

## 关键理解

这题不是二维网格连通块，不能照搬 200 岛屿数量里“上下左右走格子”的思路。

547 里的矩阵表示的是城市关系：

```text
行/列下标 = 城市编号
矩阵里的 1 = 两个城市直接相连
```

所以 DFS 的参数应该是一个城市编号，而不是 `(row, col)` 格子坐标。

## 关键边界

- 所有城市互不相连，答案是 `n`。
- 所有城市都相连，答案是 `1`。
- 两个城市通过中间城市间接相连，也属于同一个省份。
- 矩阵对角线 `isConnected[i][i]` 一般为 `1`。

## 错误记录

- `visited` 数组要初始化，不能只写 `int visited[MAXN];`。
- 数组整体清零要写 `int visited[MAXN] = {0};`，不能写 `= 0`。
- 模仿 200 直接改矩阵的做法不适合这题，使用 `visited[city]` 更清楚。

## 复杂度

- 时间复杂度：`O(n^2)`，每个城市 DFS 时会扫描连接矩阵的一行。
- 空间复杂度：`O(n)`，主要是 `visited` 和递归栈。

## 本地输入格式

```text
n
isConnected[0][0] isConnected[0][1] ...
isConnected[1][0] isConnected[1][1] ...
...
```

样例：

```text
3
1 1 0
1 1 0
0 0 1
```

正确输出应该是：

```text
2
```
