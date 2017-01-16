//
//  main.c
//  斐波那契数列
//
//  Created by LZhenHong on 2017/1/16.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>

// 递归通常比较简洁
// 但是递归的缺点也很显著：
// 递归是函数调用函数，函数的调用时有时间和空间的消耗的：每一次函数调用，都需要在内存栈中分配空间以保存参数／返回地址及临时变量，而且往栈压入数据和弹出数据也需要时间。
// 递归还可能引起栈溢出，每个进程的栈容量是有限的，当递归的层级太多，就会超出栈的容量。


//  

long long FibonacciInRecursion(unsigned int n) {
    if (n <= 0) { return 0; }
    
    if (n == 1) { return 1; }
    
    return FibonacciInRecursion(n - 2) + FibonacciInRecursion(n - 1);
}

long long FibonacciInLoop(unsigned int n) {
    long long f1 = 0;
    if (n <= 0) { return f1; }
    
    long long f2 = 1;
    if (n == 1) { return f2; }
    
    long long temp = 0;
    for (unsigned int i = 1; i < n; ++i) {
        temp = f2;
        f2 += f1;
        f1 = temp;
    }
    
    return f2;
}

int main(int argc, const char * argv[]) {
    unsigned int n = 5;
    
    int re = (int)FibonacciInRecursion(n);
    int lp = (int)FibonacciInLoop(n);
    
    printf("%d - %d\n", re, lp);
    
    return 0;
}
