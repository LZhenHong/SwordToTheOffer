//
//  main.c
//  树的子结构
//
//  Created by LZhenHong on 2017/1/23.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
} BinaryTreeNode;

bool isTwoBinaryTreeEqual(BinaryTreeNode *tree1, BinaryTreeNode *tree2) {
    if (!tree2) { return true; }
    
    if (!tree1) { return false; }
    
    if (tree1->data == tree2->data) {
        return isTwoBinaryTreeEqual(tree1->leftChild, tree2->leftChild) &&
        isTwoBinaryTreeEqual(tree1->rightChild, tree2->rightChild);
    } else {
        return false;
    }
}

/// 第二个参数是否是第一个参数的子树
bool isSubTree(BinaryTreeNode *tree1, BinaryTreeNode *tree2) {
    if (!tree1 || !tree2) { return false; }
    
    bool result = false;
    if (tree1->data == tree2->data) {
        result = isTwoBinaryTreeEqual(tree1, tree2);
    }
    
    if (!result) {
        result = isSubTree(tree1->leftChild, tree2);
    }
    
    if (!result) {
        result = isSubTree(tree1->rightChild, tree2);
    }
    
    return result;
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
    tree->data = 2;
    
    BinaryTreeNode *node5 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node5->data = 5;
    node5->leftChild = NULL;
    node5->rightChild = NULL;
    tree->leftChild = node5;
    
    BinaryTreeNode *node6 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node6->data = 6;
    node6->leftChild = NULL;
    node6->rightChild = NULL;
    tree->rightChild = node6;
    
    return tree;
}

BinaryTreeNode *createExampleTree3() {
    BinaryTreeNode *tree = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    tree->data = 2;
    
    BinaryTreeNode *node5 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node5->data = 5;
    node5->leftChild = NULL;
    node5->rightChild = NULL;
    tree->leftChild = node5;
    
    BinaryTreeNode *node6 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node6->data = 5;
    node6->leftChild = NULL;
    node6->rightChild = NULL;
    tree->rightChild = node6;
    
    return tree;
}

BinaryTreeNode *createExampleTree4() {
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

BinaryTreeNode *createExampleTree5() {
    BinaryTreeNode *tree = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    tree->data = 2;
    tree->rightChild = NULL;
    
    BinaryTreeNode *node1 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node1->data = 3;
    node1->leftChild = NULL;
    node1->rightChild = NULL;
    tree->leftChild = node1;
    
    return tree;
}

BinaryTreeNode *createExampleTree6() {
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

BinaryTreeNode *createExampleTree7() {
    BinaryTreeNode *tree = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    tree->data = 2;
    tree->leftChild = NULL;
    
    BinaryTreeNode *node1 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node1->data = 3;
    node1->leftChild = NULL;
    node1->rightChild = NULL;
    tree->rightChild = node1;
    
    return tree;
}

BinaryTreeNode *createExampleTree8() {
    BinaryTreeNode *tree = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    tree->data = 0;
    tree->rightChild = NULL;
    
    BinaryTreeNode *node1 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node1->data = 1;
    node1->rightChild = NULL;
    tree->leftChild = node1;
    
    BinaryTreeNode *node2 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node2->data = 2;
    node2->leftChild = NULL;
    node1->leftChild = node2;
    
    BinaryTreeNode *node3 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node3->data = 3;
    node3->leftChild = NULL;
    node3->rightChild = NULL;
    node2->rightChild = node3;
    
    return tree;
}

int main(int argc, const char * argv[]) {
    BinaryTreeNode *tree1 = createExampleTree1();
    BinaryTreeNode *tree2 = createExampleTree2();
    BinaryTreeNode *tree3 = createExampleTree3();
    BinaryTreeNode *treeNULL = NULL;
    BinaryTreeNode *tree4 = createExampleTree4();
    BinaryTreeNode *tree5 = createExampleTree5();
    BinaryTreeNode *tree6 = createExampleTree6();
    BinaryTreeNode *tree7 = createExampleTree7();
    BinaryTreeNode *tree8 = createExampleTree8();
    
    printf("%s\n", isSubTree(tree1, tree2) ? "True" : "False");
    printf("%s\n", isSubTree(tree1, tree3) ? "True": "False");
    printf("%s\n", isSubTree(tree1, treeNULL) ? "True" : "False");
    printf("%s\n", isSubTree(tree4, tree5) ? "True" : "False");
    printf("%s\n", isSubTree(tree6, tree7) ? "True" : "False");
    printf("%s\n", isSubTree(tree8, tree7) ? "True" : "False");
    
    destoryTree(tree1);
    destoryTree(tree2);
    destoryTree(tree3);
    destoryTree(tree4);
    destoryTree(tree5);
    destoryTree(tree6);
    destoryTree(tree7);
    destoryTree(tree8);
    
    return 0;
}
