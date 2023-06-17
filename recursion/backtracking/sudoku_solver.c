#include<stdio.h>

int isPossible(int sudoku[9][9], int row, int col, int num){
    for(int i = 0; i < 9; i++)
        if(sudoku[row][i] == num)
            return 0;
    
    for(int i = 0; i < 9; i++)
        if(sudoku[i][col] == num)
            return 0;
    
    int a = row - (row % 3);
    int b = col - (col % 3);
    for(int i = a; i <= a + 2; i++)
        for(int j = b; j <= b + 2; j++)
            if(sudoku[i][j] == num)
                return 0;

    return 1;
}
int solveSudoku(int sudoku[9][9], int row, int col){
	if(row == 8 && col == 9)
        return 1;

    if(col == 9){
		row++;
		col = 0;
	}
    
	if(sudoku[row][col] > 0)
		return solveSudoku(sudoku, row, col + 1);

    for(int i = 1; i <= 9; i++){
        if(isPossible(sudoku, row, col, i) == 1){
            sudoku[row][col] = i;
            if(solveSudoku(sudoku, row, col + 1) == 1)
                return 1;
        }
        sudoku[row][col] = 0;
    }
    return 0;
}
void display(int x[9][9]){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++)
            printf(" %d", x[i][j]);
        printf("\n");
    }
}
int main(){
	int sudoku[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                        {6, 0, 0, 1, 9, 5, 0, 0, 0},
                        {0, 9, 8, 0, 0, 0, 0, 6, 0},
                        {8, 0, 0, 0, 6, 0, 0, 0, 3},
                        {4, 0, 0, 8, 0, 3, 0, 0, 1},
                        {7, 0, 0, 0, 2, 0, 0, 0, 6},
                        {0, 6, 0, 0, 0, 0, 2, 8, 0},
                        {0, 0, 0, 4, 1, 9, 0, 0, 5},
                        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    display(sudoku);
    if(solveSudoku(sudoku, 0, 0) == 1){
        printf("Solved sudoku :\n");
        display(sudoku);
    }
    else
        printf("Solution not possible.");
    
	return 0;
}