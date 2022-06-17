#include <stdio.h>
#include <stdlib.h>

int chess_white(char **board) {
	int i = 0;
	int j = 0;
	int repaint = 0;
	int top=1; // top_coner is White

	while (i < 8) {
		j = 0; top *= -1;
		while (j < 8) {
			if (top == 1) {
				if (board[i][j] == 'W')
					repaint++;
			}
			else {
				if (board[i][j] == 'B')
					repaint++;
			}
			top *= -1;
			j++;
		}
		i++;
	}
	return repaint;
}
int chess_black(char **board) {
	int i = 0;
	int j = 0;
	int repaint = 0;
	int top = -1; // top coner is Black

	while (i < 8) {
		j = 0; top *= -1;
		while (j < 8) {
			if (top == 1) {
				if (board[i][j] == 'W')
					repaint++;
			}
			else {
				if (board[i][j] == 'B')
					repaint++;
			}
			top *= -1;
			j++;
		}
		i++;
	}
	return repaint;
}

char **make_board(char **board, int n,int m) {
	//mak 8 * 8 board
	int i, j;
	i = 0;
	char **res;
	res = (char**)malloc(sizeof(char*) * 8);

	while (i < 8) {
		j = 0;
		res[i] = (char*)malloc(sizeof(char)*9);
		while (j < 8) {
			res[i][j] = board[n][m];
			m++; j++;
		}
		n++; i++; m -= 8;
	}
	return res;
}

int main(){
	int n,m,i,j,min,c1,c2;
	char ** board;
	char ** temp;

	scanf("%d %d", &n, &m);
	board = (char**)malloc(sizeof(char*)*n);

	i = 0;
	while (i < n) {
		board[i] = (char*)malloc(sizeof(char)*m + 1);
		scanf("%s", board[i++]);
	}

	i = 0; min = 1000000;
	while (i <= n - 8) {
		j = 0;
		while (j <= m - 8) {
			temp = make_board(board, i, j);
			c1 = chess_black(temp); c2 = chess_white(temp);
			if (c1 < min || c2 < min) {
				if (c1 > c2)
					min = c2;
				else
					min = c1;
			}
			j++;
		}
		i++;
	}
	printf("%d", min);
	return 0;
}
