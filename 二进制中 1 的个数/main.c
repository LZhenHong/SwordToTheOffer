//
//  main.c
//  二进制中 1 的个数
//
//  Created by LZhenHong on 2017/1/17.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>

// 相关题目：
// 1. 一条语句判断一个整数 n 是否为 2 的整数次方。2 的整数次方，以二进制的角度来看，就是只有一个位置上是 1。以这道题的第二种解法来看，如果 n & (n - 1) == 0，则表明只有位置上为 1，即这个数就是 2 的整数次方。如果 n & (n - 1) != 0，则这个数就不是 2 的整数次方。
// 2. 输入两个整数 m 和 n，需要改变 m 二进制几位数能得到 n。这里先将 m 与 n 进行「异或 ^」，这样两个整数的二进制位置不同的就会变成 1，这样再来计算 1 的个数就能得到需要改变的位数。

// 把一个整数减去 1 之后再和原来的整数作位与运算，得到的结果相当于是把整数的二进制表示中的最右边一个 1 变成 0。

// 不断将 1 👈 移动，来与参数进行 位与 运算
// 如果结果为 1，则这个位置上是 1；如果结果为 0，则这个位置是 0。
int numberOfOneInBinaryNormal(int n) {
    int count = 0;
    
    unsigned int flag = 1;
    while (flag) {
        if (n & flag) { ++count; }
        flag <<= 1;
    }
    
    return count;
}

// 二进制：1100 - 1 = 1011; 1011 & 1100 = 1000, 减少了一个 1，可以借此来判断 1 的个数。
int numberOfOneInBinaryExtra(int n) {
    int count = 0;
    
    while (n) {
        ++count;
        n &= (n - 1);
    }
    
    return count;
}

int main(int argc, const char * argv[]) {
    int n = 1;
    
//    int n = 0x7FFFFFFF;
    
//    int n = 0x80000000;
    
//    int n = 0xFFFFFFFF;
    
    printf("%d\n", numberOfOneInBinaryNormal(n));
    printf("%d\n", numberOfOneInBinaryExtra(n));
    
    return 0;
}
