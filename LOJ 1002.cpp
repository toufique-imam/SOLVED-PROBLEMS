#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class edge
{
public:
    int u,v,w;
    edge() {};
    edge(int a,int b,int c)
    {
        this->u=a;
        this->v=b;
        this->w=c;
    }
    bool operator < (const edge &x) const
    {
        return this->w<x.w;
    }
};

class edge2
{
public:
    int v,w;
    edge2() {};
    edge2(int a,int b)
    {
        this->v=a;
        this->w=b;
    }
    bool operator < (const edge &x) const
    {
        return this->w>x.w;
    }
};

class DSU
{
public:
    int n;
    int par[509];
    DSU(int n)
    {
        this->n=n;
        for(int i=0; i<n; i++)
        {
            par[i]=i;
        }
    }
    int ROOT(int x)
    {
        while(par[x]!=x)
        {
            par[x]=par[par[x]];
            x=par[x];
        }
        return x;
    }
    void UNION(int x,int y)
    {
        int p=ROOT(x);
        int q=ROOT(y);
        par[p]=par[q];
    }
    void UNION1(int x,int y)
    {
        par[x]=par[y];
    }
};

vector<edge>v;
vector<edge2>vq[509];
int visited[509];


void clean()
{
    v.clear();
    for(int i=0; i<509; i++)
    {
        vq[i].clear();
    }
    memset(visited,-1,sizeof(visited));
}
void bfs(int source)
{
    visited[source]=0;
    queue<edge2>q;
    q.push(edge2(source,0));
    while(q.size())
    {
        edge2 t=q.front();
        q.pop();
        for(int i=0; i<vq[t.v].size(); i++)
        {
            edge2 px=vq[t.v][i];
            if(visited[px.v]==-1)
            {
                visited[px.v]=max(visited[t.v],px.w);
                q.push(edge2(px.v,visited[px.v]));
            }
        }
    }
    return;
}

void MST(int n)
{
    DSU vx(n);
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++)
    {
        edge x=v[i];
        int tx=vx.ROOT(x.u);
        int ty=vx.ROOT(x.v);
        if(tx!=ty)
        {
            vx.UNION1(tx,ty);
            vq[x.u].push_back(edge2(x.v,x.w));
            vq[x.v].push_back(edge2(x.u,x.w));
        }
    }
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int test;
    scanf("%d",&test);
    for(int _t=1; _t<=test; _t++)
    {
        clean();
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0; i<m; i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            v.push_back(edge(a,b,c));
        }
        MST(n);
        int source;
        scanf("%d",&source);
        bfs(source);
        printf("Case %d:\n",_t);
        for(int i=0; i<n; i++)
        {
            if(visited[i]==-1)
                puts("Impossible");
            else
                printf("%d\n",visited[i]);
        }
    }
}
