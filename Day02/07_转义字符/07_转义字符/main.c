#include<stdio.h>

int main() {
	// 1、双引号转义
	//printf("%s\n", "我真是太"机智"了");
	// 加上反斜杠，就意味着后面的引号不要当成特殊含义了，就可以显示出来了
	// 转义字符：把原来的意思转掉了
	// \n 就是后面的n不是普通的英文字母的意思了
	printf("%s\n", "我真是太\"机智\"了");

	// 2、反斜杠转义
	printf("\\ \n");// 输出反斜杠
	printf("D:\Desktop\william\n"); // D:Desktopwilliam
	printf("D:\\Desktop\\william\n"); // D:\Desktop\william

	return 0;
}