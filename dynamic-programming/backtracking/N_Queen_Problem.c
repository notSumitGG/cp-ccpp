#include <stdbool.h>
#include <stdio.h>

int n;

bool isValid(int board[n][n], int row, int col) {
	int i, j;

	for(i = 0; i < col; i++)                               /* Check this row on left side */
		if(board[row][i])
			return false;

	for(i = row, j = col; i >= 0 && j >= 0; i--, j--)      /* Check upper diagonal on left side */
		if(board[i][j])
			return false;

	for(i = row, j = col; j >= 0 && i < n; i++, j--)       /* Check lower diagonal on left side */
		if(board[i][j])
			return false;

	return true;
}

bool nqueen(int board[n][n], int row) {
	if(row >= n)
		return true;

	for(int col = 0; col < n; col++) {
		if(isValid(board, row, col)) {
			board[row][col] = 1;

			if(nqueen(board, row + 1))
				return true;

			board[row][col] = 0;
		}
	}
	return false;
}

int main(){
	int board[1000][1000];
	scanf(" %d", &n);
	if (nqueen(board, 0) == false) {
		printf("Solution does not exist");
	}
    else
        for (int i = 0; i < n; i++) {
		    for (int j = 0; j < n; j++)
		    	printf(" %d ", board[i][j]);
	    	printf("\n");
	    }

	return 0;
}