// Created by wlk on 2019/6/27 22:25.

#include "PetQueue.h"

PetQueue Init() {//初始化
    Queue dog = (Queue) malloc(sizeof(struct QNode));
    dog->Rear = dog->Front = NULL;
    Queue cat = (Queue) malloc(sizeof(struct QNode));
    cat->Rear = cat->Front = NULL;
    PetQueue pet = (PetQueue) malloc(sizeof(struct PetNode));
    pet->Dog = dog;
    pet->Cat = cat;
    return pet;
}

int IsEmpty(Queue q) {
    return (q->Front == NULL);
}

int IsPetEmpty(PetQueue petQueue) {
    return IsEmpty(petQueue->Dog) && IsEmpty(petQueue->Cat);
}

int IsDogEmpty(PetQueue petQueue) {
    return IsEmpty(petQueue->Dog);
}

int IsCatEmpty(PetQueue petQueue) {
    return IsEmpty(petQueue->Cat);
}

void AddQ(PetQueue petQueue, PetNode petNode) {
    petNode->Count = Count++;
    Queue dog = petQueue->Dog;
    Queue cat = petQueue->Cat;
    if (strcmp("dog", petNode->Type) == 0) { //判断新节点类型，按类别存储
        if (IsEmpty(dog) == 1) {//队列为空
            dog->Front = dog->Rear = petNode;
        } else {//队列不为空
            dog->Rear->Next = petNode;
            dog->Rear = petNode;
        }
    } else if (strcmp("cat", petNode->Type) == 0) {
        if (IsEmpty(cat) == 1) {
            cat->Front = cat->Rear = petNode;
        } else {
            cat->Rear->Next = petNode;
            cat->Rear = petNode;
        }
    } else {
        printf("err,not dog or cat!");
    }
}


char *Poll(Queue q) {
    PetNode topNode;
    char *data;
    if (IsEmpty(q) == 1) {
        printf("Queue Is Empty!");
        return NULL;
    } else {
        topNode = q->Front;
        if (q->Front == q->Rear) //如果队列只有一个元素
        {
            q->Front = q->Rear = NULL;
        } else {
            q->Front = q->Front->Next;
        }
        data = topNode->Type;
        free(topNode);
        return data;
    }
}

char *PollAll(PetQueue petQueue) {
    Queue dog = petQueue->Dog;
    Queue cat = petQueue->Cat;
    if (IsEmpty(dog) != 1 && IsEmpty(cat) != 1) {//猫狗都不为空时
        if (dog->Front->Count < cat->Front->Count) {//比较时间戳，越小说明进入越早，需要优先弹出
            return Poll(dog);
        } else {
            return Poll(cat);
        }
    } else if (IsEmpty(dog) != 1) {//当不满足都不为空条件时，判断不为空的队列并弹出
        return Poll(dog);
    } else if (IsEmpty(cat) != 1) {
        return Poll(cat);
    } else {
        return "err,PetQueue is empty!";
    }
}

char *PollDog(PetQueue petQueue) {
    if (IsDogEmpty(petQueue) != 1) {
        return Poll(petQueue->Dog);
    } else {
        return "Dog Queue is empty!";
    }
}

char *PollCat(PetQueue petQueue) {
    if (IsCatEmpty(petQueue) != 1) {
        return Poll(petQueue->Cat);
    } else {
        return "Cat Queue is empty!";
    }
}

