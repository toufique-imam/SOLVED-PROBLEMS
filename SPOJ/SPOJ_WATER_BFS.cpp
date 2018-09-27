#include<bits/stdc++.h>
using namespace std;
#define ll              long long
#define pb              push_back
#define read()         freopen("input.txt","r",stdin)
#define write()        freopen("output.txt","w",stdout)
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define mod             100000007
#define all(v)          v.begin(),v.end()

int n,m;
int a1[109][109];
int a2[109][109];
int ax[]= {0,0,1,-1};
int ay[]= {1,-1,0,0};
bool visited[109][109];

bool check(int x,int y)
{
    if(x>-1 && y>-1 && x<n && y<m)
        return true;
    return false;
}

void bfs(int x,int y)
{
    int tx,ty,vx,vy;
    queue<int>q;
    q.push(x);
    q.push(y);
    visited[x][y]=1;
    a2[x][y]=a1[x][y];
    while(q.empty()==0)
    {
        tx=q.front();
        q.pop();
        ty=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            vx=tx+ax[i];
            vy=ty+ay[i];
            if(check(vx,vy) && visited[vx][vy]==0 && a1[vx][vy]>=a1[tx][ty])
            {
                visited[vx][vy]=1;
                a2[vx][vy]=a1[vx][vy];
                q.push(vx);
                q.push(vy);
            }
        }
    }
}

void input()
{
    memset(visited,0,sizeof(visited));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d",&a1[i][j]);
            a2[i][j]=mod;
        }
    }
}

void row()
{
    for(int i=0; i<n; i++)
    {
        if(visited[i][0]==0)
            bfs(i,0);
        if(visited[i][m-1]==0)
            bfs(i,m-1);
    }
}

void col()
{
    for(int i=0; i<m; i++)
    {
        if(visited[0][i]==0)
            bfs(0,i);
        if(visited[n-1][i]==0)
            bfs(n-1,i);
    }
}

void gain()
{
    bool f=0;
    for(int i=1; i<n-1; i++)
    {
        for(int j=1; j<m-1; j++)
        {
            if(visited[i][j]==0)
            {
                int minn=mod;
                for(int k=0; k<4; k++)
                {
                    int vx=i+ax[k];
                    int vy=j+ay[k];
                    if(check(vx,vy))
                        minn=min(minn,max(a2[vx][vy],a1[vx][vy]));
                }
                if(minn<a2[i][j])
                {
                    f=1;
                    a2[i][j]=minn;
                    //visited[i][j]=1;
                }
            }
        }
    }
    if(f)
        gain();
    else
        return;
}

int calu()
{
    int i,j,cnt=0;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(a1[i][j]<a2[i][j])
                cnt+=abs(a2[i][j]-a1[i][j]);
    return cnt;
}


int main ()
{
    //read();
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int i,j;
        scanf("%d %d",&n,&m);
        input();
        row();
        col();
        gain();
        printf("%d\n",calu());
    }
}
