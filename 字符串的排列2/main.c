//
//  main.c
//  字符串的排列2
//
//  Created by LZhenHong on 2017/2/8.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>
#include <string.h>

// https://segmentfault.com/a/1190000002710424

// 这里还有一种递归的思路，在求 n 个字符的长度为 m 的组合时。
// 把 n 个字符分成两部分：第一个字符和其余的所有字符。
// 如果组合里包含第一个字符，则下一步在剩余的字符里选取 m - 1 个字符；
// 如果组合里不包含第一个字符，则下一步在剩余的 n - 1 字符里选择 m 个字符。

void stringPermutaion(char *string) {
    if (!string) { return; }
    
    int length = (int)strlen(string);
    int count = 1 << length;
    for (int i = 1; i < count; ++i) {
        for (int j = 0; j < length; ++j) {
            if (((i >> j) & 1) != 0) {
                printf("%c", *(string + j));
            }
        }
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    char string[6] = "abcdf\0";
    stringPermutaion(string);
    
    return 0;
}
