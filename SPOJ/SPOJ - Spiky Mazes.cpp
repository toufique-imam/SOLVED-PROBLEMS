/*
ID:sabertooth9
TASK:SPOJ_SPIKES
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;
#define ll              long long
#define pb              push_back
#define read(s)         freopen(#s,"r",stdin)
#define write(s)        freopen(#s,"w",stdout)
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define mod             1000000007
#define all(v)          v.begin(),v.end()

vector<string>v;
bool visited[1000][1000];
ll dis[1000][1000];
ll n,m,cantake;
ll ax[]= {0,0,-1,1};
ll ay[]= {1,-1,0,0};

bool valid(ll x,ll y)
{
    if(x>-1 && y>-1 && x<n && y<m && v[x][y]!='#' && visited[x][y]==false)
        return 1;
    return 0;
}

void bfs(ll x,ll y)
{
    queue<ll>q;
    q.push(x);
    q.push(y);
    visited[x][y]=1;
    dis[x][y]=0;
    ll i,tx,ty,vx,vy;
    while(q.empty()==0)
    {
        tx=q.front();
        q.pop();
        ty=q.front();
        q.pop();
        for(i=0; i<4; i++)
        {
            vx=tx+ax[i];
            vy=ty+ay[i];
            if(valid(vx,vy))
            {
                visited[vx][vy]=1;
                q.push(vx);
                q.push(vy);
                if(v[vx][vy]=='s')
                    dis[vx][vy]=dis[tx][ty]+1;
                else
                    dis[vx][vy]=dis[tx][ty];
            }
        }
    }
}

int main ()
{
    //ll n,m,cantake;
    //read(input.txt);
    scanf("%lld %lld %lld",&n,&m,&cantake);
    string s;
    ll i,x,y,j;
    getchar();
    for(i=0; i<n; i++)
    {
        cin>>s;
        v.push_back(s);
        for(j=0; j<m; j++)
        {
            if(s[j]=='x')
            {
                x=i;
                y=j;
            }
        }
    }
    bfs(x,y);
    bool f=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(v[i][j]=='@' && dis[i][j]*2<=cantake && visited[i][j]==1)
            {
                f=1;
                break;
            }
        }
    }
    if(f)
        puts("SUCCESS");
    else
        puts("IMPOSSIBLE");
}
