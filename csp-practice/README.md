# CSP C Practice

这个目录用来记录 CSP 备考时写过的题目代码、思路和错误。

## 使用方式

每做一道题，就在 `problems/` 下新建一个文件夹：

```text
problems/
  001-problem-name/
    main.c
    notes.md
    input.txt
```

建议每题至少记录三样东西：

- `main.c`：你的最终代码，或者正在调试的代码。
- `notes.md`：题目思路、错因、复杂度、复盘。
- `input.txt`：自己手写的测试数据。

## C 语言编译运行

如果你电脑上安装了 `gcc`，可以在 PowerShell 里运行：

```powershell
gcc .\problems\000-sample-sum\main.c -o .\problems\000-sample-sum\main.exe
Get-Content .\problems\000-sample-sum\input.txt | .\problems\000-sample-sum\main.exe
```

做新题时，把路径换成对应题目的 `main.c` 即可。

## 刷题记录

LeetCode 备考题单见：[leetcode-practice-list.md](./leetcode-practice-list.md)

| 编号 | 题目 | 类型 | 状态 | 错因/备注 |
|---|---|---|---|---|
| 000 | sample-sum | 输入输出 | 已完成 | 用来测试编译运行流程 |
| 001 | lc704-binary-search | 二分查找 | LeetCode 已通过 | 闭区间二分 |
| 002 | lc35-search-insert-position | 二分查找 | LeetCode 已通过 | 找不到时返回插入位置 |

## 常见复盘点

- 输入是否读完整。
- 数组大小是否足够。
- `int` 是否会溢出，需要不要用 `long long`。
- 边界情况是否考虑，比如 `n = 0`、`n = 1`、最大数据。
- 时间复杂度是否能通过题目数据范围。
