# CSP C Practice

这是我的 CSP / LeetCode C 语言刷题记录仓库。

主要目标：

- 用 C 语言练习 CSP 常见算法题型。
- 每道题保留代码、样例输入、思路和复盘。
- 记录错误原因，方便后续复习。

## 目录入口

- 练习主目录：[csp-practice/](./csp-practice/)
- LeetCode 题单：[csp-practice/leetcode-practice-list.md](./csp-practice/leetcode-practice-list.md)
- LeetCode 题目记录：[csp-practice/problems/](./csp-practice/problems/)
- CSP 真题记录：[csp-practice/csp-real/](./csp-practice/csp-real/)
- CSP 真题总进度：[csp-practice/csp-real/progress.md](./csp-practice/csp-real/progress.md)
- C 语言模板：[csp-practice/templates/c_template.c](./csp-practice/templates/c_template.c)
- 真题练习 OJ：[曙梦 OJ CSP 题库](https://oj.shumeng.tech/p?page=3&q=category%3ACSP)

## 每题结构

LeetCode 每道题一个独立目录：

```text
csp-practice/problems/001-lc704-binary-search/
  main.c
  notes.md
  input.txt
```

CSP 真题按考试年月归档：

```text
csp-practice/csp-real/202603/01-csp202603a-balanced-number/
  main.c
  notes.md
  input.txt
```

- `main.c`：本地可编译运行的 C 代码。
- `notes.md`：题意、思路、错误记录、复杂度、复盘。
- `input.txt`：本地测试输入。

## 本地运行

可以使用脚本编译并运行某道题：

```powershell
.\scripts\run.ps1 012-lc70-climbing-stairs
```

真题目录也可以用同一个脚本：

```powershell
.\scripts\run.ps1 csp-real\202603\01-csp202603a-balanced-number
```

对于 LeetCode 题，脚本会自动查找：

```text
csp-practice/problems/012-lc70-climbing-stairs/main.c
csp-practice/problems/012-lc70-climbing-stairs/input.txt
```

然后用 `gcc` 编译，并把 `input.txt` 作为输入运行。

## 学习规则

- 先自己写代码，再检查。
- 错误优先记录在对应题目的 `notes.md`。
- LeetCode 通过后，再更新题单和复盘。
- 多题可以合并提交，减少无意义的 Git 操作。
