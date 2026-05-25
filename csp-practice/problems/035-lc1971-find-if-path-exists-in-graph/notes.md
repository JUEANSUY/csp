# 035-lc1971-find-if-path-exists-in-graph

## 题目信息

- 来源：LeetCode 1971 Find if Path Exists in Graph
- 链接：https://leetcode.cn/problems/find-if-path-exists-in-graph/
- 类型：并查集 / DFS / BFS
- 难度：简单
- 状态：练习中

## 题意

给一个无向图，判断从 `source` 到 `destination` 是否存在一条路径。

边是双向的，只要两个点在同一个连通块里，就说明它们之间存在路径。

## 思路提示

这题建议用并查集练习。

可以先想：

- `parent[x]` 表示节点 `x` 的父节点。
- 一开始每个点自己是一个集合：`parent[i] = i`。
- 对于每条边 `[a, b]`，把 `a` 和 `b` 所在的集合合并。
- 最后判断 `source` 和 `destination` 的根节点是否相同。

需要写两个核心函数：

- `find(x)`：找到 `x` 所在集合的根。
- `union(a, b)`：把 `a` 和 `b` 所在集合合并。

## 关键边界

- `source == destination`。
- 没有边。
- 图不连通。
- 多条边连接同一组点。
- 节点编号从 0 到 `n - 1`。

## 错误记录

-

## 复杂度

- 时间复杂度：
- 空间复杂度：

## 本地输入格式

```text
n m
u1 v1
u2 v2
...
um vm
source destination
```

样例：

```text
3 3
0 1
1 2
2 0
0 2
```

正确输出应该是：

```text
true
```
