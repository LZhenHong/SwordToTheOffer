//
//  main.c
//  二维数组的查找
//
//  Created by LZhenHong on 2017/1/14.
//  Copyright © 2017年 lzh. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

// 首先选取数组中右上角的数字。
// 如果这个数字等于要查找的数字，查找过程结束；
// 如果该数字大于要查找的数字，剔除这个数字所在的列；
// 如果该数字小于要查找的数字，则剔除这个数字所在的行。

bool findNumber(int rows, int columns, int matrix[rows][columns], int target) {
    if (matrix == NULL || rows <= 0 || columns <= 0) { return false; }
    
    int r = 0, c = columns - 1;
    int n = 0;
    
    while (r < rows && columns >= 0) {
        n = matrix[r][c];
        if (n == target) {
            return true;
        } else if (n > target) {
            --c;
        } else {
            ++r;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    int matrix[4][4] = {
                        1, 2, 8, 9,
                        2, 4, 9, 12,
                        4, 7, 10, 13,
                        6, 8, 11, 15
                       };
    int rows = 4, columns = 4, target = 7;
    
    printf("%s\n", findNumber(rows, columns, matrix, target) ? "true" : "false");
    
    return 0;
}
