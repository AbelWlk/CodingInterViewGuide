#include <stdio.h>
#include <stdlib.h>
#include "Stack/Stack.h"

/*
题目：用2个栈实现队列，支持队列基本操作 
要点：1.stackPush向stackPop压入数据时，必须一次性将stackPush全部压入
     2.如果stackPop不为空,则不能压入数据，等到stackPop中的数据慢慢全部弹出后，则又可以再次压入
     这保证了stackPop栈顶元素始终是队列头元素*/

void QueueInit(Stack *stackPush, Stack *stackPop) {
    *stackPush = Init();
    *stackPop = Init();
}

void QueueAdd(Stack stackPush, int data) {
    Push(stackPush, data);
}

int QueuePoll(Stack stackPush, Stack stackPop) {
    if (IsEmpty(stackPop) == 1 && IsEmpty(stackPush) == 1)//都为空时队列为空
    {
        printf("Queue is empty!");
        return -1;
    } else if (IsEmpty(stackPop) == 1)//有一个不为空，判断是不是stackPop为空
    {
        while (IsEmpty(stackPush) != 1)//如果是stackPop为空，则stackPush必定不为空；将其中数据全部压入stackPop
        {
            Push(stackPop, Pop(stackPush));
        }
    }
    return Pop(stackPop);//如果不是stackPop为空，则直接弹出stcakPop栈顶
}

int QueuePeek(Stack stackPush, Stack stackPop) {
    if (IsEmpty(stackPop) == 1 && IsEmpty(stackPush) == 1) {
        printf("Queue is empty!");
        return -1;
    } else if (IsEmpty(stackPop) == 1) {
        while (IsEmpty(stackPush) != 1) {
            Push(stackPop, Pop(stackPush));
        }
    }
    return stackPop->Next->Data;//返回栈顶元素，但是不弹栈
}

int main() {
    Stack stackPush, stackPop;
    QueueInit(&stackPush, &stackPop);

    QueueAdd(stackPush, 10);
    QueueAdd(stackPush, 180);

    printf("%d\n", QueuePeek(stackPush, stackPop));
    printf("%d\n", QueuePoll(stackPush, stackPop));
    printf("%d\n", QueuePoll(stackPush, stackPop));

    return 0;
}