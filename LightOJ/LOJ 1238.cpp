#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int inf=10000000;
struct edge
{
    int x,y;
};
int grid[30][30];
int level[3][30][30];
int ax[]= {0,0,1,-1};
int ay[]= {1,-1,0,0};
//vector<string>v;
edge puff[5];
int n,m;
void process(int pos,string s)
{
    for(int i=0; i<m; i++)
    {
        if(s[i]=='#' or s[i]=='m')
            grid[pos][i]=0;
        else if(s[i]=='a' or s[i]=='b' or s[i]=='c')
        {
            puff[s[i]-'a']= {pos,i};
        }
        else if(s[i]=='h')
        {
            puff[3]= {pos,i};
        }
    }
}
bool cango(int x,int y)
{
    if(x<n and y<m and x>-1 and y>-1)
        return 1;
    return 0;
}

void bfs(edge qw,int no)
{
    queue<int>q;
    q.push(qw.x);
    q.push(qw.y);
    level[no][qw.x][qw.y]=0;
    while(q.size())
    {
        int tx=q.front();
        q.pop();
        int ty=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int tempx=tx+ax[i];
            int tempy=ty+ay[i];
            if(cango(tempx,tempy) and grid[tempx][tempy]==-1 && level[no][tempx][tempy]==-1)
            {
                level[no][tempx][tempy]=level[no][tx][ty]+1;
                q.push(tempx);
                q.push(tempy);
            }
        }
    }
    return;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    for(int _t=1; _t<=test; _t++)
    {
        memset(grid,-1,sizeof grid);
        memset(level,-1,sizeof(level));
        cin>>n>>m;
        string s;
        for(int i=0; i<n; i++)
        {
            cin>>s;
            process(i,s);
        }
        for(int i=0; i<3; i++)
        {
            bfs(puff[i],i);
        }
        int ans=-inf;
        for(int i=0; i<3; i++)
        {
            ans=max(ans,level[i][puff[3].x][puff[3].y]);
        }
        cout<<"Case "<<_t<<": "<<ans<<endl;
    }
}

