// Created by wlk on 2019/6/30 17:14.
#include <stdio.h>
#include "datastructure/LinkedList.h"

/*题目：打印两个有序链表的公共部分
 * 解析：如果head1的值小于head2，则head1向下移动
 *       如果head1的值大于head2,则head2向下移动
 *       如果相等，则打印这个值，并将head1,head2都往下移动
 *       当head1，head2任何一个为空时，整个过程停止*/

void printCommonPart(LinkedList l1, LinkedList l2) {
    PtrNode head1 = l1->Head;
    PtrNode head2 = l2->Head;
    while (head1 != NULL && head2 != NULL) {
        if (head1->Data < head2->Data) {
            head1 = head1->Next;
        } else if (head1->Data > head2->Data) {
            head2 = head2->Next;
        } else {
            printf("%d ", head1->Data);
            head1 = head1->Next;
            head2 = head2->Next;
        }
    }
}

int main() {

    LinkedList l1 = Init();
    AddLast(l1, 1);
    AddLast(l1, 2);
    AddLast(l1, 3);
    AddLast(l1, 4);
    AddLast(l1, 5);
    LinkedList l2 = Init();
    AddLast(l2, 1);
    AddLast(l2, 3);
    AddLast(l2, 5);

    printCommonPart(l1, l2);


    return 0;
}