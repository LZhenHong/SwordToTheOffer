//
//  main.c
//  在 O(1) 时间删除链表节点
//
//  Created by LZhenHong on 2017/1/19.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// 常规思路：删除链表的节点，我们通常需要找到需要被删除的节点的前一个节点，单向链表只有从头节点开始寻找，这样花费的时间就是 O(N)
// O(1) 的思路：我们这里已经知道要删除的节点，这样我们可以很容易知道被删除节点的下一个节点，我们将删除节点的下一个节点的值复制到要删除的节点上，再将下一个节点删除，这样就能达到删除需要删除的节点的效果

typedef struct node {
    int data;
    struct node *next;
} ListNode;

void deleteListNode(ListNode *head, ListNode *deletingNode) {
    if (!head || !deletingNode) { return; }
    
    if (!deletingNode->next) {
        ListNode *p = head;
        while (p->next->next) { p = p->next; }
        free(p->next);
        p->next = NULL;
    } else {
        ListNode *n = deletingNode->next;
        deletingNode->data = n->data;
        deletingNode->next = n->next;
        free(n);
        n = NULL;
    }
    --head->data;
}

ListNode *createExampleList() {
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->next = NULL;
    head->data = 0;
    
    ListNode *p = head;
    for (int i = 0; i < 10; ++i) {
        ListNode *n = (ListNode *)malloc(sizeof(ListNode));
        n->data = i;
        n->next = NULL;
        p->next = n;
        p = n;
        ++head->data;
    }
    
    return head;
}

void destoryList(ListNode *head) {
    if (!head) { return; }
    
    ListNode *p = head;
    ListNode *q = head->next;
    while (p->next) {
        free(p);
        p = q;
        q = q->next;
    }
    free(p);
}

int main(int argc, const char * argv[]) {
    ListNode *head = createExampleList();
    
    ListNode *n = head->next->next->next;
    
    // 删除尾节点
//    ListNode *n = head->next;
//    while (n->next) { n = n->next; }
    
    // 删除头节点后面的节点
//    ListNode *n = head->next;
    
    deleteListNode(head, n);
    
    n = head->next;
    while (n) {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
    
    destoryList(head);
    
    
    // 删除只有一个节点的链表
//    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
//    head->data = 1;
//    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
//    node->data = 43;
//    head->next = node;
//    
//    deleteListNode(head, node);
//    
//    ListNode *n = head;
//    while (n->next) {
//        printf("%d ", n->data);
//        n = n->next;
//    }
//    printf("\n");
//    
//    free(head);
    
    return 0;
}
