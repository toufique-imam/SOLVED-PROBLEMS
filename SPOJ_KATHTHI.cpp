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
 
vector<string>v;
ll dis[1009][1009];
ll n,m;
ll ax[]= {0,0,1,-1};
ll ay[]= {1,-1,0,0};
 
bool check(ll x,ll y)
{
    if(x>-1 && y>-1 && x<n && y<m)
        return true;
    return false;
}
 
 
void cln()
{
    v.clear();
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
            dis[i][j]=mod;
    }
}
 
/*void process(ll x,string s)
{
    for(ll i=0;i<m;i++)
    {
        if(s[i]==guru)
            v[x][i]=0;
        else
            v[x][i]=1;
    }
}*/
 
void bfs_0_1()
{
    deque<ll>q;
    dis[0][0]=0;
    q.push_front(0);
    q.push_front(0);
    ll tx,ty,vx,vy,i,t;
    char guru;
    while(q.empty()==0)
    {
        tx=q.front();
        q.pop_front();
        ty=q.front();
        q.pop_front();
        guru=v[tx][ty];
        for(i=0; i<4; i++)
        {
            vx=tx+ax[i];
            vy=ty+ay[i];
            if(check(vx,vy))
            {
                if(guru==v[vx][vy])
                    t=0;
                else
                    t=1;
                if(dis[vx][vy]>dis[tx][ty]+t)
                {
                    dis[vx][vy]=dis[tx][ty]+t;
                    if(t)
                    {
                        q.push_back(vx);
                        q.push_back(vy);
                    }
                    else
                    {
                        q.push_front(vy);
                        q.push_front(vx);
                    }
                }
 
            }
        }
    }
}
 
int main ()
{
    //read();
   // write();
    ll test;
    scanf("%lld",&test);
    for(ll xd=1;xd<=test;xd++)
    {
        ll i;
        scanf("%lld %lld",&n,&m);
        cln();
        getchar();
        string s;
        for(i=0; i<n; i++)
        {
            cin>>s;
            v.pb(s);
        }
        bfs_0_1();
        printf("%lld\n",dis[n-1][m-1]);
    }
}
 
