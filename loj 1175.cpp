#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
int n,m;
int grid[209][209];
//int levelc[209][209][209];
int finlevel[209][209];
int level[209][209];
int ax[]= {0,0,-1,1};
int ay[]= {1,-1,0,0};
vector< pair<int,int> >v;
 
bool cango(int x,int y)
{
    return x<n and y<m and x>-1 and y>-1;
}
 
void bfs1(int x,int y)
{
    queue<int>q;
    q.push(x);
    q.push(y);
    finlevel[x][y]=0;
    while(q.size())
    {
        int tx=q.front();
        q.pop();
        int ty=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int px=tx+ax[i];
            int py=ty+ay[i];
            if(cango(px,py) and finlevel[px][py]>finlevel[tx][ty]+1 and grid[px][py]!=2){
                q.push(px);
                q.push(py);
                finlevel[px][py]=finlevel[tx][ty]+1;
            }
        }
    }
}
 
void bfs(int x,int y)
{
    queue<int>q;
    q.push(x);
    q.push(y);
    level[x][y]=0;
    while(q.size())
    {
        int tx=q.front();
        q.pop();
        int ty=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int px=tx+ax[i];
            int py=ty+ay[i];
            if(cango(px,py) and !grid[px][py] and level[px][py]==-1)
            {
                q.push(px);
                q.push(py);
                level[px][py]=level[tx][ty]+1;
            }
        }
    }
}
 
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int test;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>test;
    for(int _t=1; _t<=test; _t++)
    {
        memset(level,-1,sizeof level);
        memset(grid,0,sizeof(grid));
        v.clear();
        //for(int i=0;i<209;i++)for(int j=0;j<209;j++)levelc[i][j]=1e9;
        for(int i=0;i<209;i++)for(int j=0;j<209;j++)finlevel[i][j]=1e9;
        cin>>n>>m;
        int st,en;
        for(int i=0; i<n; i++)
        {
            string s;
            cin>>s;
            for(int j=0; j<m; j++)
            {
                if(s[j]=='#')
                    grid[i][j]=2;
                else if(s[j]=='F')
                {
                    v.push_back(make_pair(i,j));
                    grid[i][j]=1;
                }
                else if(s[j]=='J')
                {
                    st=i;
                    en=j;
                }
            }
        }
        for(int i=0; i<v.size(); i++)
        {
            bfs1(v[i].first,v[i].second);
        }
        bfs(st,en);
        bool f=0;
        int ans=2000000000;
        for(int i=0; i<n; i++)
        {
            if(grid[i][0]==0)
            {
                if(level[i][0]<finlevel[i][0] and level[i][0]!=-1)
                {
                    f=1;
                    ans=min(ans,level[i][0]);
                }
            }
            if(grid[i][m-1]==0)
            {
                if(level[i][m-1]<finlevel[i][m-1] and  level[i][m-1]!=-1)
                {
                    f=1;
                    ans=min(ans,level[i][m-1]);
                }
            }
        }
        for(int i=0; i<m; i++)
        {
            if(grid[0][i]==0)
            {
                if(level[0][i]<finlevel[0][i] and level[0][i]!=-1)
                {
                    f=1;
                    ans=min(ans,level[0][i]);
                }
            }
            if(grid[n-1][i]==0)
            {
                if(level[n-1][i]<finlevel[n-1][i] and level[n-1][i]!=-1)
                {
                    f=1;
                    ans=min(ans,level[n-1][i]);
                }
            }
        }
        cout<<"Case "<<_t<<": ";
        if(f)
            cout<<ans+1<<endl;
        else
            cout<<"IMPOSSIBLE"<<endl;
    }
}
