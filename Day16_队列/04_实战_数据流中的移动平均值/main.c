/*
https://leetcode.cn/problems/qIsx9U/
给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算滑动窗口里所有数字的平均值。

实现 MovingAverage 类：

MovingAverage(int size) 用窗口大小 size 初始化对象。
double next(int val) 成员函数 next 每次调用的时候都会往滑动窗口增加一个整数，请计算并返回数据流中最后 size 个值的移动平均值，即滑动窗口里所有数字的平均值。


示例：

输入：
inputs = ["MovingAverage", "next", "next", "next", "next"]
inputs = [[3], [1], [10], [3], [5]]
输出：
[null, 1.0, 5.5, 4.66667, 6.0]

解释：
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // 返回 1.0 = 1 / 1
movingAverage.next(10); // 返回 5.5 = (1 + 10) / 2
movingAverage.next(3); // 返回 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // 返回 6.0 = (10 + 3 + 5) / 3


提示：

1 <= size <= 1000
-105 <= val <= 105
最多调用 next 方法 104 次
*/


typedef struct {
    int* element;
    int front;
    int rear;
    int size;
} MovingAverage;

/** Initialize your data structure here. */

MovingAverage* movingAverageCreate(int size) {
    MovingAverage* obj = (MovingAverage*)malloc(sizeof(MovingAverage));
    if (!obj) {
        return NULL;
    }
    int* element = (int*)malloc(sizeof(int) * 10000);
    if (!element) {
        free(obj);
        return NULL;
    }

    obj->element = element;
    obj->front = 0;
    obj->rear = 0;
    obj->size = size;
    return obj;
}

double movingAverageNext(MovingAverage* obj, int val) {
    int index = obj->front;
    double sum = 0;
    obj->element[obj->rear++] = val;
    if (obj->rear - obj->front <= obj->size) {
        while (index != obj->rear) {
            sum += obj->element[index];
            index++;
        }
        return sum / (obj->rear - obj->front);
    }
    obj->front++;
    index = obj->front;
    while (index != obj->rear) {
        sum += obj->element[index];
        index++;
    }
    return sum / obj->size;
}

void movingAverageFree(MovingAverage* obj) {
    free(obj->element);
    free(obj);

}

/**
 * Your MovingAverage struct will be instantiated and called as such:
 * MovingAverage* obj = movingAverageCreate(size);
 * double param_1 = movingAverageNext(obj, val);

 * movingAverageFree(obj);
*/


#include <stdlib.h>

typedef struct {
    int* window;    // 窗口存储 
    int size; // 最大容量 
    int count;      // 当前元素数 
    int head;       // 插入位置指针 
    double sum;     // 当前窗口和 
} MovingAverage;

MovingAverage* movingAverageCreate(int size) {
    MovingAverage* obj = malloc(sizeof(MovingAverage));
    obj->window = malloc(sizeof(int) * size);
    obj->size = size;
    obj->count = 0;
    obj->head = 0;
    obj->sum = 0.0;
    return obj;
}

double movingAverageNext(MovingAverage* obj, int val) {
    if (obj->count < obj->size) {
        // 窗口未满时直接累加 
        obj->sum += val;
        obj->window[obj->head] = val;
        obj->count++;
    }
    else {
        // 窗口已满时替换最旧元素 
        obj->sum += val - obj->window[obj->head];
        obj->window[obj->head] = val;
    }

    // 更新插入位置（循环覆盖）
    obj->head = (obj->head + 1) % obj->size;

    // 计算当前有效元素数量 
    int divisor = obj->count < obj->size ? obj->count : obj->size;
    return obj->sum / divisor;
}

void movingAverageFree(MovingAverage* obj) {
    free(obj->window);
    free(obj);
}

