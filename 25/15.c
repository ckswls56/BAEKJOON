#include <stdio.h>
#include <stdlib.h>

typedef struct coordinate
{
    int x;
    int y;
    char wall;
} coordinate;

int direction[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int n, m;
char visited[1001][1001][2];
char arr[1001][1001];
int res[1001][1001];
coordinate q[1001 * 1001 * 2];
int front = -1;
int rear = -1;

void push(int y, int x, int wall_cnt)
{
    q[++rear].y = y;
    q[rear].x = x;
    q[rear].wall = wall_cnt;
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
    visited[y][x][0] = 1;
    res[y][x] = 1;
    push(y, x, 0);

    while (size())
    {
        c = pop();
        int y = c.y;
        int x = c.x;
        int wall_cnt = c.wall;
        if (y == n - 1 && x == m - 1)
        {
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int dy = direction[i][0];
            int dx = direction[i][1];
            if ((y + dy >= 0 && y + dy < n) && (x + dx >= 0 && x + dx < m) && visited[y + dy][x + dx][wall_cnt] == 0)
            {
                if (arr[y + dy][x + dx] == 0)
                {
                    res[y + dy][x + dx] = res[y][x] + 1;
                    push(y + dy, x + dx, wall_cnt);
                    visited[y + dy][x + dx][wall_cnt] = 1;
                }
                else
                {
                    if (wall_cnt) //이미 벽을 뚫은적이 있는 경우
                        continue;
                    else
                    {
                        res[y + dy][x + dx] = res[y][x] + 1;
                        push(y + dy, x + dx, wall_cnt + 1);
                        visited[y + dy][x + dx][wall_cnt + 1] = 1;
                    }
                }
            }
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
    if (res[n - 1][m - 1])
        printf("%d", res[n - 1][m - 1]);
    else
        printf("-1");
}