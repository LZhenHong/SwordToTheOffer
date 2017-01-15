//
//  main.c
//  倒序遍历链表
//
//  Created by LZhenHong on 2017/1/15.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// 链表操作要注意头节点和尾节点

// 单向链表只能从前向后遍历，但是输出需要是从后向前的，这与栈的特点很像

typedef int ElemType;

// 这里简化了栈操作
typedef struct stack {
    ElemType data[100];
    int top;
} Stack;

typedef struct node {
    ElemType data;
    struct node *next;
} ListNode;

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

void reverseLiteralListUsingStack(ListNode *list) {
    if (!list) { return; }
    
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = 0;
    
    ListNode *p = list;
    while (p) {
        s->data[s->top++] = p->data;
        p = p->next;
    }
    
    while (s->top > 0) {
        printf("%d ", s->data[--s->top]);
    }
    
    free(s);
}

// 在递归调用本质上就是一个栈结构，所以这个还可以用递归实现
void reverseLiteralListUsingRecursion(ListNode *list) {
    if (!list) { return; }
    
    reverseLiteralListUsingRecursion(list->next);
    printf("%d ", list->data);
}

int main(int argc, const char * argv[]) {
    ListNode *head = createExampleList();
    reverseLiteralListUsingStack(head->next); // 将头节点手动去掉
//    reverseLiteralListUsingRecursion(head->next);
    
//    ListNode *n = (ListNode *)malloc(sizeof(ListNode));
//    n->data = 12;
//    n->next = NULL;
//    reverseLiteralListUsingStack(n);
//    reverseLiteralListUsingRecursion(n);
    
    destoryList(head);
    
    return 0;
}
