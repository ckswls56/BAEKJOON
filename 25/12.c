#include <stdio.h>
#define MAX 1001

typedef struct coordinate
{
    int x;
    int y;
} coordinate;

const int direction[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
char visited[MAX][MAX];
int res[MAX][MAX];
int arr[MAX][MAX];

coordinate q[MAX * MAX];
int front = -1;
int rear = -1;
int m, n;

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

void bfs()
{
    coordinate c;

    while (size())
    {
        c = pop();
        int y = c.y;
        int x = c.x;
        for (int i = 0; i < 4; i++)
        {
            int dy = direction[i][0];
            int dx = direction[i][1];
            if ((y + dy >= 0 && y + dy < n) && (x + dx >= 0 && x + dx < m) && arr[y + dy][x + dx] == 0 && visited[y + dy][x + dx] == 0)
            {
                res[y + dy][x + dx] = res[y][x] + 1;
                push(y + dy, x + dx);
                visited[y + dy][x + dx] = 1;
            }
        }
    }
}

int check_box()
{
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (res[i][j] == 0 && arr[i][j] == 0)
            {
                return -1;
            }
            else if (res[i][j] > ret)
                ret = res[i][j];
        }
    }
    return ret;
}

int main()
{
    scanf("%d %d", &m, &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 1)
            {
                push(i, j);
            }
        }
    }

    bfs();

    printf("%d", check_box());
}