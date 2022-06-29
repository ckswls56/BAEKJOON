#include <stdio.h>

int abs(int n) {
	if (n < 0)
		return -n;
	return n;
}

void print_board(int(*board)[9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	exit(0);
}


void sudoku(int(*board)[9], int count) {
	if (count == 81)
		print_board(board);
	else {
		int x = count % 9;
		int y = count / 9;

		if (board[y][x] != 0) {
			sudoku(board, count + 1);
		}
		else {
			for (int i = 1; i <= 9; i++) {
				board[y][x] = i;
				int fail = 0;
				//row,col check
				for (int j = 0; j < 9; j++) {
					if (j != x && board[y][j] == i)
						fail = 1;
					if (j != y && board[j][x] == i)
						fail = 1;
				}

				int center1 = 0;
				int center2 = 0;
				for (int c1 = 1; c1 <= 7; c1 += 3) {
					for (int c2 = 1; c2 <= 7; c2 += 3) {
						if (abs(y - c1) <= 1 && abs(x - c2) <= 1) {
							center1 = c1;
							center2 = c2;
						}
							
					}
				}
				//sqare check
				for (int n1 = center1 - 1; n1 <= center1 + 1; n1++) {
					for (int n2 = center2 - 1; n2 <= center2 + 1; n2++) {
						if (n1 == y && n2 == x)
							continue;
						else {
							if (board[n1][n2] == i)
								fail = 1;
						}
					}
				}

				if (!fail)
					sudoku(board, count + 1);
				board[y][x] = 0;

			}

		}

	}
}
int main() {
	int board[9][9];

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	
	sudoku(board, 0);
}
