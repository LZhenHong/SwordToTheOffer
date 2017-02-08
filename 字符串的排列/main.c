//
//  main.c
//  字符串的排列
//
//  Created by LZhenHong on 2017/2/3.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// 相关问题：
// 1. 8 个数，放在正方体的八个顶点，要求每个面的顶点的数字加起来相等。思路：先求出 8 个数的全排列，然后判断是否符合条件。
// 2. 八皇后问题。思路：定义一个长度为 8 的数组，数组中第 i 个数字表示位于第 i 行的皇后的列数。然后求出 0～7 的全排列，再去掉对角线的情况。

void permutation(char *string, char *stringBegin) {
    if (*stringBegin == '\0') {
        printf("%s\n", string);
    } else {
        for (char *ch = stringBegin; *ch != '\0'; ++ch) {
            char temp = *ch;
            *ch = *stringBegin;
            *stringBegin = temp;
            
            permutation(string, stringBegin + 1);
            
            temp = *ch;
            *ch = *stringBegin;
            *stringBegin = temp;
        }
    }
}

void stringPermutation(char *string) {
    if (!string) { return; }
    
    permutation(string, string);
}

int main(int argc, const char * argv[]) {
    char string[4] = "abc\0";
//    char string[2] = "a\0";
    
    stringPermutation(string);
    
    return 0;
}
