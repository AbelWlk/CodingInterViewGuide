// Created by wlk on 2019/6/27 22:25.

#include "PetQueue.h"

Queue Init() {
    Queue q = (Queue) malloc(sizeof(struct QNode));
    q->Front = q->Rear = NULL;
    return q;
}

int IsEmpty(Queue q) {
    return (q->Front == NULL);
}

void AddQ(Queue q, PetNode petNode) {
    petNode->Count = Count++;
    if (strcmp("dog", pet.Type) == 0) {
        if (IsEmpty(q) == 1) {
            q->Front = q->Rear = petNode;
        } else {
            q->Rear->Next = petNode;
        }
    }
}

int DeleteQ(Queue q);

void foreachQueue(Queue q);