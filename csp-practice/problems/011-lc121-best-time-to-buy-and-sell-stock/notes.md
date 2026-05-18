# 011-lc121-best-time-to-buy-and-sell-stock

## 题目信息

- 来源：LeetCode 121 Best Time to Buy and Sell Stock
- 链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
- 类型：数组 / 贪心
- 难度：简单
- 完成日期：2026-05-18
- 状态：LeetCode 已通过

## 题意

给定每天的股票价格，只能买入一次、卖出一次，且买入必须在卖出之前。求最大利润。如果无法盈利，返回 `0`。

## 我的思路

一开始写了暴力版：

- 枚举买入日 `i`。
- 枚举卖出日 `j`，要求 `j > i`。
- 利润是 `prices[j] - prices[i]`。

暴力版逻辑正确，但时间复杂度是 O(n^2)，LeetCode 会超时。

最终改成一趟遍历：

- `minPrice` 表示到当前为止见过的最低买入价。
- `maxProfit` 表示当前最大利润。
- 每一天都尝试作为卖出日，利润是 `prices[i] - minPrice`。
- 如果今天价格更低，就更新 `minPrice`，给未来卖出日使用。

核心逻辑：

```c
int minPrice = prices[0];
int maxProfit = 0;

for (int i = 1; i < pricesSize; i++) {
    int profit = prices[i] - minPrice;
    if (profit > maxProfit) {
        maxProfit = profit;
    }

    if (prices[i] < minPrice) {
        minPrice = prices[i];
    }
}
```

## 关键边界

- 价格一直下降：返回 `0`。
- 价格一直上升：最大利润是最后一天减第一天。
- 最大利润出现在中间。
- 只有一天价格：返回 `0`。
- 多天价格相同：返回 `0`。

## 错误记录

- 一开始把一段价格相加，误解成求区间和。实际上利润是卖出价减买入价。
- 暴力版会超时。
- 边界判断 `pricesSize <= 1` 应该放在访问 `prices[0]` 之前。

## 复杂度

- 时间复杂度：O(n)
- 空间复杂度：O(1)

## 本地输入格式

```text
n
prices[0] prices[1] ... prices[n-1]
```

样例：

```text
6
7 1 5 3 6 4
```

输出：

```text
5
```

## 测试记录

本地用 `gcc -Wall -Wextra -std=c11` 编译通过。

测试过的情况：

- LeetCode 样例：通过。
- 价格一直下降：通过。
- 价格一直上升：通过。
- 多天价格相同：通过。
- 只有一天价格：通过。

## 复盘

这题的关键是“每一天都可以作为卖出日”。如果今天卖出，最优买入价一定是今天之前见过的最低价，所以只需要维护一个 `minPrice`。
