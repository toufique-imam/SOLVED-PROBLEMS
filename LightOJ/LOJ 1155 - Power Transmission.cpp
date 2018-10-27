/*
ID: sabertooth
LANG: C++11
TASK:
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define eps             1e-9
#define inf             0x3f3f3f3f
#define INF             2e18
#define PI              acos(-1.0)
#define ff              first
#define ss              second
#define all(v)          v.begin(),v.end()
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(min(a,b),min(c,d))
#define max4(a,b,c,d)   max(max(a,b),max(c,d))
#define max5(a,b,c,d,e) max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e) min(min3(a,b,c),min(d,e))
#define Iterator(a)     __typeof__(a.begin())
#define read            freopen("in.txt","r",stdin);
#define write           freopen("out.txt","w",stdout);
#define TEST            int test;scanf("%d",&test);for(int T=1;T<=test;T++)
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define reunique(v)     v.resize(std::unique(all(v)) - v.begin())
#define MP              make_pair
#define PB              push_back
#define EB              emplace_back
#define segtree         int mid=(st+en)/2,lt=node*2,rg=node*2+1
#define MERGE(v1,v2,v)  merge(all(v1),all(v2),back_inserter(v))
//int CAP[109];
int par[109+109];
int cost[109+109];
int CF[2*109][2*109];
int n;
int bfs(int x,int target)
{
    queue<int>q;
    q.push(x);
    memset(par,-1,sizeof par);
    par[x]=x;
    cost[x]=1000000000;
    while(!q.empty())
    {
        int t=q.front();
        if(t==target)
            break;
        q.pop();
        for(int i=1; i<=n+n+2; i++)
        {
            if(par[i]==-1 and CF[t][i]>0)
            {
                q.push(i);
                par[i]=t;
                cost[i]=min(CF[t][i],cost[t]);
            }
        }
    }
    if(par[target]==-1)
        return 0;
    return cost[target];
}
void path(int flow)
{
    int x=n+n+2;
    while(par[x]!=x and par[x]!=-1)
    {
        CF[par[x]][x]-=flow;
        CF[x][par[x]]+=flow;
        //cout<<x<<"->";
        //if(par[x]==0)cout<<0;
        x=par[x];
    }
    //cout<<" :"<<flow<<endl;
    return;
}
int maxFlow()
{
    int ans=0;
    int flow=bfs(0,n+n+2);
    while(flow>0)
    {
        path(flow);
        ans+=flow;
        flow=bfs(0,n+n+2);
    }
    return ans;
}
int main()
{
    TEST
    {
        //memset(cost,0,sizeof cost);
      //  memset(CAP,0,sizeof CAP);
        memset(CF,0,sizeof CF);
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&CF[i][i+n]);
        }
        //[0]=CAP[n+1]=1e9;
        int m,a,b,c;
        scanf("%d",&m);
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            CF[a+n][b]=+c;
        }
        int sink,tap;
        scanf("%d%d",&tap,&sink);
        for(int i=0; i<tap; i++)
        {
            scanf("%d",&a);
            CF[0][a]=1e9;
        }
        for(int i=0; i<sink; i++)
        {
            scanf("%d",&a);
            CF[a+n][n+n+2]=1e9;
        }
        printf("Case %d: %d\n",T,maxFlow());
    }
}
