# 027-lc215-kth-largest-element-in-an-array

## 题目信息

- 来源：LeetCode 215 Kth Largest Element in an Array
- 链接：https://leetcode.cn/problems/kth-largest-element-in-an-array/
- 类型：快速选择 / 三路划分
- 难度：中等
- 状态：LeetCode 已通过

## 题意

给一个整数数组 `nums` 和整数 `k`，返回数组中第 `k` 大的元素。

注意是排序后的第 `k` 大元素，不是第 `k` 个不同的元素。

## 我的思路

先把“第 `k` 大”转换成升序数组里的目标下标：

```c
int target = numsSize - k;
```

例如长度为 `6`，找第 `2` 大，升序下标就是 `6 - 2 = 4`。

最终使用三路快速选择：

1. 在当前区间 `[left, right]` 中随机选一个 `pivot`。
2. 把数组划分成三段：

```text
< pivot
== pivot
> pivot
```

3. 如果 `target` 落在 `< pivot` 区间，就去左边找。
4. 如果 `target` 落在 `> pivot` 区间，就去右边找。
5. 如果 `target` 落在 `== pivot` 区间，直接返回 `nums[target]`。

## 三路划分

维护三个指针：

```c
int lt = left;
int i = left;
int gt = right;
```

它们表示：

```text
[left, lt - 1]   < pivot
[lt, i - 1]      == pivot
[i, gt]          还没处理
[gt + 1, right]  > pivot
```

处理规则：

- `nums[i] < pivot`：和 `nums[lt]` 交换，`lt++`，`i++`。
- `nums[i] > pivot`：和 `nums[gt]` 交换，`gt--`，但 `i` 不动。
- `nums[i] == pivot`：`i++`。

`nums[i] > pivot` 时 `i` 不动，是因为从右边换回来的新 `nums[i]` 还没有检查过。

## 为什么不用普通二路划分

普通二路划分通常分成：

```text
<= pivot
> pivot
```

如果数组中有大量重复元素，例如全是 `1`，每次可能只能缩小很少的范围，容易退化到 `O(n^2)`。

三路划分会把所有 `== pivot` 的元素一次性放在中间，如果目标落在这一段，可以立刻返回，所以重复元素多时更稳。

## 关键边界

- `k = 1`，找最大值。
- `k = numsSize`，找最小值。
- 数组里有大量重复元素。
- 数组里有负数。
- 单元素数组。

## 错误记录

- `pivot` 是值，不是下标。
- 二路 `partition` 返回一个位置，三路划分得到的是 `[lt, gt]` 一整段。
- `while (left < right)` 会漏掉单元素区间，应该使用 `while (left <= right)`。
- 三路划分里不能用普通 `for` 自动 `i++`，因为 `nums[i] > pivot` 时 `i` 不能移动。

## 复杂度

- 时间复杂度：平均 `O(n)`，最坏情况可能退化，但随机 pivot 和三路划分能降低风险。
- 空间复杂度：`O(1)`。

## 本地输入格式

```text
n k
nums[0] nums[1] ... nums[n-1]
```

样例：

```text
6 2
3 2 1 5 6 4
```

正确输出应该是：

```text
5
```
