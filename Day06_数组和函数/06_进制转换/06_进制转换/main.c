#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/*
除留余数法

当前数     商     余数
  14        7       0
   7        3       1
   3        1       1
   1        0       1

14 -> 1110
*/

int main() {
    int curr, quo, rem[32];
    int size = 0;
    int base = 9;
    // curr = 14;
    scanf("%d", &curr);
    while (curr) {
        quo = curr / 2;
        //printf("%d\n", quo);
        //printf("%d\n", curr%2);
        rem[size] = curr % 2;
        //printf("%d\n", size);
        //printf("%d\n", rem[size]);
        ++size;
        curr /= 2;
    }
    //printf("%d\n", size);
    for (int i = size - 1; i >= 0; --i) {
        printf("%d", rem[i]);
    }

	return 0;
}