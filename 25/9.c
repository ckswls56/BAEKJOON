#include <stdio.h>
#include <stdlib.h>

typedef struct coordinate
{
    int x;
    int y;
} coordinate;

int direction[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int n, m;
char visited[101][101];
char arr[101][101];
int res[101][101];
coordinate q[101 * 101];
int front = -1;
int rear = -1;

void push(int y, int x)
{
    q[++rear].y = y;
    q[rear].x = x;
}

coordinate pop()
{
    return q[++front];
}

int size()
{
    return rear - front;
}

void bfs(int y, int x)
{
    coordinate c;
    visited[y][x] = 1;
    res[y][x] = 1;
    push(y, x);

    while (size())
    {
        c = pop();
        int y = c.y;
        int x = c.x;
        if (y == n - 1 && x == m - 1)
        {
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int dy = direction[i][0];
            int dx = direction[i][1];
            if ((y + dy >= 0 && y + dy < n) && (x + dx >= 0 && x + dx < m) && visited[y + dy][x + dx] == 0 && arr[y + dy][x + dx] == 1)
            {
                res[y + dy][x + dx] = res[y][x] + 1;
                push(y + dy, x + dx);
            }
            visited[y + dy][x + dx] = 1;
        }
    }
}

int main()
{
    scanf("%d %d\n", &n, &m);

    char temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%c", &arr[i][j]);
            arr[i][j] -= '0';
        }
        scanf("%c", &temp); //개행 입력 방지
    }
    bfs(0, 0);
    printf("%d", res[n - 1][m - 1]);
}