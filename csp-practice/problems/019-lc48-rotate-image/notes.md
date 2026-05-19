# 019-lc48-rotate-image

## 题目信息

- 来源：LeetCode 48 Rotate Image
- 链接：https://leetcode.cn/problems/rotate-image/
- 类型：矩阵模拟
- 难度：中等
- 状态：LeetCode 已通过

## 题意

给一个 `n x n` 的矩阵，把它顺时针旋转 90 度。

要求原地修改矩阵，不能返回一个新的矩阵。

## 我的思路

把顺时针旋转 90 度拆成两个操作：

1. 沿主对角线转置。
2. 每一行左右反转。

例子：

```text
1 2 3
4 5 6
7 8 9
```

先转置：

```text
1 4 7
2 5 8
3 6 9
```

再每行反转：

```text
7 4 1
8 5 2
9 6 3
```

## 关键实现

转置时只交换一半：

```c
for (int i = 0; i < matrixSize; i++) {
    for (int j = i + 1; j < matrixSize; j++) {
        swap(matrix[i][j], matrix[j][i]);
    }
}
```

每行反转时也只交换一半：

```c
for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize / 2; j++) {
        swap(matrix[i][j], matrix[i][matrixSize - 1 - j]);
    }
}
```

## 关键边界

- `n = 1`。
- `n = 2`。
- 奇数阶矩阵，中间元素不动。
- 偶数阶矩阵，没有单独中心点。

## 错误记录

- 转置时如果 `j` 从 `0` 到 `matrixSize - 1`，同一对元素会交换两次，最后变回原样。
- 每行反转时如果 `j` 遍历整行，也会左右交换两次，最后变回原样。
- 本地编译时 `matrixColSize` 没用会有 warning，不影响 LeetCode；如果想消掉警告，可以在函数里写 `(void)matrixColSize;`。

## 复杂度

- 时间复杂度：`O(n^2)`。
- 空间复杂度：`O(1)`，原地修改矩阵。

## 本地输入格式

```text
n
matrix[0][0] matrix[0][1] ...
matrix[1][0] matrix[1][1] ...
...
```

样例：

```text
3
1 2 3
4 5 6
7 8 9
```

正确输出应该是：

```text
7 4 1
8 5 2
9 6 3
```
