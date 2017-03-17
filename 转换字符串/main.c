//
//  main.c
//  转换字符串
//
//  Created by LZhenHong on 2017/3/16.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VALUE 100

// www.zhidao.baidu.com -> com/baidu/zhidao/www
typedef struct {
    char data[MAX_VALUE];
    int top;
} Stack;

bool isStackFull(Stack *s) {
    if (!s) {
        return false;
    }
    return s->top >= MAX_VALUE;
}

bool isStackEmpty(Stack *s) {
    if (!s) {
        return false;
    }
    return s->top == 0;
}

void push(Stack *s, char c) {
    if (!s || isStackFull(s)) { return; }
    
    s->data[s->top++] = c;
}

char pop(Stack *s) {
    if (!s || isStackEmpty(s)) {
        return '`';
    }
    return s->data[--s->top];
}

void reverseString(char *str, long len) {
    if (!str || !len) { return; }
    
    char temp;
    if (len >= 2) {
        temp = *str;
        *str = *(str + len - 1);
        *(str + len - 1) = temp;
        reverseString(str + 1, len - 2);
    }
}

int main(int argc, const char * argv[]) {
    
    char str[] = "www.zhidao.baidu.com";
//    printf("char * size: %ld\n\n", sizeof(str));
    
    Stack *s1 = (Stack *)malloc(sizeof(Stack));
    s1->top = 0;
    
    Stack *s2= (Stack *)malloc(sizeof(Stack));
    s2->top = 0;
    
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == '.') {
            while (!isStackEmpty(s1)) {
                push(s2, pop(s1));
            }
            push(s2, '/');
        } else {
            push(s1, str[i]);
        }
    }
    
    while (!isStackEmpty(s1)) {
        push(s2, pop(s1));
    }
    
    int i = 0;
    char *newStr = (char *)malloc(sizeof(str) * sizeof(char));
    while (!isStackEmpty(s2) && i < strlen(str)) {
        newStr[i] = pop(s2);
        ++i;
    }
    newStr[i] = '\0';
    printf("%s\n\n", newStr);
    
    free(s1);
    free(s2);
    free(newStr);
    
    
    reverseString(str, strlen(str));
    int index = 0;
    int j = 0;
    for (; j < strlen(str); ++j) {
        if (str[j] == '.') {
            str[j] = '/';
            reverseString(str + index, j - index);
            index = j + 1;
        }
    }
    reverseString(str + index, j - index);
    printf("%s\n", str);
    
    return 0;
}
