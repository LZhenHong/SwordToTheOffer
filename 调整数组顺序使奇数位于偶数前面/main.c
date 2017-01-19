//
//  main.c
//  调整数组顺序使奇数位于偶数前面
//
//  Created by LZhenHong on 2017/1/19.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>

void sortArrayOddBeforeEven(int *data, int count) {
    if (!data || count < 2) { return; }
    
    int i = 0;
    int j = count - 1;
    
    int temp = 0;
    while (j > i) {
        while (j > i && !(data[j] & 0x1)) { --j; }
        while (j > i && (data[i] & 0x1)) { ++i; }
        
        if (j > i) {
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
}

int main(int argc, const char * argv[]) {
    int data[8] = {2, 4, 5, 6, 7, 1, 5, 7};
    
//    int data[8] = {2, 4, 6, 8, 1, 3, 5, 7};
    
//    int data[8] = {1, 3, 5, 7, 2, 4, 6, 8};
    
    int count = 8;
    
    sortArrayOddBeforeEven(data, count);
    
    for (int i = 0; i < count; ++i) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    return 0;
}
