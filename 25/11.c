#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 301

typedef struct coordinate
{
    int x;
    int y;
} coordinate;

const int direction[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
int res[MAX][MAX];
int visited[MAX][MAX];
coordinate q[MAX * MAX];

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

void bfs(int x1, int y1, int x2, int y2, int l)
{
    coordinate c;
    visited[y1][x1] = 1;
    push(y1, x1);

    while (size())
    {
        c = pop();
        int y = c.y;
        int x = c.x;
        if (y == y2 && x == x2)
        {
            break;
        }
        for (int i = 0; i < 8; i++)
        {
            int dx = direction[i][0];
            int dy = direction[i][1];
            if ((y + dy >= 0 && y + dy < l) && (x + dx >= 0 && x + dx < l) && visited[y + dy][x + dx] == 0)
            {
                res[y + dy][x + dx] = res[y][x] + 1;
                push(y + dy, x + dx);
                visited[y + dy][x + dx] = 1;
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(visited, 0, sizeof(visited));
        memset(res, 0, sizeof(res));
        rear = -1;
        front = -1;
        int l, start_x, start_y, end_x, end_y;
        scanf("%d", &l);
        scanf("%d %d %d %d", &start_x, &start_y, &end_x, &end_y);
        bfs(start_x, start_y, end_x, end_y, l);
        printf("%d\n", res[end_y][end_x]);
    }
}