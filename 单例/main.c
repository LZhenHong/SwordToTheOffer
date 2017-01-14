//
//  main.c
//  单例
//
//  Created by LZhenHong on 2017/1/14.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef int * Singleton;

static Singleton *sharedSingleton = NULL;

pthread_mutex_t singleton_lock = PTHREAD_MUTEX_INITIALIZER;

// 两次判断
Singleton *getSingleton() {
    // 如果没有这一层判断的话
    // 那么每次获取单例都会加锁，如果此时单例已经创建好，就没必要再加锁，加锁会造成资源浪费。
    if (sharedSingleton == NULL) {
        pthread_mutex_lock(&singleton_lock);
        // 这一层判断避免在多线程的情况下，造成单例多次创建。
        // 线程 A 执行到 「创建单例」，但是此时单例没有创建好。
        // 线程 B 此时在「等待线程锁解除」。当线程 A 执行完之后，线程 B 获得执行时间，那么没有这一层判断，线程 B 会再次创建单例。此时这个单例不是线程安全的。
        if (sharedSingleton == NULL) {
            sharedSingleton = (Singleton *)calloc(1, sizeof(Singleton));
        }
        pthread_mutex_unlock(&singleton_lock);
    }
    return sharedSingleton;
}

int main(int argc, const char * argv[]) {
    return 0;
}
