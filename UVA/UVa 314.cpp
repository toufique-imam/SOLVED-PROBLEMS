#include<bits/stdc++.h>

using namespace std;

int ax[] = {-1, 0, 1, 0};
int ay[] = {0, 1, 0, -1};
int grid[55][55];
int visited[55][55][4];
int n, m, x, y, x2, y2, dir;

bool cango(int xm, int ym)
{
    if (xm <= 0 or ym <= 0 or xm >= n or ym >= m)
        return false;
    if (grid[xm][ym])
        return false;
    if (grid[xm - 1][ym - 1])
        return false;
    if (grid[xm - 1][ym])
        return false;
    if (grid[xm][ym - 1])
        return false;
    return true;
}

void clean()
{
    memset(visited, -1, sizeof visited);
}

int bfs()
{
    queue<int> q;
    int tx, ty, dx, px, py;
    if (cango(x, y))
    {
        visited[x][y][dir] = 0;
        q.push(x);
        q.push(y);
        q.push(dir);
    }
    while (!q.empty())
    {
        tx = q.front();
        q.pop();
        ty = q.front();
        q.pop();
        dx = q.front();
        q.pop();
        if (tx == x2 and ty == y2)
            return visited[tx][ty][dx];
        if(visited[tx][ty][(dx+1)%4]==-1)
        {
            visited[tx][ty][(dx+1)%4]=visited[tx][ty][dx]+1;
            q.push(tx);
            q.push(ty);
            q.push((dx+1)%4);
        }
        if(visited[tx][ty][(dx+3)%4]==-1)
        {
            visited[tx][ty][(dx+3)%4]=visited[tx][ty][dx]+1;
            q.push(tx);
            q.push(ty);
            q.push((dx+3)%4);
        }
        for(int i=1; i<=3; i++)
        {
            px=tx+ax[dx]*i;
            py=ty+ay[dx]*i;
            if(cango(px,py))
            {
                if(visited[px][py][dx]==-1)
                {
                    visited[px][py][dx]=visited[tx][ty][dx]+1;
                    q.push(px);
                    q.push(py);
                    q.push(dx);
                }
            }
            else
                break;
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> m and n + m > 0)
    {
        clean();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        string xd;
        cin >> x >> y >> x2 >> y2 >> xd;
        if (xd[0] == 'n')
            dir = 0;
        else if (xd[0] == 's')
            dir = 2;
        else if (xd[0] == 'e')
            dir = 1;
        else
            dir = 3;
        cout << bfs()<<endl;
    }
}
