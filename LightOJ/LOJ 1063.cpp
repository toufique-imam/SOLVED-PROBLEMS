#include <bits/stdc++.h>
using namespace std;

vector<int>v[10009];
int visited[10009];
int ti;
int low[10009];
int child[10009];

void clean()
{
    for(int i=0; i<10009; i++)
        v[i].clear();
    memset(low,0,sizeof low);
    memset(visited,0,sizeof visited);
    memset(child,0,sizeof child);
}

void dfs(int x,int pa)
{
    visited[x]=low[x]=++ti;
    child[x]=1;
    for(int i=0; i<v[x].size(); i++)
    {
        int px=v[x][i];
        if(px==pa)
            continue;
        else if(visited[px])
            low[x]=min(visited[px],low[x]);
        else
        {
            dfs(px,x);
            low[x]=min(low[x],low[px]);
            if(low[px]>=visited[x])
                child[x]++;
        }
    }
}


int main()
{
    int test;
    scanf("%d",&test);
    for(int T=1; T<=test; T++)
    {
        clean();
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0; i<m; i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(1,1);
        int cnt=0;
        child[1]--;
        for(int i=1;i<=n;i++)
        {
            if(child[i]>1)
                cnt++;
        }
        printf("Case %d: %d\n",T,cnt);
    }
}
