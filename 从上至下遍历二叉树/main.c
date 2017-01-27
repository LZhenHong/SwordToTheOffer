//
//  main.c
//  从上至下遍历二叉树
//
//  Created by LZhenHong on 2017/1/27.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 这里的情况与图的宽度遍历相似，可以说是图的宽度遍历的简化
// 这里使用队列来保存每个遍历的二叉树节点

typedef struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
} BinaryTreeNode;

// 这里简化了队列的操作
typedef struct {
    BinaryTreeNode *data[100];
    int head;
    int tail;
} BinaryTreeNodeQueue;

void enQueue(BinaryTreeNodeQueue *queue, BinaryTreeNode *node) {
    if (!queue || queue->tail >= 100 || !node) { return; }
    
    queue->data[queue->tail++] = node;
}

BinaryTreeNode *outQueue(BinaryTreeNodeQueue *queue) {
    // 对错误处理不完整
    if (!queue || queue->head >= queue->tail) { return NULL; }
    
    return queue->data[queue->head++];
}

bool isQueueEmpty(BinaryTreeNodeQueue *queue) {
    if (!queue) { return true; }
    
    return !(queue->head < queue->tail && queue->tail < 100);
}

void preLiteralTree(BinaryTreeNode *tree) {
    if (!tree) { return; }
    
    printf("%d ", tree->data);
    preLiteralTree(tree->leftChild);
    preLiteralTree(tree->rightChild);
}

void destoryTree(BinaryTreeNode *tree) {
    if (!tree) { return; }
    
    destoryTree(tree->leftChild);
    destoryTree(tree->rightChild);
    free(tree);
}

BinaryTreeNode *createExampleTree1() {
    BinaryTreeNode *tree = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    tree->data = 0;
    
    BinaryTreeNode *node1 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node1->data = 1;
    tree->leftChild = node1;
    
    BinaryTreeNode *node2 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node2->data = 2;
    tree->rightChild = node2;
    
    BinaryTreeNode *node3 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node3->data = 3;
    node3->leftChild = NULL;
    node3->rightChild = NULL;
    node1->leftChild = node3;
    
    BinaryTreeNode *node4 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node4->data = 4;
    node4->leftChild = NULL;
    node4->rightChild = NULL;
    node1->rightChild = node4;
    
    BinaryTreeNode *node5 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node5->data = 5;
    node5->leftChild = NULL;
    node5->rightChild = NULL;
    node2->leftChild = node5;
    
    BinaryTreeNode *node6 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node6->data = 6;
    node6->leftChild = NULL;
    node6->rightChild = NULL;
    node2->rightChild = node6;
    
    return tree;
}

void literalBinaryTreeFromTop(BinaryTreeNode *tree) {
    BinaryTreeNodeQueue *queue = (BinaryTreeNodeQueue *)malloc(sizeof(BinaryTreeNodeQueue));
    queue->head = 0;
    queue->tail = 0;
    
    enQueue(queue, tree);
    
    BinaryTreeNode *node = NULL;
    while (!isQueueEmpty(queue)) {
        node = outQueue(queue);
        printf("%d ", node->data);
        if (node->leftChild) { enQueue(queue, node->leftChild); }
        if (node->rightChild) { enQueue(queue, node->rightChild); }
    }
    printf("\n");
    
    free(queue);
}

int main(int argc, const char * argv[]) {
    BinaryTreeNode *tree = createExampleTree1();
    
//    preLiteralTree(tree);
    literalBinaryTreeFromTop(tree);
    
    destoryTree(tree);
    
    return 0;
}
