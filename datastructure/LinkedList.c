// Created by wlk on 2019/6/29 12:10.

#include "LinkedList.h"

LinkedList Init() {
    LinkedList l = (LinkedList) malloc(sizeof(struct LNode));
    l->Head = l->Tail = NULL;
    return l;
}

int IsEmpty(LinkedList l) {
    return l->Head == NULL;
}

void AddLast(LinkedList l, int data) {
    PtrNode tmpNode = (PtrNode) malloc(sizeof(struct Node));
    tmpNode->Data = data;
    tmpNode->Next = NULL;
    if (IsEmpty(l) == 1) {
        l->Head = l->Tail = tmpNode;
    } else {
        l->Tail->Next = tmpNode;
        l->Tail = tmpNode;
    }
}

int PollFirst(LinkedList l) {
    if (IsEmpty(l) == 1) {
        printf("LinkedList is Empty!");
        return -1;
    } else {
        PtrNode firstNode = l->Head;
        if (l->Head = l->Tail) {
            l->Head = l->Tail = NULL;
        } else {
            l->Head = l->Head->Next;
        }
        int data = firstNode->Data;
        free(firstNode);
        return data;
    }
}

int PollLast(LinkedList l) {
    if (IsEmpty(l) == 1) {
        printf("LinkedList is Empty!");
        return -1;
    } else {
        PtrNode lastNode = l->Tail;
        if (l->Head = l->Tail) {
            l->Head = l->Tail = NULL;
        } else {
            PtrNode preNode = l->Head;
            while (preNode->Next->Next != NULL) {
                preNode = preNode->Next;
            }
            l->Tail = preNode;
        }
        int data = lastNode->Data;
        free(lastNode);
        return data;
    }
}

int PeekFirst(LinkedList l) {
    if (IsEmpty(l) == 1) {
        printf("LinkedList is Empty!");
        return -1;
    } else {
        return l->Head->Data;
    }
}

int PeekLast(LinkedList l) {
    if (IsEmpty(l) == 1) {
        printf("LinkedList is Empty!");
        return -1;
    } else {
        return l->Tail->Data;
    }
}