#include<stdio.h>
// unsigned 无符号 0和正数
int main() {
	short a = 1;
	unsigned short a1 = 1;
	// d --> u
	/*
		unsigned short:       %hu
		unsigned int:         %u
		unsigned long:        %lu
		unsigned long long :  %llu
	*/
	// unsigned short 的范围 [0, 2^16)
	printf("%hd\n", a);
	printf("%hu\n", a);

	unsigned short b = 65536;
	printf("%hu\n", b);// 0           1 00000000 00000000

	unsigned short c = -1;
	printf("%hu\n", c);// 65535       11111111 11111111
	printf("%hd\n", 65535);// -1
	return 0;
}