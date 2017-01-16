//
//  main.c
//  快速排序
//
//  Created by LZhenHong on 2017/1/16.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>

// 快排的时间复杂度：
// 平均：O(NlgN)
// 最差：O(N^2) 在最坏的情况下，待排序的序列为正序或者逆序，每次划分只得到一个比上一次划分少一个记录的子序列，注意另一个为空。

void quickSort(int *data, int count) {
    if (count < 2) { return; }
    
    int left = 0;
    int right = count - 1;
    
    int temp = 0;
    while (left < right) {
        while (data[right] >= data[0] && left < right) { --right; }
        while (data[left] < data[0] && left < right) { ++left; }
        
        if (left < right) {
            temp = data[left];
            data[left] = data[right];
            data[right] = temp;
        }
    }
    
    temp = data[0];
    data[0] = data[left];
    data[left] = temp;
    
    quickSort(data, left);
    quickSort(data + left + 1, count - left - 1);
}

int main(int argc, const char * argv[]) {
    int count = 8;
    int data[8] = {7, 6, 5, 4, 3, 2, 1, 0};
    
    quickSort(data, count);
    
    for (int i = 0; i < count; ++i) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    return 0;
}
