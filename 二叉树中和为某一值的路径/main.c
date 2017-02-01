//
//  main.c
//  二叉树中和为某一值的路径
//
//  Created by LZhenHong on 2017/2/1.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
} BinaryTreeNode;

void destoryTree(BinaryTreeNode *tree) {
    if (!tree) { return; }
    
    destoryTree(tree->leftChild);
    destoryTree(tree->rightChild);
    free(tree);
}

typedef struct stack {
    BinaryTreeNode *data[100];
    int top;
} Stack;

void push(Stack *stack, BinaryTreeNode *node) {
    if (!stack) { return; }
    
    stack->data[stack->top++] = node;
}

BinaryTreeNode *pop(Stack *stack) {
    if (!stack || stack->top == 0) { return NULL; }
    
    return stack->data[stack->top--];
}

static int sum = 0;

void printPath(Stack *s) {
    BinaryTreeNode *node = NULL;
    for (int i = 0; i < s->top; ++i) {
        node = s->data[i];
        printf("%d ", node->data);
    }
    printf("\n");
}

void findPathInBinaryTree(BinaryTreeNode *tree, int target, Stack *s) {
    if (!tree) { return; }
    
    sum += tree->data;
    push(s, tree);
    
    if (!tree->leftChild && !tree->rightChild) {
        if (sum == target) {
            printPath(s);
        }
    }
    
    if (tree->leftChild) { findPathInBinaryTree(tree->leftChild, target, s); }
    
    if (tree->rightChild) { findPathInBinaryTree(tree->rightChild, target, s); }
    
    sum -= tree->data;
    pop(s);
}

BinaryTreeNode *createExampleTree() {
    BinaryTreeNode *tree = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    tree->data = 10;
    
    BinaryTreeNode *node1 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node1->data = 5;
    tree->leftChild = node1;
    
    BinaryTreeNode *node2 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node2->data = 12;
    node2->leftChild = NULL;
    node2->rightChild = NULL;
    tree->rightChild = node2;
    
    BinaryTreeNode *node3 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node3->data = 4;
    node3->leftChild = NULL;
    node3->rightChild = NULL;
    node1->leftChild = node3;
    
    BinaryTreeNode *node4 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node4->data = 7;
    node4->leftChild = NULL;
    node4->rightChild = NULL;
    node1->rightChild = node4;
    
    return tree;
}

int main(int argc, const char * argv[]) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = 0;
    BinaryTreeNode *tree = createExampleTree();
    int target = 22;
    
    findPathInBinaryTree(tree, target, s);
    
    free(s);
    destoryTree(tree);
    
    return 0;
}
