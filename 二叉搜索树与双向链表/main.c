//
//  main.c
//  二叉搜索树与双向链表
//
//  Created by LZhenHong on 2017/2/2.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
} BinaryTreeNode;

void convertBinaryTreeToLinkedList(BinaryTreeNode *tree, BinaryTreeNode **lastNode) {
    if (!tree) { return; }
    
    BinaryTreeNode *currentNode = tree;
    
    if (currentNode->leftChild) {
        convertBinaryTreeToLinkedList(currentNode->leftChild, lastNode);
    }
    
    currentNode->leftChild = *lastNode;
    if (*lastNode) {
        (*lastNode)->rightChild = currentNode;
    }
    
    *lastNode = currentNode;
    
    if (currentNode->rightChild) {
        convertBinaryTreeToLinkedList(tree->rightChild, lastNode);
    }
}

BinaryTreeNode *convert(BinaryTreeNode *tree) {
    BinaryTreeNode *lastNode = NULL;
    convertBinaryTreeToLinkedList(tree, &lastNode);

    if (!lastNode) { return NULL; }
    
    BinaryTreeNode *headNode = lastNode;
    while (headNode->leftChild) {
        headNode = headNode->leftChild;
    }
    
    return headNode;
}

BinaryTreeNode *createExampleBinarySearchTree() {
    BinaryTreeNode *tree10 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    tree10->data = 10;
    
    BinaryTreeNode *tree6 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    tree6->data = 6;
    tree10->leftChild = tree6;
    
    BinaryTreeNode *tree4 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    tree4->data = 4;
    tree4->leftChild = NULL;
    tree4->rightChild = NULL;
    tree6->leftChild = tree4;
    
    BinaryTreeNode *tree8 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    tree8->data = 8;
    tree8->leftChild = NULL;
    tree8->rightChild = NULL;
    tree6->rightChild = tree8;
    
    BinaryTreeNode *tree14 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    tree14->data = 14;
    tree10->rightChild = tree14;
    
    BinaryTreeNode *tree12 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    tree12->data = 12;
    tree12->leftChild = NULL;
    tree12->rightChild = NULL;
    tree14->leftChild = tree12;
    
    BinaryTreeNode *tree16 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    tree16->data = 16;
    tree16->leftChild = NULL;
    tree16->rightChild = NULL;
    tree14->rightChild = tree16;
    
    return tree10;
}

BinaryTreeNode *createExampleBinarySearchTree1() {
    BinaryTreeNode *node6 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node6->data = 6;
    node6->rightChild = NULL;
    
    BinaryTreeNode *node5 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node5->data = 5;
    node5->rightChild = NULL;
    node6->leftChild = node5;
    
    BinaryTreeNode *node4 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node4->data = 4;
    node4->leftChild = NULL;
    node4->rightChild = NULL;
    node5->leftChild = node4;
    
    return node6;
}

BinaryTreeNode *createExampleBinarySearchTree2() {
    BinaryTreeNode *node6 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node6->data = 6;
    node6->leftChild = NULL;
    
    BinaryTreeNode *node7 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node7->data = 7;
    node7->leftChild = NULL;
    node6->rightChild = node7;
    
    BinaryTreeNode *node8 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node8->data = 8;
    node8->leftChild = NULL;
    node8->rightChild = NULL;
    node7->rightChild = node8;
    
    return node6;
}

int main(int argc, const char * argv[]) {
//    BinaryTreeNode *tree = createExampleBinarySearchTree();
//    BinaryTreeNode *tree = createExampleBinarySearchTree1();
    BinaryTreeNode *tree = createExampleBinarySearchTree2();
    
    BinaryTreeNode *headNode = convert(tree);
    
    while (headNode) {
        printf("%d ", headNode->data);
        headNode = headNode->rightChild;
    }
    printf("\n");
    
    return 0;
}
