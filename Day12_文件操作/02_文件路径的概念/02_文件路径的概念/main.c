#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1、绝对路径
    // "D:\Users\x.txt"

    // 2、相对路径
    // "Users\x.txt"
    // "hhh\gg.txt"

    return 0;
}

/*
. (当前目录)：表示当前工作目录。例如，./file.txt 表示当前目录下的 file.txt 文件。
.. (上一级目录)：表示当前目录的父级目录。例如，../file.txt 表示上一级目录中的 file.txt 文件。

在不同操作系统上，路径的分隔符有所不同。
在 Unix/Linux 系统中使用 /，而在 Windows 系统中使用 \。C语言标准库提供的路径函数通常会处理这些差异。
*/