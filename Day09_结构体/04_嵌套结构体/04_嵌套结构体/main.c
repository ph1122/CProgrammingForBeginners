#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct coordinate {
	double x;
	double y;
};

struct Circule {
	struct coordinate pt;
	double radius;
};

struct Circules {
	int size;
	struct Circule c[100];
};


int main() {
	struct Circule c;
	c.pt.x = 9;
	c.pt.y = 8;
	c.radius = 5;

	struct Circules cs = {
		2,
		{
			{{9, 8}, 5}, {{2,1},1}
		}
	};

	for (int i = 0; i < cs.size; ++i) {
		printf("圆心的坐标是(%.01f, %.1f), 半径是%.01f\n", cs.c[i].pt.x, cs.c[i].pt.y, cs.c[i].radius);
	}
	return 0;
}