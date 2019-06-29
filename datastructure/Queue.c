// Created by wlk on 2019/6/25 22:39.
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

Queue Init() {
    Queue q = (Queue) malloc(sizeof(struct QNode));
    q->Front = q->Rear = NULL;
    return q;
}

//1:true  0:false
int IsEmpty(Queue q) {
    return (q->Front == NULL);
}

void AddQ(Queue q, int data) {
    PtrNode tmpNode = (PtrNode) malloc(sizeof(struct Node));
    tmpNode->Data = data;
    tmpNode->Next = NULL;
    if (IsEmpty(q) == 1) {
        q->Front = tmpNode;
        q->Rear = tmpNode;
    } else {
        q->Rear->Next = tmpNode;
        q->Rear = tmpNode;
    }
}

int DeleteQ(Queue q) {

    PtrNode topNode;
    int data;

    if (IsEmpty(q) == 1) {
        printf("Queue Is Empty!");
        return -1;
    } else {
        topNode = q->Front;
        if (q->Front == q->Rear) //如果队列只有一个元素
        {
            q->Front = q->Rear = NULL;
        } else {
            q->Front = q->Front->Next;
        }
        data = topNode->Data;
        free(topNode);
        return data;
    }
}

void foreachQueue(Queue q) {
    if (IsEmpty(q) == 1) {
        printf("Queue Is Empty!");
        return;
    }
    PtrNode pCurrent = q->Front;
    while (pCurrent) {
        printf("%d ", pCurrent->Data);
        pCurrent = pCurrent->Next;
    }
    printf("\n");
}
