#include<bits/stdc++.h>
using namespace std;

vector< pair<int,int> >v(509);
int path[109][109];
map< pair< pair<int,int>, pair<int,int> >,int>cantgo;

int ax[]= {0,0,-1,1};
int ay[]={-1,1,0,0};

bool valid(int x,int y,int n,int m)
{
    return (x>-1 && y>-1 && x<n && y<m);
}
void clean()
{
    v=vector< pair<int,int> >(509,{200,200});
    memset(path,-1,sizeof(path));
    cantgo.clear();
}

int bfs(int n,int m)
{
    queue<int>q;
    q.push(0);
    q.push(0);
    path[0][0]=0;
    pair< pair<int,int>, pair<int,int> >p1;
    pair<int,int>tempp;
    while(q.size())
    {
        int tx=q.front();
        q.pop();
        int ty=q.front();
        q.pop();
        int dist=path[tx][ty];
        if(tx==n-1 && ty==m-1)
            return path[tx][ty];
        for(int i=0; i<4; i++)
        {
            int px=tx+ax[i];
            int py=ty+ay[i];
            tempp=make_pair(px,py);
            p1=make_pair( make_pair(tx,ty),make_pair(px,py));
            if(valid(px,py,n,m) && cantgo[p1]==0)
            {
                if(v[dist+1]==tempp)
                {
                    q.push(tx);
                    q.push(ty);
                    path[tx][ty]++;
                }
                else if(path[px][py]==-1)
                {
                    q.push(px);
                    q.push(py);
                    path[px][py]=dist+1;
                }
            }
        }
    }
    return path[n-1][m-1];
}


int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)==2 && n && m)
    {
        clean();
        int r,a,b,c,d;
        scanf("%d",&r);
        for(int i=0; i<r; i++)
        {
            scanf("%d %d %d %d",&a,&b,&c,&d);
            cantgo[make_pair( make_pair(a,b),make_pair(c,d))]=1;
        }
        scanf("%d",&r);
        for(int i=0;i<r;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            v[a]=make_pair(b,c);
        }
        cout<<bfs(n,m)<<endl;
    }
}
