//
//  main.c
//  数组中出现次数超过一半的数字
//
//  Created by LZhenHong on 2017/2/13.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

// 思路 1: 先对数组排序，在 length ／ 2 的位置上一定是需要的数字。
// 思路 2: 快速排序的思想，随机选定一个数字，将比这个数字大的数字移动到选定的数字左边，大的移动到右边。如果这个数字在 length ／ 2 的位置上，这就是我们需要找的数字。如果不是，则就递归选定数字左边或者右边的数组。

static bool isError = false;

// 当数组不满足题目所给要求，没有做处理。
int moreThanAHalfNum(int *data, int length) {
    if (!data || !length) {
        isError = true;
        return 0;
    }
    
    int res = data[0];
    int count = 1;
    for (int i = 1; i < length; ++i) {
        if (count == 0) {
            res = data[i];
            ++count;
        } else if (res == data[i]) {
            ++count;
        } else {
            --count;
        }
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
//    int data[7] = {1, 2, 4, 3, 2, 2, 2};
//    int length = 7;
    
    int data[1] = {2};
    int length = 1;
    
    if (!isError) {
        printf("%d\n", moreThanAHalfNum(data, length));
    }
    
    return 0;
}
