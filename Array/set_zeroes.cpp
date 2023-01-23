#include<vector>
using namespace std;
// https://leetcode.com/problems/set-matrix-zeroes/
class Solution {
public:
    // space complexity = O(n + m)
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(n, -1);
        vector<int> col(m, -1);

        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(matrix[i][j] == 0){
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }

        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(row[i] == 0 || col[j] == 0)
                    matrix[i][j] = 0;
            }
        }
    }
    // space complexity = O(2)
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool first_row = false, first_col = false;

        for(int i=0; i<n; ++i){
            if(matrix[i][0] == 0){
                first_col = true;
                break;
            }
        }

        for(int j=0; j<m; ++j){
            if(matrix[0][j] == 0){
                first_row = true;
                break;
            }
        }

        for(int i=1; i<n; ++i) {
            for(int j=1; j<m; ++j) {
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i=1; i<n; ++i) {
            for(int j=1; j<m; ++j) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if(first_col){
            for(int i=0; i<n; ++i)
                matrix[i][0] = 0;
        }

        if(first_row){
            for(int j=0; j<m; ++j)
                matrix[0][j] = 0;
        }
    }
};