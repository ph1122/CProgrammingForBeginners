/*
https://leetcode.cn/problems/number-of-recent-calls/description/
写一个 RecentCounter 类来计算特定时间范围内最近的请求。

请你实现 RecentCounter 类：

RecentCounter() 初始化计数器，请求数为 0 。
int ping(int t) 在时间 t 添加一个新请求，其中 t 表示以毫秒为单位的某个时间，并返回过去 3000 毫秒内发生的所有请求数（包括新请求）。确切地说，返回在 [t-3000, t] 内发生的请求数。
保证 每次对 ping 的调用都使用比之前更大的 t 值。



示例 1：

输入：
["RecentCounter", "ping", "ping", "ping", "ping"]
[[], [1], [100], [3001], [3002]]
输出：
[null, 1, 2, 3, 3]

解释：
RecentCounter recentCounter = new RecentCounter();
recentCounter.ping(1);     // requests = [1]，范围是 [-2999,1]，返回 1
recentCounter.ping(100);   // requests = [1, 100]，范围是 [-2900,100]，返回 2
recentCounter.ping(3001);  // requests = [1, 100, 3001]，范围是 [1,3001]，返回 3
recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002]，范围是 [2,3002]，返回 3


提示：

1 <= t <= 109
保证每次对 ping 调用所使用的 t 值都 严格递增
至多调用 ping 方法 104 次
*/

#include <stdlib.h>

#define MAX_REQUESTS 10001  // 保证能容纳14e次调用 

typedef struct {
    int* requests;
    int front;
    int rear;
    int size;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter* obj = malloc(sizeof(RecentCounter));
    if (!obj) return NULL;

    obj->requests = malloc(sizeof(int) * MAX_REQUESTS);
    if (!obj->requests) {
        free(obj);
        return NULL;
    }

    obj->front = 0;
    obj->rear = 0;
    obj->size = 0;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    const int window_start = t - 3000;

    // 移除窗口外的所有过期请求 
    while (obj->size > 0 && obj->requests[obj->front] < window_start) {
        obj->front++;
        obj->size--;
    }

    // 添加新请求 
    obj->requests[obj->rear++] = t;
    obj->size++;

    return obj->size;
}

void recentCounterFree(RecentCounter* obj) {
    if (obj) {
        free(obj->requests);
        free(obj);
    }
}