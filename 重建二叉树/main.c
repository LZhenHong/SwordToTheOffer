//
//  main.c
//  重建二叉树
//
//  Created by LZhenHong on 2017/1/15.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// 二叉搜索树的左子树的值都小于或者等于根节点，右子树的值都大于或者等于根节点

// 二叉树的特例：
// 1. 堆：堆分为最大堆和最小堆。在最大堆中根节点的值最大，最小堆中根节点的值最小。
// 2. 红黑树：树中的节点分为红／黑两种，并通过规则确保从根节点到叶节点的最长路径不超过最短路径的两倍。

typedef struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
} BinaryTreeNode;

BinaryTreeNode *createBinaryTreeCore(int *preorder, int *midorder, int count) {
    if (!preorder || !midorder || count <= 0) { return NULL; }
    
    int c = 0;
    for (int i = 0; i < count; ++i) {
        if (midorder[i] == preorder[0]) {
            break;
        } else {
            ++c;
        }
    }
    
    BinaryTreeNode *node = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node->data = preorder[0];
    node->leftChild = createBinaryTreeCore(preorder + 1, midorder, c);
    node->rightChild = createBinaryTreeCore(preorder + c + 1, midorder + c + 1, count - c - 1);
    
    return node;
}

void destoryTree(BinaryTreeNode *tree) {
    if (!tree) { return; }
    
    destoryTree(tree->leftChild);
    destoryTree(tree->rightChild);
    free(tree);
}

void preLog(BinaryTreeNode *tree) {
    if (!tree) { return; }
    
    printf("%d ", tree->data);
    preLog(tree->leftChild);
    preLog(tree->rightChild);
}

void midLog(BinaryTreeNode *tree) {
    if (!tree) { return; }
    
    midLog(tree->leftChild);
    printf("%d ", tree->data);
    midLog(tree->rightChild);
}

void sufLog(BinaryTreeNode *tree) {
    if (!tree) { return; }
    
    sufLog(tree->leftChild);
    sufLog(tree->rightChild);
    printf("%d ", tree->data);
}

// 输入前序遍历和中序遍历不匹配会出现问题
int main(int argc, const char * argv[]) {
    // 不完全二叉树
    int preorder[8] = {1, 2, 4, 7, 3, 5, 6, 8};
    int midorder[8] = {4, 7, 2, 1, 5, 3, 8, 6};
    int c = 8;
    
//    // 完全二叉树
//    int preorder[7] = {1, 2, 4, 5, 3, 6, 7};
//    int midorder[7] = {4, 2, 5, 1, 6, 3, 7};
//    int c = 7;
    
    // 所有节点只有左子树
//    int preorder[4] = {1, 2, 4, 7};
//    int midorder[4] = {7, 4, 2, 1};
//    int c = 4;
    
    // 所有节点只有右子树
//    int preorder[4] = {1, 2, 4, 7};
//    int midorder[4] = {1, 2, 4, 7};
//    int c = 4;
    
    // 只有一个节点
//    int preorder[1] = {1};
//    int midorder[1] = {1};
//    int c = 1;
    
    BinaryTreeNode *tree = createBinaryTreeCore(preorder, midorder, c);
    
    preLog(tree);
    printf("\n");
    
    midLog(tree);
    printf("\n");
    
    sufLog(tree);
    printf("\n");
    
    destoryTree(tree);
    
    return 0;
}
