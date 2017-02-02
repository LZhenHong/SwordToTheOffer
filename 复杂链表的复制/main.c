//
//  main.c
//  复杂链表的复制
//
//  Created by LZhenHong on 2017/2/2.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *sibling;
} ComplexListNode;

ComplexListNode *createExampleList() {
    ComplexListNode *nodeA = (ComplexListNode *)malloc(sizeof(ComplexListNode));
    nodeA->data = 0;
    
    ComplexListNode *nodeB = (ComplexListNode *)malloc(sizeof(ComplexListNode));
    nodeB->data = 1;
    nodeA->next = nodeB;
    
    ComplexListNode *nodeC = (ComplexListNode *)malloc(sizeof(ComplexListNode));
    nodeC->data = 2;
    nodeB->next = nodeC;
    
    ComplexListNode *nodeD = (ComplexListNode *)malloc(sizeof(ComplexListNode));
    nodeD->data = 3;
    nodeC->next = nodeD;
    
    ComplexListNode *nodeE = (ComplexListNode *)malloc(sizeof(ComplexListNode));
    nodeE->data = 4;
    nodeE->next = NULL;
    nodeE->sibling = NULL;
    nodeD->next = nodeE;
    
    nodeA->sibling = nodeC;
    nodeB->sibling = nodeE;
    nodeC->sibling = NULL;
//    nodeC->sibling = nodeC;
//    nodeC->sibling = nodeA;
    nodeD->sibling = nodeB;
    
    return nodeA;
}

void destoryList(ComplexListNode *list) {
    if (!list) { return; }
    
    ComplexListNode *p = list;
    ComplexListNode *q = list->next;
    while (p->next) {
        free(p);
        p = q;
        q = q->next;
    }
    free(p);
}

void copyComplexListNode(ComplexListNode *list) {
    if (!list) { return; }
    
    ComplexListNode *n = list;
    while (n) {
        ComplexListNode *newNode = (ComplexListNode *)malloc(sizeof(ComplexListNode));
        newNode->data = n->data;
        newNode->sibling = NULL;
        
        newNode->next = n->next;
        n->next = newNode;
        n = n->next->next;
    }
}

void connectSiblingNode(ComplexListNode *list) {
    if (!list) { return; }
    
    ComplexListNode *firstNode = list;
    ComplexListNode *secondNode = list->next;
    while (firstNode && secondNode) {
        if (firstNode->sibling) {
            secondNode->sibling = firstNode->sibling->next;
        }
        firstNode = firstNode->next->next;
        secondNode = secondNode->next ? secondNode->next->next : NULL;
    }
}

ComplexListNode *reconnetComplexList(ComplexListNode *list) {
    if (!list) { return NULL; }
    
    ComplexListNode *firstNode = list;
    ComplexListNode *secondNode = list->next;
    ComplexListNode *newList = list->next;
    while (firstNode && secondNode) {
        firstNode->next = secondNode->next;
        secondNode->next = secondNode->next ? secondNode->next->next : NULL;
        
        firstNode = firstNode->next;
        secondNode = secondNode->next;
    }
    
    return newList;
}

int main(int argc, const char * argv[]) {
    ComplexListNode *list = createExampleList();
    
    copyComplexListNode(list);
    connectSiblingNode(list);
    ComplexListNode *copiedList = reconnetComplexList(list);
    
    ComplexListNode *n = copiedList;
    while (n) {
        printf("(%d, %d) ", n->data, n->sibling ? n->sibling->data : 0);
        n = n->next;
    }
    printf("\n");
    
    destoryList(list);
    destoryList(copiedList);
    
    return 0;
}
