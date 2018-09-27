#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,d;
int dist[11][10009];
class edge
{
public:
    int u,w,type,used;
    edge() {};
    edge(int a,int b,int c)
    {
        u=a;
        w=b;
        type=c;
    }
    edge(int a,int b,int c,int d)
    {
        u=a;
        w=b;
        type=c;
        used =d;
    }
    bool operator < (const edge &x) const
    {
        if(type==x.type)
            return this->w > x.w;
        return this->type>x.type;
    }
};

vector<edge>v[10009];

void clean()
{
    for(int i=0; i<10000; i++)
    {
        v[i].clear();
    }
    memset(dist,63,sizeof(dist));
}

void dijkstra()
{
    dist[0][0]=0;
    priority_queue<edge>pq;
    pq.push(edge(0,0,0,0));
    while(pq.size())
    {
        edge t=pq.top();
        pq.pop();
        for(int i=0; i<v[t.u].size(); i++)
        {
            edge x=v[t.u][i];
            if(x.type)
            {
                if(d>t.used and dist[t.used+1][x.u]>dist[t.used][t.u]+x.w)
                {
                    dist[t.used+1][x.u]=dist[t.used][t.u]+x.w;
                    pq.push(edge(x.u,dist[t.used+1][x.u],1,t.used+1));
                }
            }
            else
            {
                if(dist[t.used][x.u]>dist[t.used][t.u]+x.w)
                {
                    dist[t.used][x.u]=dist[t.used][t.u]+x.w;
                    pq.push(edge(x.u,dist[t.used][x.u],0,t.used));
                }
            }
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
        scanf("%d %d %d %d",&n,&m,&k,&d);
        for(int i=0;i<m;i++){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            v[a].push_back(edge(b,c,0));
        }
        for(int i=0;i<k;i++){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            v[a].push_back(edge(b,c,1));
        }
        bool f=0;
        int ans=1061109567;
        dijkstra();
        for(int i=0;i<=d;i++){
            if(dist[i][n-1]!=1061109567){
                f=1;
                ans=min(ans,dist[i][n-1]);
            }
        }
        printf("Case %d: ",_t);
        if(f)
            printf("%d\n",ans);
        else
            printf("Impossible\n");
    }
}
