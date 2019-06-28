// Created by wlk on 2019/6/27 21:39.
#include <stdio.h>
#include <string.h>
#include "datastructure/PetQueue.h"


PetNode initPetNode(char *type) {
    PetNode petNode = (PetNode) malloc(sizeof(struct Pet));
    petNode->Type = type;
    return petNode;
}

int main() {
    PetNode p = initPetNode("dog");
    PetNode p2 = initPetNode("cat");
    PetNode p3 = initPetNode("dog");
    PetNode p4 = initPetNode("dog");
    PetNode p5 = initPetNode("cat");
    PetNode p6 = initPetNode("dog");
    PetNode p7 = initPetNode("cat");

    PetQueue petQueue = Init();

    AddQ(petQueue, p);
    AddQ(petQueue, p2);
    AddQ(petQueue, p3);
    AddQ(petQueue, p4);
    AddQ(petQueue, p5);
    AddQ(petQueue, p6);
    AddQ(petQueue, p7);

    for (int i = 0; i < 7; ++i) {
        printf("%s\n", PollAll(petQueue));
    }


    return 0;
}