# CSP 真题记录

这个目录用来记录 CCF CSP 认证真题练习。

## OJ 入口

- CSP 真题题库：[曙梦 OJ CSP 题库](https://oj.shumeng.tech/p?page=3&q=category%3ACSP)
- 题目链接通常形如：`https://oj.shumeng.tech/p/CSP202603A`

如果 VPN 打不开，可以尝试关闭 VPN，或把 `oj.shumeng.tech` 设置为直连。

建议每套真题按月份建立目录：

```text
csp-real/
  202603/
    01-csp202603a-balanced-number/
      main.c
      notes.md
      input.txt
```

## 已建立套卷

| 套卷 | 说明 | 本地记录 |
|---|---|---|
| CSP202509 | 2025 年 9 月 CCF CSP 认证 | [202509/](./202509/) |
| CSP202512 | 2025 年 12 月 CCF CSP 认证 | [202512/](./202512/) |
| CSP202603 | 2026 年 3 月第 41 次 CCF CSP 认证 | [202603/](./202603/) |

总进度见：[progress.md](./progress.md)

## 运行方式

从仓库根目录运行：

```powershell
.\scripts\run.ps1 csp-real\202603\01-csp202603a-balanced-number
```

脚本会编译该目录下的 `main.c`，并使用同目录的 `input.txt` 作为输入。

练真题时优先记录：

- 题目编号和来源。
- 题意是否读懂。
- 输入输出格式。
- 数据范围。
- 暴力思路为什么不够。
- 正解思路和复杂度。
- 自己的思路。
- 错误记录、边界样例和 OJ 得分。

真题笔记可以直接参考 `templates/csp_notes_template.md` 的结构：先把题意翻译成人话，再写暴力、正解、复杂度和错因。
