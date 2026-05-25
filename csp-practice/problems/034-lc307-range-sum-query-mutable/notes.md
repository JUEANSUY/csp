# 034-lc307-range-sum-query-mutable

## 题目信息

- 来源：LeetCode 307 Range Sum Query - Mutable
- 链接：https://leetcode.cn/problems/range-sum-query-mutable/
- 类型：树状数组 / 线段树
- 难度：中等
- 状态：LeetCode 已通过

## 题意

给一个数组，需要支持两种操作：

- `update(index, val)`：把 `nums[index]` 改成 `val`。
- `sumRange(left, right)`：查询区间 `[left, right]` 的元素和。

和 303 不同，这题数组会被修改，所以普通前缀和不能直接维护。

## 思路提示

建议先学习树状数组，也叫 Binary Indexed Tree。

可以先想：

- 如果每次 `sumRange` 都暴力求和，查询是 O(n)，可能会超时。
- 如果用普通前缀和，查询是 O(1)，但每次更新后很多前缀和都要改，更新是 O(n)。
- 树状数组可以让单点更新和前缀和查询都变成 O(log n)。

这题常用拆法：

- 保存原数组 `nums`，这样更新时能算出差值 `delta = val - nums[index]`。
- 用树状数组维护前缀和。
- `sumRange(left, right) = prefix(right + 1) - prefix(left)`。
- 树状数组内部通常用 1-based 下标，所以原数组下标 `index` 对应树状数组里的 `index + 1`。

## 关键边界

- 只有一个元素。
- 多次更新同一个位置。
- 查询整个数组。
- 查询单个位置。
- 数组里有负数。

## 错误记录

- `NumArray` 里需要同时保存当前真实数组和树状数组；真实数组用于计算 `delta = val - oldValue`。
- `create` 时不能只复制原数组，还要把每个 `nums[i]` 通过 `add(obj, i + 1, nums[i])` 加进树状数组。
- `update` 只处理被修改的位置，不需要遍历数组：先算 `delta`，再更新 `obj->num[index]`，最后用 `add` 维护 `tree`。
- 树状数组内部用 1-based 下标；原数组下标 `index` 进入树状数组时要变成 `index + 1`。
- `sumRange(left, right)` 对应 `prefix(right + 1) - prefix(left)`。
- `free` 时要先释放结构体里的动态数组，再释放结构体本身。

## 复杂度

- 时间复杂度：创建 O(n log n)，单次更新 O(log n)，单次查询 O(log n)。
- 空间复杂度：O(n)。

## 本地输入格式

```text
n
nums[0] nums[1] ... nums[n-1]
q
operation ...
```

操作格式：

```text
sum left right
update index val
```

样例：

```text
5
1 3 5 7 9
3
sum 0 2
update 1 2
sum 0 2
```

正确输出应该是：

```text
9
8
```
