#include<stdio.h>

const int nrow = 5;
const int ncol = 4;

// result indices
int res_row = -1, res_col = -1;

int search(int a[nrow][ncol], int find) {
    int col_lb = ncol, row_lb = nrow;
    int low, high;

    // calculating first column lower bound 
    low = 0;
    high = nrow;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(find <= a[mid][0]) {
            row_lb = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    row_lb -= 1;
    
    // calculating first row lower bound
    low = 0;
    high = ncol;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(find <= a[0][mid]) {
            col_lb = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    col_lb -= 1;

    printf(" %d %d", row_lb, col_lb);
    // finding element in lower bound column
    low = 0;
    high = row_lb;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(find == a[mid][col_lb]) {
            res_row = mid;
            res_col = col_lb;
            return 1;
        } 
        else if(find < a[mid][col_lb]) 
            high = mid - 1;
        else 
            low = mid + 1;
    }

    // finding element in lower bound row
    low = 0;
    high = col_lb;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(find == a[row_lb][mid]) {
            res_row = row_lb;
            res_col = mid;
            return 1;
        }
        else if(find < a[row_lb][mid])
            high = mid - 1;
        else 
            low = mid + 1;
    }
    return 0;
}

int main() {
    // this is a special type of sorted array
    // because the array is not only sorted 
    // row-wise but also column-wise 
    // Max Time Complexity = O(4*log(n))
    int a[nrow][ncol] = {{1,  2,  5,  10}, 
                         {3,  4,  7,  12}, 
                         {6,  8,  9,  14}, 
                         {11, 13, 15, 16},
                         {17, 18, 19, 20}};

    int find;
    scanf(" %d", &find);

    if(search(a, find))
        printf("Index: %d %d\n", res_row, res_col);
    else 
        printf("Element not found\n");
    return 0;
}

int binary_search_2d(int matrix[4][4], int rows, int cols, int target) {
    int left = 0, right = rows * cols - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int mid_row = mid / cols, mid_col = mid % cols;
        int mid_val = matrix[mid_row][mid_col];
        if (mid_val == target) {
            return 1;
        } else if (mid_val < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}

int main() {
    int matrix[4][4] = {{ 1,  3,  5,  2}, 
                        { 7,  9, 11, 21}, 
                        {13, 15, 17, 27}};
    int rows = 4, cols = 4;
    int target ;
    scanf("%d",&target);
    int found = binary_search_2d(matrix, rows, cols, target);
    if (found) {
        printf("Found %d in the 2D array\n", target);
    } else {
        printf("Did not find %d in the 2D array\n", target);
    }
    return 0;
}