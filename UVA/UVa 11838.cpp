#include<bits/stdc++.h>
using namespace std;
vector<int>v[2009];
int low[1009];
int dis[1009];
bool visited[1009];
int tim;
int SCC,cnt;
stack<int>ans;
void clean()
{
    for(int i=0; i<1009; i++)
    {
        v[i].clear();
    }
    SCC=0;
    tim=0;
    memset(low,0,sizeof low);
    memset(dis,0,sizeof dis);
    memset(visited,0,sizeof visited);
}
void dfs(int u)
{
    low[u]=dis[u]=++tim;
    visited[u]=1;
    ans.push(u);
    for(int i=0; i<v[u].size(); i++)
    {
        int xx=v[u][i];
        if(!visited[xx])
            dfs(xx);
        if(visited[xx])
            low[u]=min(low[u],low[xx]);
    }
    if(low[u]==dis[u])
    {
        SCC++;
        cnt=0;
        while(1)
        {
            int _x=ans.top();
            cnt++;
            ans.pop();
            if(_x==u)
                break;
        }
    }
}

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)==2 and n+m>0)
    {
        clean();
        int a,b,q;
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&a,&b,&q);
            if(q==2)
            {
                v[a].push_back(b);
                v[b].push_back(a);
            }
            else
                v[a].push_back(b);
        }
        dfs(1);
        if(SCC==1 and cnt==n)
            puts("1");
        else
            puts("0");
    }
}
