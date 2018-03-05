#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 10000
#define all(v) v.begin() v.end()

double grid[1009][1009];
bool mp[1009][1009];
int visited[1009][1009];
int ax[]= {0,0,1,-1,1,-1,-1,1};
int ay[]= {1,-1,0,0,1,1,-1,-1};
double dist=100*sqrt(2);
bool cango(int x,int y,int n,int m)
{
    if(x>-1 && y>-1 && x<=n && y<=m)
        return 1;
    return 0;
}

double bfs(int n,int m)
{
    queue<int>q;
    q.push(0);
    q.push(0);
    grid[0][0]=0;
    while(q.size())
    {
        int tx=q.front();
        q.pop();
        int ty=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int x=tx+ax[i];
            int y=ty+ay[i];
            if(cango(x,y,n,m))
            {
                if(grid[x][y]>grid[tx][ty]+100)
                {
                    grid[x][y]=grid[tx][ty]+100;
                    q.push(x);
                    q.push(y);
                }
            }
        }
        for(int i=4; i<8; i++)
        {
            int x=tx+ax[i];
            int y=ty+ay[i];
            if(cango(x,y,n,m) && mp[x][y])
            {
                if(grid[x][y]>grid[tx][ty]+dist)
                {
                    grid[x][y]=grid[tx][ty]+dist;
                    q.push(x);
                    q.push(y);
                }
            }
        }
    }
    return grid[n][m];
}

int main()
{
    for(int i=0; i<1001; i++)
        for(int j=0; j<1001; j++)
            grid[i][j]=1e9*1.0;
    int n,m;
    scanf("%d %d",&n,&m);
    int a;
    scanf("%d",&a);
    for(int i=0; i<a; i++)
    {
        int we,er;
        scanf("%d %d",&we,&er);
        mp[we][er]=1;
    }
    printf("%0.0f\n",round(bfs(n,m)));
}
