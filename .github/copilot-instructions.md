# AI 编码代理指南

为了帮助 AI 编码代理在这个 C 语言学习项目中更高效地工作，请遵循以下指南：

## 项目概述
本项目是一个 C 语言学习仓库，包含各种 C 语言程序的示例。每个程序通常位于一个独立的子目录中，并包含其源代码 (`.c` 文件) 和一个 `output` 子目录，用于存放编译后的可执行文件。

## 关键开发工作流程

### 1. Windows 环境下的编译
本项目中的 C 语言程序通常使用 `gcc` 编译器进行编译。标准的编译命令模式如下：

```bash
C:\mingw64\bin\gcc.exe -Wall -Wextra -g3 <source_file.c> -o <output_directory/executable_name.exe> -lm
```

**示例:**
要编译 `素回文数判断输出/pripal.c`，命令如下：
```bash
C:\mingw64\bin\gcc.exe -Wall -Wextra -g3 素回文数判断输出/pripal.c -o 素回文数判断输出/output/pripal.exe -lm
```
请注意，`C:\mingw64\bin\gcc.exe` 是本环境中 `gcc` 的完整路径。在编写编译命令时，务必使用此完整路径。

### 2. Linux 环境下的编译
在 Linux 环境下，`gcc` 通常已安装并位于系统路径中。标准的编译命令模式如下：

```bash
gcc -Wall -Wextra -g3 <source_file.c> -o <output_directory/executable_name> -lm
```

**示例:**
要编译 `素回文数判断输出/pripal.c`，命令如下：
```bash
gcc -Wall -Wextra -g3 素回文数判断输出/pripal.c -o 素回文数判断输出/output/pripal -lm
```
请注意，在 Linux 环境下，可执行文件通常没有 `.exe` 扩展名。

## 项目特定约定

### 1. 目录结构
每个功能或练习通常都有一个独立的目录。例如：
- `素回文数判断输出/`
  - `pripal.c` (源代码)
  - `output/`
    - `pripal.exe` (编译后的可执行文件)

在进行文件操作或编译时，请始终参考当前的工作目录和目标文件的相对路径。

### 2. 输出文件
编译后的可执行文件通常位于其对应源代码目录下的 `output/` 子目录中。请确保编译命令将可执行文件输出到正确的 `output/` 目录。

### 3. 代码风格
代码风格应保持简洁和可读性，遵循 C 语言的常见最佳实践。目前没有强制性的特定代码风格指南，但应保持一致性。
