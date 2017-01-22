//
//  main.c
//  合并两个排序的链表
//
//  Created by LZhenHong on 2017/1/22.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} ListNode;

ListNode *createOddNumberList() {
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->data = 0;
    head->next = NULL;
    
    ListNode *p = head;
    
    int nums[5] = {1, 2, 3, 4, 5};
    
    for (int i = 0; i < 5; ++i) {
        ListNode *n = (ListNode *)malloc(sizeof(ListNode));
        n->data = nums[i];
        n->next = NULL;
        p->next = n;
        p = n;
        ++head->data;
    }
    
    return head;
}

ListNode *createEvenNumberList() {
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->data = 0;
    head->next = NULL;
    
    ListNode *p = head;
    
    int nums[5] = {1, 2, 3, 7, 8};
    
    for (int i = 0; i < 5; ++i) {
        ListNode *n = (ListNode *)malloc(sizeof(ListNode));
        n->data = nums[i];
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

ListNode *mergeTwoOrderedList(ListNode *head1, ListNode *head2) {
    if (!head1) {
        return head2;
    } else if (!head2) {
        return head1;
    }
    
    ListNode *newHead = (ListNode *)malloc(sizeof(ListNode));
    newHead->data = head1->data + head2->data;
    
    ListNode *p = head1->next;
    ListNode *q = head2->next;
    ListNode *k = newHead;
    
    while (p && q) {
        if (p->data > q->data) {
            k->next = q;
            q = q->next;
        } else {
            k->next = p;
            p = p->next;
        }
        k = k->next;
    }
    
    if (p && !q) {
        k->next = p;
    } else if (!p && q) {
        k->next = q;
    }
    
    return newHead;
}

// 这里的递归实现没有考虑到链表的头节点
ListNode *mergeTwoList(ListNode *head1, ListNode *head2) {
    if (!head1) {
        return head2;
    } else if (!head2) {
        return head1;
    }
    
    ListNode *n = NULL;
    
    if (head1->data > head2->data) {
        n = head2;
        mergeTwoList(head1, head2->next);
    } else {
        n = head1;
        mergeTwoList(head1->next, head2);
    }
    
    return n;
}

int main(int argc, const char * argv[]) {
    ListNode *oddHead = createOddNumberList();
    ListNode *evenHead = createEvenNumberList();
    
    ListNode *newHead = mergeTwoOrderedList(oddHead, evenHead);
    ListNode *n = newHead->next;
    
    while (n) {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
    
    free(oddHead);
    free(evenHead);
    destoryList(newHead);
    
    return 0;
}
