#include<bits/stdc++.h>
using namespace std;

bool visited[10009];
vector<int>v[10009];
stack<int>s;
void dfs1(int u)
{
    visited[u]=1;
    for(int i=0; i<v[u].size(); i++)
    {
        if(visited[v[u][i]]==0)
        {
            dfs1(v[u][i]);
        }
    }
    s.push(u);
}
void dfs2(int u)
{
    visited[u]=1;
    for(int i=0; i<v[u].size(); i++)
    {
        if(visited[v[u][i]]==0)
        {
            dfs1(v[u][i]);
        }
    }
    return;
}

void clean()
{
    while(!s.empty())
        s.pop();
    for(int i=0; i<10009; i++)
    {
        v[i].clear();
    }
    memset(visited,0,sizeof visited);
}
int main()
{
    int Test;
    scanf("%d",&Test);
    for(int T=1; T<=Test; T++)
    {
        clean();
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0; i<m; i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
        }
        for(int i=1; i<=n; i++)
        {
            if(!visited[i])
            {
                dfs1(i);
            }
        }
        int cnt=0;
        memset(visited,0,sizeof visited);
        while(!s.empty())
        {
            int t=s.top();
            s.pop();
            if(!visited[t])
            {
                cnt++;
                dfs2(t);
            }
        }
        printf("Case %d: %d\n",T,cnt);
    }
}
