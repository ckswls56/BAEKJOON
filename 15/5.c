#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int	promising(char *board, int y)
{
	int i = 0;

	while (i < y)
	{
		if (board[i] == board[y] || y - i == abs(board[y] - board[i]))
			return (0);
		i++;
	}
	return (1);
}

void	play_queens(char *board, int y, int *cnt,int n)
{
	int	x;

	if (y == n)
		(*cnt)++;
	else
	{
		x = 0;
		while (x < n)
		{
			board[y] = x + '0';
			if (promising(board, y))
				play_queens(board, y + 1, cnt, n);
			x++;
		}
	}
}

int	queens_puzzle(int n)
{
	char	*board;
	board = (char*)malloc(n);
	int		cnt = 0;
	
	play_queens(board, 0, &cnt,n);
	return (cnt);
}

int main() {
	int n;
	scanf("%d", &n);

	printf("%d", queens_puzzle(n));
}
