#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct Point {
	double x, y;
};

struct Circle {
	struct Point pt;
	double radius;
};

void PrintCircle(struct Circle c) {
	printf("圆心(%.1f, %.1f), 半径%.1f\n", c.pt.x, c.pt.y, c.radius);
}

void moveCircle(struct Circle* c, double x, double y) {
	c->pt.x += x;
	c->pt.y += y;
}
int main() {
	struct Circle c = { {9, 8}, 5 };
	PrintCircle(c);
	moveCircle(&c, +2, -1);
	PrintCircle(c);

	return 0;
}