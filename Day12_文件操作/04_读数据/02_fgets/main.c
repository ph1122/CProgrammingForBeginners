#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	char name[] = "./hhh/fgets.txt";
	FILE* f = fopen(name, "r");
	if (f == NULL) {
		printf("文件不存在");
		return -1;
	}
	char data[1024];
	char* str = NULL;
	/*
	str = fgets(data, 1024, f);
	printf(data); // 123435换行
	printf(str); // 123435换行
	str = fgets(data, 1024, f); 
	printf(data); // rf gs dg gr换行
	printf(str); // rf gs dg gr换行
	str = fgets(data, 1024, f);
	printf(data); // 3124 gfdfg
	printf(str); // 3124 gfdfg
	str = fgets(data, 1024, f);
	printf(data); // 3124 gfdfg
	printf("%s",str);// (null)
	str = fgets(data, 1024, f);
	printf(data); // 3124 gfdfg
	printf("%s", str);// (null)
	*/
	/*
	* 返回值
		成功时：返回 str，即指向缓冲区的指针。
		失败时：
			如果到达文件末尾（EOF），返回 NULL。
			如果发生错误，返回 NULL。
	如果 fgets() 返回 NULL：
	在读取任何字符之前遇到 EOF 或发生错误：buffer 的内容不会被修改，保持不变。
	在读取部分字符后遇到 EOF：buffer 中会存储已读取的部分内容，并以 \0 结尾。
	*/

	//while ((str = fgets(data, 1024, f) != NULL)
	while (str = fgets(data, 1024, f)) {
		//printf(data);
		printf("%s", data);
	}

	fclose(f);
	return 0;
}

