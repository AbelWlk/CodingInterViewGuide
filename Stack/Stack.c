#include "Stack.h"

/*-----------------实现普通简易栈------------------*/

Stack Init() { //构建一个堆栈头节点，返回该指针节点
    Stack s;
    s = (Stack) malloc(sizeof(struct SNode));
    s->Next = NULL;
    return s;
}

//1:true  0:false
int IsEmpty(Stack s) { //判断是否为空
    return (s->Next == NULL);
}

int Push(Stack s, int data) {
    //构建节点存入data并压栈
    PtrNode tmpNode = (PtrNode) malloc(sizeof(struct SNode));
    tmpNode->Data = data;
    tmpNode->Next = s->Next;
    s->Next = tmpNode;
    return 0;
}

int Pop(Stack s) {
    PtrNode topNode;
    int data;
    if (IsEmpty(s) == 1) {
        printf("Stack Is Empty!");
        return -1;
    } else {
        topNode = s->Next;
        s->Next = topNode->Next;
        data = topNode->Data;
        free(topNode);
        return data;
    }
}