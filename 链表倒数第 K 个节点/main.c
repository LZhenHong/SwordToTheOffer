//
//  main.c
//  链表倒数第 K 个节点
//
//  Created by LZhenHong on 2017/1/20.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} ListNode;

// 利用两个指针，两个指针的距离是 k - 1，当第一个指针到链表尾节点的时候，第二个指针指向倒数第 k 个节点

ListNode *tailKthNode(ListNode *head, int k) {
    if (!head || k <= 0 || k > head->data) { return NULL; }
    
    ListNode *headNode = head->next;
    ListNode *tailNode = head->next;
    
    for (int i = k - 1; i > 0; --i) { headNode = headNode->next; }
    
    while (headNode->next) {
        headNode = headNode->next;
        tailNode = tailNode->next;
    }
    
    return tailNode;
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
    
    ListNode *n = tailKthNode(head, 3);
    
//    ListNode *n = tailKthNode(head, 10);
    
//    ListNode *n = tailKthNode(head, -1);
    
//    ListNode *n = tailKthNode(head, 0);
    
//    ListNode *n = tailKthNode(head, 11);
    
    if (n) {
        printf("%d\n", n->data);
    } else {
        printf("NULL\n");
    }
    
    destoryList(head);
    
    return 0;
}
