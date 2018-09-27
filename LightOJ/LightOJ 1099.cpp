#include<bits/stdc++.h>
using namespace std;
#define  pii    pair<int,int>
#define  ff     first
#define  sc     second
const long long arrsize=5000;

struct edge
{
    long long to;
    long long weight;
    edge() {}
    edge(int n,int m)
    {
        this->to=n;
        this->weight=m;
    }
    bool operator < (const edge &x) const
    {
        return weight>x.weight;
    }
};


struct node
{
    long long x,v,w;
    node() {};
    node(int a,int b,int c)
    {
        x=a;
        v=b;
        w=c;
    }
    bool operator <(const node &next) const
    {
        if(x==next.x)
        {
            if(w==next.w)
                return v>next.v;
            return w>next.w;
        }
        return x>next.x;
    }
};


vector<edge>roads[arrsize+9];
long long dist[2][arrsize+9];

void clean()
{
    for(int i=0; i<=arrsize; i++)
        roads[i].clear();
    for(int i=0; i<=arrsize; i++)
        dist[0][i]=dist[1][i]=1e9;
}

void dijkstra()
{
    priority_queue<node>pq;
    pq.push(node(0,1,0));
    dist[0][1]=0;
    while(pq.size())
    {
        node t=pq.top();
        pq.pop();
        if(t.w>dist[t.x][t.v])
            continue;
        for(int i=0; i<roads[t.v].size(); i++)
        {
            edge x=roads[t.v][i];
            if(t.w+x.weight<dist[0][x.to])
            {
                dist[1][x.to]=dist[0][x.to];
                dist[0][x.to]=t.w+x.weight;
                pq.push(node(1,x.to,dist[1][x.to]));
                pq.push(node(0,x.to,dist[0][x.to]));
            }
            else if(t.w+x.weight>dist[0][x.to] and t.w+x.weight<dist[1][x.to])
            {
                dist[1][x.to]=t.w+x.weight;
                pq.push(node(1,x.to,dist[1][x.to]));
            }
        }
    }
}

int main()
{
    int test;
    scanf("%d",&test);
    for(int t=1; t<=test; t++)
    {
        clean();
        long long n,r,a,b,c;
        scanf("%lld %lld",&n,&r);
        for(int i=0; i<r; i++)
        {
            scanf("%lld %lld %lld",&a,&b,&c);
            roads[a].push_back(edge(b,c));
            roads[b].push_back(edge(a,c));
        }
        dijkstra();
        printf("Case %d: %lld\n",t,dist[1][n]);
    }
}
