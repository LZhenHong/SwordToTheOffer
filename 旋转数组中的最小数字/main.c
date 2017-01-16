//
//  main.c
//  旋转数组中的最小数字
//
//  Created by LZhenHong on 2017/1/16.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>

// 这个问题要注意两种特殊情况：
// 1. 没有旋转的数组
// 2. {1, 1, 1, 0, 1} 这样的数组，开头／中间／结尾都相同，这样的数组用顺序查找

// 二分查找的思想
int minimumNumberInRotationArray(int *data, int count) {
    if (!data || !count) {
        // 抛出异常
        return 0;
    }
    
    int min = 0;
    int max = count - 1;
    int mid = min;
    
    while (data[min] >= data[max]) {
        if (max - min == 1) {
            mid = max;
            break;
        }
        
        mid = (min + max) / 2;
        
        if (data[min] == data[mid] && data[mid] == data[max]) {
            int minimum = data[0];
            for (int i = 1; i < count; ++i) {
                if (data[i] < minimum) {
                    minimum = data[i];
                }
            }
            return minimum;
        }
        
        if (data[mid] >= data[min]) {
            min = mid;
        } else if (data[mid] < data[max]) {
            max = mid;
        }
    }
    
    return data[mid];
}

int main(int argc, const char * argv[]) {
    int data[5] = {1, 1, 1, 0, 1};
    
//    int data[5] = {1, 0, 1, 1, 1};
    
//    int data[5] = {3, 4, 5, 1, 2};
    
//    int data[5] = {1, 2, 3, 4, 5};
    
//    int data[1] = {2};
    
    int count = 5;
    
    printf("%d\n", minimumNumberInRotationArray(data, count));
    
    return 0;
}
