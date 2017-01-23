//
//  main.c
//  二叉树的镜像
//
//  Created by LZhenHong on 2017/1/23.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
} BinaryTreeNode;

void flipBinaryTree(BinaryTreeNode *tree) {
    if (!tree) { return; }
    
    flipBinaryTree(tree->leftChild);
    flipBinaryTree(tree->rightChild);
    
    BinaryTreeNode *node = tree->leftChild;
    tree->leftChild = tree->rightChild;
    tree->rightChild = node;
}

void preLiteralTree(BinaryTreeNode *tree) {
    if (!tree) { return; }
    
    printf("%d ", tree->data);
    preLiteralTree(tree->leftChild);
    preLiteralTree(tree->rightChild);
}

void midLiteralTree(BinaryTreeNode *tree) {
    if (!tree) { return; }
    
    preLiteralTree(tree->leftChild);
    printf("%d ", tree->data);
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

BinaryTreeNode *createExampleTree2() {
    BinaryTreeNode *tree = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    tree->data = 0;
    tree->rightChild = NULL;
    
    BinaryTreeNode *node1 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node1->data = 1;
    node1->rightChild = NULL;
    tree->leftChild = node1;
    
    BinaryTreeNode *node2 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node2->data = 2;
    node2->rightChild = NULL;
    node1->leftChild = node2;
    
    BinaryTreeNode *node3 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node3->data = 3;
    node3->leftChild = NULL;
    node3->rightChild = NULL;
    node2->leftChild = node3;
    
    return tree;
}

BinaryTreeNode *createExampleTree3() {
    BinaryTreeNode *tree = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    tree->data = 0;
    tree->leftChild = NULL;
    
    BinaryTreeNode *node1 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node1->data = 1;
    node1->leftChild = NULL;
    tree->rightChild = node1;
    
    BinaryTreeNode *node2 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node2->data = 2;
    node2->leftChild = NULL;
    node1->rightChild = node2;
    
    BinaryTreeNode *node3 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node3->data = 3;
    node3->leftChild = NULL;
    node3->rightChild = NULL;
    node2->rightChild = node3;
    
    return tree;
}

BinaryTreeNode *createExampleTree4() {
    BinaryTreeNode *tree = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    tree->data = 0;
    tree->leftChild = NULL;
    tree->rightChild = NULL;
    
    return tree;
}

int main(int argc, const char * argv[]) {
    BinaryTreeNode *tree1 = createExampleTree1();
    flipBinaryTree(tree1);
    preLiteralTree(tree1);
    printf("\n");
    destoryTree(tree1);
    
    BinaryTreeNode *tree2 = createExampleTree2();
    flipBinaryTree(tree2);
    midLiteralTree(tree2);
    printf("\n");
    destoryTree(tree2);
    
    BinaryTreeNode *tree3 = createExampleTree3();
    flipBinaryTree(tree3);
    midLiteralTree(tree3);
    printf("\n");
    destoryTree(tree3);
    
    BinaryTreeNode *tree4 = createExampleTree4();
    flipBinaryTree(tree4);
    midLiteralTree(tree4);
    printf("\n");
    destoryTree(tree4);
    
    return 0;
}
