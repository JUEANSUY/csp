# 008-lc54-spiral-matrix

## 题目信息

- 来源：LeetCode 54 Spiral Matrix
- 链接：https://leetcode.cn/problems/spiral-matrix/
- 类型：矩阵 / 模拟
- 难度：中等
- 完成日期：2026-05-17
- 状态：LeetCode 已通过

## 题意

给定一个 `m x n` 的矩阵，按照顺时针螺旋顺序返回矩阵中的所有元素。

遍历顺序可以理解为：

```text
上边 -> 右边 -> 下边 -> 左边
```

然后不断缩小矩阵边界，直到所有元素都被访问。

## 我的思路

使用四个边界变量：

- `top`：当前上边界。
- `bottom`：当前下边界。
- `left`：当前左边界。
- `right`：当前右边界。

每一轮：

1. 从左到右遍历上边，然后 `top++`。
2. 从上到下遍历右边，然后 `right--`。
3. 如果 `top <= bottom`，从右到左遍历下边，然后 `bottom--`。
4. 如果 `left <= right`，从下到上遍历左边，然后 `left++`。

循环条件是：

```c
while (top <= bottom && left <= right)
```

## LeetCode C 签名

本题 LeetCode 的 C 语言函数签名是：

```c
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
```

注意：

- `matrix` 是 `int**`，不是本地常见的二维数组 `int matrix[MAXN][MAXN]`。
- `matrixColSize` 是 `int*`，列数用 `matrixColSize[0]` 取得。
- 结果数组需要 `malloc`，并通过 `returnSize` 返回结果长度。

本地为了方便测试，使用 `raw[MAXN][MAXN]` 存数据，再构造 `int *matrix[MAXN]` 来适配 LeetCode 风格的函数签名。

## 关键边界

- 只有一行。
- 只有一列。
- 正方形矩阵。
- 长方形矩阵。
- 最后一圈只剩一个元素。
- 最后一圈只剩一行或一列。

## 错误记录

- 第一次写法中，用 `i < matrixSize * matrixColSize` 判断是否还能继续遍历，但这个条件不能防止单行、单列时重复遍历。
- 单行矩阵曾经出现运行异常，原因是走完上边后没有根据 `top <= bottom` 判断是否还存在下边。
- LeetCode 提交时报过 `int **` 和二维数组类型不兼容，后来改成 LeetCode 的 `int** matrix` 签名。

## 复杂度

- 时间复杂度：O(m * n)
- 空间复杂度：O(m * n)，用于返回结果数组。

## 本地输入格式

```text
m n
matrix[0][0] matrix[0][1] ...
...
```

样例：

```text
3 3
1 2 3
4 5 6
7 8 9
```

输出：

```text
1 2 3 6 9 8 7 4 5
```

## 测试记录

本地用 `gcc -Wall -Wextra -std=c11` 编译通过。

测试过的情况：

- `3 x 3` 正方形矩阵：通过。
- `1 x 4` 单行矩阵：通过。
- `4 x 1` 单列矩阵：通过。
- `3 x 4` 长方形矩阵：通过。
- `2 x 2` 矩阵：通过。

## 复盘

模拟题要把“状态变量”维护清楚。这里最重要的是四个边界变量，每走完一条边就收缩对应边界。不能只用已经遍历的元素数量来判断下一条边是否存在，否则容易在单行或单列矩阵里重复遍历。
