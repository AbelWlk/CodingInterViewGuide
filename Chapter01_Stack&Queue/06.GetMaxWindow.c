// Created by wlk on 2019/6/29 12:00.
#include <stdio.h>
#include "datastructure/LinkedList.h"

/*生成窗口最大值数组
 * 窗口大小为w,数组长度为n,则一共产生n-w+1个窗口最大值
 * 输入：数组arr,数组长度length,窗口大小w
 * 输出：一个长度为n-w+1的数组res,res[i]为每个窗口状态小最大值*/

int *getMaxWindow(const int *arr, int length, int w) {
    if (arr == NULL || w < 1 || length < w) {
        return NULL;
    }
    LinkedList qmax = Init();
    int *res = malloc(sizeof(int) * (length - w + 1));
    int index = 0;
    for (int i = 0; i < length; i++) {
        while (IsEmpty(qmax) != 1 && arr[PeekLast(qmax)] <= arr[i]) {
            PollLast(qmax);
        }
        AddLast(qmax, i);
        if (PeekFirst(qmax) == i - w) {
            PollFirst(qmax);
        }
        if (i >= w - 1) {
            res[index++] = arr[PeekFirst(qmax)];
        }
    }
    return res;
}

int main() {
    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int *res = getMaxWindow(arr, 8, 3);

    for (int i = 0; i < sizeof(arr) / sizeof(int) - 2; i++) {
        printf("%d ", res[i]);
    }

    return 0;
}