// Created by wlk on 2019/6/27 22:25.

#ifndef CODINGINTERVIEWGUIDE_PETQUEUE_H
#define CODINGINTERVIEWGUIDE_PETQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int Count = 0;

typedef struct Pet *PetNode;
struct Pet {
    char Type[10];
    int Count;
    PetNode Next;
};

struct QNode {
    PetNode Front, Rear;
};
typedef struct QNode *Queue;

Queue Init();

int IsEmpty(Queue q);

void AddQ(Queue q, PetNode petNode);

int DeleteQ(Queue q);

void foreachQueue(Queue q);

#endif //CODINGINTERVIEWGUIDE_PETQUEUE_H
