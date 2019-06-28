// Created by wlk on 2019/6/27 22:25.

#ifndef CODINGINTERVIEWGUIDE_PETQUEUE_H
#define CODINGINTERVIEWGUIDE_PETQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int Count = 0;

typedef struct Pet *PetNode;
struct Pet {
    char *Type;
    int Count;
    PetNode Next;
};

struct QNode {
    PetNode Front, Rear;
};
typedef struct QNode *Queue;

struct PetNode {
    Queue Dog, Cat;
};
typedef struct PetNode *PetQueue;

PetQueue Init();

int IsEmpty(Queue q);

int IsPetEmpty(PetQueue petQueue);//判断猫狗队列是否为空

int IsDogEmpty(PetQueue petQueue);//判断猫狗队列是否为空

int IsCatEmpty(PetQueue petQueue);//判断猫狗队列是否为空

void AddQ(PetQueue petQueue, PetNode petNode);

char *Poll(Queue q);//队列顺序弹出

char *PollAll(PetQueue petQueue);//猫狗队列按照入队顺序出队，不分类型

char *PollDog(PetQueue petQueue);//只弹出狗

char *PollCat(PetQueue petQueue);//只弹出猫



#endif //CODINGINTERVIEWGUIDE_PETQUEUE_H
