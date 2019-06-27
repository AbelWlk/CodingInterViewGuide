// Created by wlk on 2019/6/25 22:39.

#include <stdio.h>
#include <stdlib.h>

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

void foreachQueue(Queue q);
