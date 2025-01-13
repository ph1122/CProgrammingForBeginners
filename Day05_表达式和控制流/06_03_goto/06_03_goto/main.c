#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/*
错误处理：

在多层嵌套的循环或条件语句中，可以使用 goto 跳转到统一的错误处理代码。

跳出多层循环：

在嵌套循环中，goto 可以直接跳出多层循环，而不需要使用多个 break。

goto label;  // 跳转到标签处
...
label:       // 标签定义
    statement;
*/
int main() {
    int i, j;
    for (i = 0; i < 10; ++i) {
        for (j = 0; j < 10; ++j) {
            if (i * i + j * j == 74) {
                goto end;
            }
        }
    }
end:
    printf("i=%d, j=%d\n", i, j);

	return 0;
}