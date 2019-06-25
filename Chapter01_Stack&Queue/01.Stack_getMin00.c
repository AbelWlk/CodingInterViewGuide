#include <stdio.h>
#include <stdlib.h>
#include "datastructure/Stack.h"
/*  
    题目：实现一个特殊的栈，在实现栈的基本功能的基础上，再返回栈中最小元素的操作
    要求：pop,push,getMin时间复杂度为O(1)
    可使用现成的栈结构
*/

/*--------------------题目要求的特殊栈实现------------------------*/
//初始化
void SpecialStackInit(Stack *stackData, Stack *stackMin) {
    *stackData = Init();
    *stackMin = Init();
}

int getMin(Stack stackMin) {
    if (IsEmpty(stackMin) == 1) {
        printf("Stack is empty!\n");
        return -1;
    }
    PtrNode tmp = stackMin->Next;
    return tmp->Data;
}

/*压栈
    规则是先将newNum压入stackData
    然后判断stackMin是否为空，如若空，将newNum压入；
    如果不为空，则比较newNum与stackMin栈顶元素哪一个更小，如果newNum更小或两者相等，则将newNum压入；如果stackMin栈顶元素更小，则什么也不做
 */
void SpecialPush(Stack stackData, Stack stackMin, int newNum) {
    if (IsEmpty(stackMin) == 1) {
        Push(stackMin, newNum);
    } else if (newNum <= getMin(stackMin)) {
        Push(stackMin, newNum);
    }
    Push(stackData, newNum);
}

/*弹栈
    先弹出stackData栈顶元素,记为value,然后比较stackMin栈顶元素个value哪一个最小
    因为stackMin栈顶元素是stackData的最小值，所以value只能大于或等于stackMin的栈顶元素
    当value==stackMin的栈顶元素时，stackMin弹出栈顶;
    当value>stackMin的栈顶元素时，stackMIn无操作
    返回value
 */
int SpecialPop(Stack stackData, Stack stackMin) {
    if (IsEmpty(stackData) == 1) {
        printf("Stack is empty!\n");
        return -1;
    }
    int value = Pop(stackData);
    if (value == getMin(stackMin)) {
        Pop(stackMin);
    }
    return value;
}

int main() {
    //对比01，压栈稍省时间，弹栈稍费时间
    Stack stackData, stackMin;
    SpecialStackInit(&stackData, &stackMin);
    SpecialPush(stackData, stackMin, 10);
    SpecialPush(stackData, stackMin, 9);
    SpecialPush(stackData, stackMin, 11);
    printf("%d\n", SpecialPop(stackData, stackMin));
    printf("%d\n", SpecialPop(stackData, stackMin));
    printf("%d\n", SpecialPop(stackData, stackMin));

    return 0;
}