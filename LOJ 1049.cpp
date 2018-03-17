#include <bits/stdc++.h>
using namespace std;

class edge{
public:
    int v,w;
    edge(){};
    edge(int a,int b){
        this->v=a;
        this->w=b;
    }
};
vector<edge>v[109];
int cost[109][109];

int dfs(int node,int par){
    if(node==1){
        cost[par][1]=0;
    }
    else
    {
        for(int i=0;i<v[node].size();i++){
            edge x=v[node][i];
            if(x.v!=par){
                cost[par][node]= dfs(x.v,node)+x.w;
            }
        }
    }
    return cost[par][node];
}
void clean(){
    for(int i=0;i<109;i++){
        v[i].clear();
    }
    memset(cost,-1,sizeof(cost));
}
int main()
{
    int test;
    scanf("%d\n",&test);
    for(int _t=1; _t<=test; _t++)
    {
        clean();
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            v[a].push_back(edge(b,0));
            v[b].push_back(edge(a,c));
        }
        int x=dfs(v[1][0].v,1)+v[1][0].w;
        int y=dfs(v[1][1].v,1)+v[1][1].w;
        printf("Case %d: %d\n",_t,min(x,y));
    }
}
