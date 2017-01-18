//
//  main.c
//  数值的整数次方
//
//  Created by LZhenHong on 2017/1/18.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>

// 这里主要是考虑到给种情况：
// 4 ^ 5
// 4 ^ (-3)
// 5 ^ 0
// (-4) ^ 5
// (-4) ^ (-3)
// (-6) ^ 0
// 0 ^ 0
// 0 ^ 1
// 0 ^ (-3)

// 用快速的方式求次方，但是只考虑指数是正数的情况
double power(double base, unsigned int exponent) {
    if (exponent == 0) { return 1; }
    
    if (exponent == 1) { return base; }
    
    double res = power(base, exponent >> 1);
    res *= res;
    if (exponent & 0x1) {
        res *= base;
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
    printf("%.0lf\n", power(3, 3));
    
    return 0;
}
