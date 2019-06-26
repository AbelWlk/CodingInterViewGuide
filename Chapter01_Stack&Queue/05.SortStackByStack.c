// Created by wlk on 2019/6/26 22:53.
#include <stdio.h>
#include "datastructure/Stack.h"

/*使用一个栈实现另一个栈的排序*/

void sortStackByStack(Stack *s) {
    Stack help = Init();
    while (IsEmpty(*s) == 0) {
        int cur = Pop(*s);
        while (IsEmpty(help) == 0 && (help->Next)->Data > cur) {
            Push(*s, Pop(help));
        }
    }
    while (IsEmpty(help) == 0) {
        Push(*s, Pop(help));
    }
}

int main() {

    Stack s = Init();
    Push(s, 5);
    Push(s, 4);
    Push(s, 1);
    Push(s, 3);
    Push(s, 2);

    sortStackByStack(&s);

    foreachStack(s);


    return 0;
}