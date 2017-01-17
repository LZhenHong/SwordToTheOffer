//
//  main.c
//  归并排序
//
//  Created by LZhenHong on 2017/1/17.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>

void mSort(int *data, int count) {
    int tempArray[count];
    int middle = count / 2;
    int i = 0, j = middle, k = 0;
    
    while ((i < middle) && (j < count)) {
        if (data[i] > data[j]) {
            tempArray[k++] = data[j++];
        } else {
            tempArray[k++] = data[i++];
        }
    }
    
    if (i < middle) {
        while (i < middle) { tempArray[k++] = data[i++]; }
    }
    if (j < count) {
        while (j < count) { tempArray[k++] = data[j++]; }
    }
    
    for (int q = 0; q < count; ++q) {
        data[q] = tempArray[q];
    }
}

// 时间复杂度：O(NlogN)
void mergeSort(int *data, int count) {
    if (!data || count <= 1) { return; }
    
    int mid = count / 2;
    if (mid > 0) {
        mergeSort(data, mid);
        mergeSort(data + mid, count - mid);
        mSort(data, count);
    }
}

int main(int argc, const char * argv[]) {
//    int data[1] = {2};
    
//    int data[5] = {1, 2, 3, 4, 5};
    
//    int data[5] = {1, 2, 2, 4, 5};
    
//    int data[5] = {5, 4, 3, 2, 1};
    
    int data[5] = {1, 1, 1, 1, 0};
    
//    int data[5] = {2, 4, 1, 5, 6};
    
//    int count = 1;
    int count = 5;
    
    mergeSort(data, count);
    for (int i = 0; i < count; ++i) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    return 0;
}
