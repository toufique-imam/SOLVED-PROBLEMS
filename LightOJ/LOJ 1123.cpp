#include <bits/stdc++.h>
using namespace std;
const int N=309;
int n,m;
vector< pair<int,int> >vp[N];
vector< pair<int,pair<int,int> > >edge;
int cnt[N];
bool visited[N];
class DSU
{
public:
    int par[N];
    DSU() {};
    DSU(int x)
    {
        for(int i=0; i<x; i++)
            par[i]=i;
    }
    void UNION(int x,int y)
    {
        par[x]=par[y];
    }
    int ROOT(int x)
    {
        while(x!=par[x])
        {
            par[x]=par[par[x]];
            x=par[x];
        }
        return x;
    }
};
void clean()
{
    for(int i=0; i<N; i++)
        vp[i].clear();
    edge.clear();
    memset(visited,0,sizeof visited);
    memset(cnt,0,sizeof cnt);
}
bool cansolve()
{
    for(int i=1; i<=n; i++)
    {
        if(!cnt[i])
            return 0;
    }
    return 1;
}
int bfs(int x)
{
    visited[x]=1;
    queue<int>q;
    q.push(x);
    int ans=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<vp[u].size(); i++)
        {
            int v=vp[u][i].first;
            int cost=vp[u][i].second;
            if(!visited[v])
            {
                ans+=cost;
                q.push(v);
                visited[v]=1;
            }
        }
    }
    return ans;
}
void solve(int x)
{
    stack< pair<int, pair<int,int> > >vnew;
    for(int i=0; i<N; i++)
        vp[i].clear();
    DSU g(n+3);
    sort(edge.begin(),edge.end());
    for(int i=0; i<edge.size(); i++)
    {
        int u=edge[i].second.first;
        int v=edge[i].second.second;
        int cost=edge[i].first;
        int tx=g.ROOT(u);
        int ty=g.ROOT(v);
        if(tx!=ty)
        {
            g.UNION(tx,ty);
            vp[u].push_back(make_pair(v,cost));
            vp[v].push_back(make_pair(u,cost));
            vnew.push(make_pair(cost,make_pair(u,v)));
        }
    }
    edge.clear();
    while(!vnew.empty())
    {
        pair< int,pair<int,int> >pp;
        pp=vnew.top();
        vnew.pop();
        edge.push_back(pp);
    }
    memset(visited,0,sizeof visited);
    int ans=bfs(1);
    bool f=1;
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            f=0;
            break;
        }
    }
    if(f)
        printf("%d\n",ans);
    else
        puts("-1");
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int _t=1; _t<=test; _t++)
    {
        clean();
        printf("Case %d:\n",_t);
        scanf("%d %d",&n,&m);
        for(int i=1; i<=m; i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            cnt[a]++;
            cnt[b]++;
            edge.push_back(make_pair(c,make_pair(a,b)));
            solve(i);
        }
    }
}
