// Created by wlk on 2019/6/25 22:39.
#ifndef CODINGINTERVIEWGUIDE_QUEUE_H
#define CODINGINTERVIEWGUIDE_QUEUE_H

#include <stdio.h>

typedef struct Node *PtrNode;
struct Node {
    int Data;
    PtrNode Next;
};

struct QNode {
    PtrNode Front, Rear;
};
typedef struct QNode *Queue;

Queue Init();

int IsEmpty(Queue q);

void AddQ(Queue q, int data);

int DeleteQ(Queue q);

#endif //CODINGINTERVIEWGUIDE_QUEUE_H
