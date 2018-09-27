#include<bits/stdc++.h>
using namespace std;
#define     pii     pair<int,int>
#define     pll     pair<long long,long long>
#define     ff      first
#define     sc      second
const long long arrsize=100000;

struct edge
{
    long long to;
    long long weight;
    edge() {};
    edge(int a,int b)
    {
        to=a;
        weight=b;
    }
    bool const operator < (const edge &x) const
    {
        return weight>x.weight;
    }
};

vector<long long> dijkstra(long long source,vector< vector<edge> >roads)
{
    vector<long long>dist(roads.size()+3,1e18);
    priority_queue<edge>pq;
    pq.push(edge(source,0));
    dist[source]=0;
    while(pq.size())
    {
        edge t=pq.top();
        pq.pop();
        for(int i=0; i<roads[t.to].size(); i++)
        {
            edge x=roads[t.to][i];
            if(dist[x.to]>dist[t.to]+x.weight)
            {
                dist[x.to]=dist[t.to]+x.weight;
                pq.push(edge(x.to,dist[x.to]));
            }
        }
    }
    return dist;
}

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        long long n,k,x,m,s,a,b,c;
        vector< vector<edge> >roads;
        scanf("%lld %lld %lld %lld %lld",&n,&k,&x,&m,&s);
        roads.resize(n+3);
        for(int i=0; i<m; i++)
        {
            scanf("%lld %lld %lld",&a,&b,&c);
            roads[a].push_back(edge(b,2*c));
            roads[b].push_back(edge(a,2*c));
        }
        for(int i=1; i<=k; i++)
        {
            roads[i].push_back(edge(0,x));
            roads[0].push_back(edge(i,x));
        }
        vector<long long>dist=dijkstra(s,roads);
        for(int i=1; i<=n; i++)
            printf("%lld ",dist[i]/2);
        printf("\n");
    }
}
