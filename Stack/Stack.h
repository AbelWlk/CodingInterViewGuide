#include <stdio.h>
#include <stdlib.h>

/*-----------------实现普通简易栈------------------*/
typedef struct SNode *PtrNode;
struct SNode {
    int Data;
    PtrNode Next;
};
typedef struct SNode *Stack;

Stack Init();

int IsEmpty(Stack s);

int Push(Stack s, int data);

int Pop(Stack s);