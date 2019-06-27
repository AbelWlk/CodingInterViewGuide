// Created by wlk on 2019/6/27 21:39.
#include <stdio.h>
#include <string.h>
#include "datastructure/PetQueue.h"


void test(PetNode x) {
    x->Count = 15;
}

int main() {

    PetNode p = (PetNode) malloc(sizeof(struct Pet));
    strcpy(p->Type, "dog");
    test(p);
    printf("%s,,%d\n", p->Type, p->Count);
    return 0;
}