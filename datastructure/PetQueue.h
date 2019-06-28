// Created by wlk on 2019/6/27 22:25.

#ifndef CODINGINTERVIEWGUIDE_PETQUEUE_H
#define CODINGINTERVIEWGUIDE_PETQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int Count = 0;//作为时间戳，每次添加新节点都会增长

typedef struct Pet *PetNode;
struct Pet {            //宠物结构体 存放数据
    char *Type;
    int Count;
    PetNode Next;
};

struct QNode {          //队列节点 包含宠物节点
    PetNode Front, Rear;
};
typedef struct QNode *Queue;

struct PetNode {
    Queue Dog, Cat;
};
typedef struct PetNode *PetQueue;//宠物队列 包含队列节点

PetQueue Init();

int IsEmpty(Queue q);//判断队列是否为空

int IsPetEmpty(PetQueue petQueue);//判断猫狗队列是否为空

int IsDogEmpty(PetQueue petQueue);//判断猫狗队列是否为空

int IsCatEmpty(PetQueue petQueue);//判断猫狗队列是否为空

void AddQ(PetQueue petQueue, PetNode petNode);//添加一个宠物进队

char *Poll(Queue q);//队列顺序弹出

char *PollAll(PetQueue petQueue);//猫狗队列按照入队顺序出队，不分类型

char *PollDog(PetQueue petQueue);//只弹出狗

char *PollCat(PetQueue petQueue);//只弹出猫

#endif //CODINGINTERVIEWGUIDE_PETQUEUE_H
