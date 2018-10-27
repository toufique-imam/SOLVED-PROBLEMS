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
int CF[1009][1009];
int cost[1009];
int par[1009];
int n;
int bfs(int x,int target)
{
    memset(par,-1,sizeof par);
    queue<int>q;
    q.push(x);
    par[x]=x;
    cost[x]=1e9;
    bool f=0;
    while(!q.empty())
    {
        int t=q.front();
        if(t==target)
        {
            f=1;
            break;
        }
        q.pop();
        for(int i=1; i<=n; i++)
        {
            if(CF[t][i]>0 and par[i]==-1)
            {
                par[i]=t;
                cost[i]=min(cost[t],CF[t][i]);
                q.push(i);
            }
        }
    }
    if(f)
        return cost[target];
    else
        return 0;
}
void path(int x,int flow)
{
    while(x!=par[x])
    {
        CF[par[x]][x]-=flow;
        CF[x][par[x]]+=flow;
        x=par[x];
        if(x==par[x])
            return;
        if(x==-1)
            return;
    }
    return;
}
int maxFlow(int tap,int sink)
{
    int ans=0;
    int flow=bfs(tap,sink);
    while(flow>0)
    {
        path(sink,flow);
        ans+=flow;
        flow=bfs(tap,sink);
    }
    return ans;
}
int main()
{
    TEST
    {
        int m,tap,sink;
        int a,b,c;
        scanf("%d%d%d%d",&n,&tap,&sink,&m);
        memset(CF,0,sizeof CF);
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            CF[a][b]+=c;
            CF[b][a]+=c;
        }
        int ans=maxFlow(tap,sink);
        printf("Case %d: %d\n",T,ans);
    }
}
