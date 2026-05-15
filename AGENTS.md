# Agent Notes

这个工作区主要用于 CSP 考试备考，使用 C 语言记录刷题代码。

## 用户背景

- 用户是大学生，正在准备 CSP 考试。
- 当前主要使用 C 语言。
- 编程基础还在提升阶段，解释时应尽量清楚、具体、循序渐进。
- 回答代码问题时，优先讲清楚输入、输出、数组边界、数据范围和复杂度。

## 项目结构

主要练习目录：

```text
csp-practice/
  README.md
  templates/
    c_template.c
    notes_template.md
  problems/
    000-sample-sum/
      main.c
      notes.md
      input.txt
```

新增题目时，建议使用：

```text
csp-practice/problems/编号-题目名/
  main.c
  notes.md
  input.txt
```

## 编码偏好

- 使用 C 语言，不默认改成 C++ 或 Python。
- 示例代码尽量简单，不使用太复杂的宏和高级写法。
- 如果可能溢出，提醒使用 `long long`。
- 数组大小要结合题目数据范围说明。
- 变量名可以短，但关键逻辑要容易看懂。
- 注释只写关键点，不写太多空泛说明。

## 题目记录习惯

每道题建议记录：

- 题目类型。
- 解题思路。
- 关键边界。
- 错误记录。
- 时间复杂度和空间复杂度。
- 复盘总结。

## 本地编译运行

当前环境已检测到 `gcc` 可用。

示例编译运行命令：

```powershell
gcc .\csp-practice\problems\000-sample-sum\main.c -o .\csp-practice\problems\000-sample-sum\main.exe
Get-Content .\csp-practice\problems\000-sample-sum\input.txt | .\csp-practice\problems\000-sample-sum\main.exe
```

以后新题只需要替换对应题目目录路径。
