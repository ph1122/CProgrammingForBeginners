#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	char name[100] = "./hhh/fread.txt";
	FILE* f = fopen(name, "r");
	if (f == NULL) {
		printf("文件不存在");
		return -1;
	}
	char buff[100];
	//int n = fread(buff, 1, 5, f);
	//for (int i = 0; i < n; ++i) {
	//	printf("%c", buff[i]);
	//}
	int n;
	int sum = 0;
	while (n = fread(buff, 1, 7, f)) {
		//printf("%d\n", n); // 7 7 7 7 ......7 7 4      375 % 7 = 4
		for (int i = 0; i < n; ++i) {
			printf("%c", buff[i]);
		}
		sum += n;
		//printf("")
	}
	printf("\n%d\n", n);   // 0
	printf("%d\n", sum);   // 375     

	return 0;
}

/*
 **返回值**

- **成功时**：返回实际读取的数据项数量（`size_t` 类型）。
- **失败时**：
  - 如果到达文件末尾（EOF）或发生错误，返回的值可能小于 `nmemb`。
  - 可以使用 `feof()` 或 `ferror()` 进一步检查是到达文件末尾还是发生了错误。
*/