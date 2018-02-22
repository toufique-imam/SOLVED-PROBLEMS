#include<bits/stdc++.h>
using namespace std;

int visited[1009][1009];

int ax[]={0,0,1,-1};
int ay[]={-1,1,0,0};

bool valid(int x,int y,int n,int m)
{
    if(x>-1 && x<n && y>-1 && y<m && visited[x][y]==-1)
        return 1;
    return 0;
}

void bfs(int x,int y,int n,int m)
{
    queue<int>q;
    q.push(x);
    q.push(y);
    visited[x][y]=1;
    while(q.size())
    {
        int tx=q.front();
        q.pop();
        int ty=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int tempx=ax[i]+tx;
            int tempy=ay[i]+ty;
            if(valid(tempx,tempy,n,m))
            {
                visited[tempx][tempy]=visited[tx][ty]+1;
                q.push(tempx);
                q.push(tempy);
            }
        }
    }
    return;
}

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)==2 && n && m)
    {
        memset(visited,-1,sizeof(visited));
        int q,a,x,y;
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            scanf("%d %d",&a,&x);
            for(int j=0;j<x;j++)
            {
                scanf("%d",&y);
                visited[a][y]=0;
            }
        }
        scanf("%d %d",&x,&y);
        bfs(x,y,n,m);
        scanf("%d %d",&x,&y);
        printf("%d\n",visited[x][y]-1);
    }
}
