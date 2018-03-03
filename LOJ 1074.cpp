#include<bits/stdc++.h>
using namespace std;
struct edge
{
public:
    int u,v,w;
    edge(int a,int b,int c)
    {
        this->u=a;
        this->v=b;
        this->w=c;
    }
    edge() {};
};
vector<edge>roads;
vector<int>busy(209);
vector<int>dist(209);
int calc(int a,int b)
{
    int x=busy[b]-busy[a];
    x=powl(x,3);
    return x;
}
 
void clean()
{
    for(int i=0; i<209; i++)
        dist[i]=1e9;
    roads.clear();
}
 
void belmen(int n,int m)
{
    dist[1]=0;
    for(int i=0;i<n-1;i++)
        for(int j=0;j<m;j++)
            if(dist[roads[j].u]+roads[j].w<dist[roads[j].v])
                dist[roads[j].v]=dist[roads[j].u]+roads[j].w;
}
 
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int test;
    scanf("%d",&test);
    for(int t=1; t<=test; t++)
    {
        clean();
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d",&busy[i]);
        int m;
        scanf("%d",&m);
        for(int i=0; i<m; i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            roads.push_back(edge(a,b,calc(a,b)));
        }
        belmen(n,m);
        int q,x;
        scanf("%d",&q);
        printf("Case %d:\n",t);
        while(q--)
        {
            scanf("%d",&x);
            if(dist[x]<3 || dist[x]>1e4)
                printf("?\n");
            else
                printf("%d\n",dist[x]);
        }
    }
}
