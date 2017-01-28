//
//  main.c
//  二叉搜索树的后序遍历
//
//  Created by LZhenHong on 2017/1/28.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

bool verifySquenceOfBST(int *data, int count) {
    if (!data || count <= 0) { return false; }
    
    int root = data[count - 1];
    
    int i = 0;
    for (; i < count - 1; ++i) {
        if (data[i] > root) { break; }
    }
    
    int j = i;
    for (; j < count - 1; ++j) {
        if (data[j] < root) { return false; }
    }
    
    bool left = true;
    if (i > 0) {
        left = verifySquenceOfBST(data, i);
    }
    
    bool right = true;
    if (j < count - 1) {
        right = verifySquenceOfBST(data + i, count - i - 1);
    }
    
    return (left && right);
}

int main(int argc, const char * argv[]) {
    int seq[7] = {5, 7, 6, 9, 11, 10, 8};
    printf("%s\n", verifySquenceOfBST(seq, 7) ? "True" : "False");
    
    int seq0[4] = {7, 4, 6, 5};
    printf("%s\n", verifySquenceOfBST(seq0, 4) ? "True" : "False");
    
    int seq1[4] = {11, 10, 8, 5};
    printf("%s\n", verifySquenceOfBST(seq1, 4) ? "True" : "False");
    
    int seq2[3] = {5, 6, 8};
    printf("%s\n", verifySquenceOfBST(seq2, 3) ? "True" : "False");
    
    return 0;
}
