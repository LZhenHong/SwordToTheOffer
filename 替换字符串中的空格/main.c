//
//  main.c
//  替换字符串中的空格
//
//  Created by LZhenHong on 2017/1/14.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replaceSpaceInString(char *str) {
    if (!str) { return NULL; }
    
    int length = (int)strlen(str);
    int i = 0, spaceNumber = 0;
    
    // 先从前向后遍历字符串，计算要替换的空格的个数
    for (; i < length; ++i) {
        if (str[i] == ' ') {
            ++spaceNumber;
        }
    }
    
    // 没有空格，返回原字符串
    if (!spaceNumber) { return str; }
    
    int charAddNumber = spaceNumber * 2;
    int totalLength = length + charAddNumber;
    
    // 扩展字符串成替换完之后的长度
    char *newString = (char *)malloc(sizeof(char) * (totalLength + 1));
    
    // 用两个指针，一个指向原字符串的尾部，一个指向扩展字符串的尾部
    char *p1 = str + length;
    char *p2 = newString + totalLength;
    
    // 从后向前遍历原字符串，拷贝至扩展的字符串，遇到空格替换成 %20
    while (length >= 0) {
        if (*p1 == ' ') {
            *p2 = '0';
            *(p2 - 1) = '2';
            *(p2 - 2) = '%';
            p2 -= 3;
            --p1;
        } else {
            *p2 = *p1;
            --p1;
            --p2;
        }
        --length;
    }
    return newString;
}

int main(int argc, const char * argv[]) {
    char *string = "We are so happy.";
//    char *string = NULL;
//    char *string = "";
//    char *string = "     ";
    
    printf("%s\n", replaceSpaceInString(string));
    
    return 0;
}
