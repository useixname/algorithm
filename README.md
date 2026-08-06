# Algorithm Learning Repository

> 一个以 C++ 为主的算法学习与题解代码库，按常见知识点整理，便于查找、复习与练习。

This is a personal collection of C++ algorithm-learning code and competitive-programming solutions. The repository is organized by topic rather than by a single buildable application.

## 内容概览

仓库收录了大量独立的 C++ 程序，覆盖基础数据结构、经典算法与题目练习。目录名称保留了学习过程中的中英文与拼音命名；下面的索引帮助你快速定位主题。

| 学习方向 | 主要目录 |
| --- | --- |
| 基础数据结构与 STL | `Data Structure`、`Data Structure1`、`STL`、`lianbiao`、`stack`、`set`、`map`、`priority-queue` |
| 查找、递归与搜索 | `Bibary Search`、`erfensuafa`、`dfs and bfs`、`ditui`、`fenzhi` |
| 动态规划与策略 | `dp`、`jiyihuass`、`greedy`、`tanxinsuafa`、`moni` |
| 数学与数论 | `math`、`shuxue`、`kateilanshu`、`gaojingdu`、`weiyunsuai` |
| 常用技巧 | `sort`、`tow pointer`、`qianzuiheyuchafen`、`zifuchuai`、`xiangduanshu`、`bingchajing` |
| 图论 | `tulun` |
| 题目练习与复习 | `leetcode`、`code`、`fuxi`、`qita` |

其中，`xiangduanshu` 对应线段树，`bingchajing` 对应并查集，`qianzuiheyuchafen` 对应前缀和与差分，`weiyunsuai` 对应位运算。`Bibary Search` 与 `tow pointer` 等目录沿用原有拼写。

## 快速开始

大部分文件都是可独立编译运行的单题程序。请根据所选文件对应的题目格式提供标准输入。

```bash
g++ -std=c++17 -O2 -Wall -Wextra "<path-to-source>.cpp" -o solution
./solution < input.txt
```

在 Windows PowerShell 中，可以使用：

```powershell
g++ -std=c++17 -O2 -Wall -Wextra "<path-to-source>.cpp" -o solution.exe
.\solution.exe < input.txt
```

将 `<path-to-source>.cpp` 替换为实际文件路径。目录名中含有空格时，请保留引号。

## 使用建议

1. 从目录索引中选择一个专题，并先阅读文件名或题号接近的实现。
2. 对照题目要求检查输入、输出与边界条件；不同文件并不共享统一的输入格式。
3. 先自行完成题目，再把这里的实现作为思路、复杂度或细节上的参考。
4. 需要复习时，可按“数据结构 → 搜索与排序 → 动态规划 → 图论 → 综合练习”的顺序浏览。

## 仓库说明

- 这是一个学习代码集合，不是带有统一入口、依赖管理或自动化测试的应用项目。
- 每个源文件通常对应一个算法实现、知识点练习或在线评测题目；请单独编译、单独验证。
- 仓库中可能保留本地编译生成的 `.exe`、样例输入输出及压缩包，它们不是运行源码所必需的依赖。
- 文件名与注释的语言、格式会因题目来源和记录时间不同而有所差异。

## Contributing

欢迎通过 Issue 或 Pull Request 补充更清晰的题目来源、复杂度说明、边界条件或替代实现。提交时请尽量保持一个文件对应一个明确主题或题目，并避免提交大型二进制文件。
