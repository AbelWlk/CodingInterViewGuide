// Created by wlk on 2019/6/29 12:10.

#ifndef CODINGINTERVIEWGUIDE_LINKEDLIST_H
#define CODINGINTERVIEWGUIDE_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrNode;
struct Node {
    int Data;
    PtrNode Next;
};

struct LNode {
    PtrNode Head, Tail;
};
typedef struct LNode *LinkedList;

LinkedList Init();

int IsEmpty(LinkedList l);

void AddLast(LinkedList l, int data);

int PollFirst(LinkedList l);

int PollLast(LinkedList l);

int PeekFirst(LinkedList l);

int PeekLast(LinkedList l);

#endif //CODINGINTERVIEWGUIDE_LINKEDLIST_H
