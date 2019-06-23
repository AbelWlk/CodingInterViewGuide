// Created by wlk on 2019/6/23 22:22.

#include <stdio.h>
#include "Stack/Stack.h"

/*仅用递归函数和栈基本操作来逆序一个栈*/

/*通过递归Pop栈底元素并返回*/
int getAndRemoveLastElement(Stack s) {
    int result = Pop(s);
    if (IsEmpty(s) == 1)//IsEmpty()'s return={1:true  0:false}
    {
        return result;
    } else {
        int last = getAndRemoveLastElement(s);
        Push(s, result);
        return last;
    }
}

/*逆序栈*/
void Reverse(Stack s) {
    if (IsEmpty(s) == 1) {
        return;
    }
    int i = getAndRemoveLastElement(s);
    Reverse(s);
    Push(s, i);
}

int main() {
    Stack s = Init();
    for (int i = 1; i < 10; i++) {
        Push(s, i);
    }
    foreachStack(s);
    Reverse(s);
    foreachStack(s);
    return 0;
}