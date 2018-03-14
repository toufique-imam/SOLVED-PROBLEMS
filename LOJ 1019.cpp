#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class edge
{
public:
    int u,w;
    edge(int n,int m)
    {
        this->u=n;
        this->w=m;
    }
    edge() {};
    bool operator < (const edge &x) const
    {
        return this->w>x.w;
    }
};

vector<edge>v[109];
vector<int>dist(109);
void clean(){
    for(int i=0;i<109;i++){
        v[i].clear();
        dist[i]=1e9;
    }
    return;
}
void dijkastra(){
    priority_queue<edge>pq;
    pq.push(edge(1,0));
    dist[1]=0;
    while(pq.size()){
        edge tx=pq.top();
        pq.pop();
        for(int i=0;i<v[tx.u].size();i++){
            edge px=v[tx.u][i];
            if(dist[px.u]>dist[tx.u]+px.w){
                dist[px.u]=dist[tx.u]+px.w;
                pq.push(edge(px.u,dist[px.u]));
            }
        }
    }
}

int main()
{
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
            v[a].push_back(edge(b,c));
            v[b].push_back(edge(a,c));
        }
        dijkastra();
        printf("Case %d: ",_t);
        if(dist[n]==1e9){
            printf("Impossible\n");
        }
        else{
            printf("%d\n",dist[n]);
        }
    }
}
