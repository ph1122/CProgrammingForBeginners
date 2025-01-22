#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	char name[] = "./hhh/pwrite.txt";
	FILE* f = fopen(name, "w");
	if (f == NULL) {
		printf("文件不存在！");
		return -1;
	}

	const char* str = "abcdefghijk";
	int x = fwrite(str, 1, 3, f);
	printf("%d\n", x);

	return 0;
}

