#include<bits/stdc++.h>
using namespace std;

struct node
{
    int u,v,w;
    node() {};
    node(int a,int b,int c)
    {
        u=a;
        v=b;
        w=c;
    }
};
int power[109];
vector<int>v[109];
vector<node>vx;
bool visited[109];
int dist[109];
void clean()
{
    memset(visited,0,sizeof visited);
    for(int i=0; i<109; i++)
    {
        v[i].clear();
        dist[i]=1e9;
    }
    vx.clear();
    memset(power,0,sizeof power);
}

bool bfs(int s,int z){
    queue<int>q;
    q.push(s);
    visited[s]=1;
    while(q.size()){
        int t=q.front();
        q.pop();
        if(t==z)
            return 1;
        for(int i=0;i<v[t].size();i++){
            int p=v[t][i];
            if(!visited[p]){
                visited[p]=1;
                q.push(p);
            }
        }
    }
    return 0;
}

int main()
{
    int n,cnt;
    while(scanf("%d",&n)==1 and n>=0)
    {
        cnt=0;
        clean();
        for(int i=1; i<=n; i++)
        {
            int a,b,c;
            scanf("%d %d",&a,&b);
            power[i]=-a;
            cnt+=b;
            for(int j=0; j<b; j++)
            {
                scanf("%d",&c);
                v[i].push_back(c);
            }
        }
        dist[1]=0;
        for(int i=1; i<=n; i++)
            for(int j=0; j<v[i].size(); j++)
                vx.push_back(node(i,v[i][j],power[v[i][j]]));
        for(int i=1; i<n; i++)
            for(int j=0; j<cnt; j++)
                if(dist[vx[j].v]>dist[vx[j].u]+vx[j].w and !(dist[vx[j].u]+vx[j].w>=100))
                    dist[vx[j].v]=dist[vx[j].u]+vx[j].w;
        bool cycle=false;
        for(int i=1;i<n and !cycle;i++)
            for(int j=0;j<cnt and !cycle;j++)
                if(dist[vx[j].v]>dist[vx[j].u]+vx[j].w and !(dist[vx[j].u]+vx[j].w>=100))
                    cycle=bfs(vx[j].v,n);
        if(cycle or dist[n]<=100){
            printf("winnable\n");
        }
        else
            printf("hopeless\n");
    }
}
