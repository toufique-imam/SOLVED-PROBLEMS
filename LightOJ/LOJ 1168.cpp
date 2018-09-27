#include <bits/stdc++.h>
using namespace std;
vector<int>v[1009];
int outdegree[1009];
int dis[1009];
int low[1009];
bool instack[1009];
int color[1009];
stack<int>s;
int tim,col,no_of_one;
vector< pair<int,int> >edge;
void clean()
{
    memset(outdegree,0,sizeof outdegree);
    edge.clear();
    while(!s.empty())
        s.pop();
    memset(instack,0,sizeof instack);
    tim=col=no_of_one=0;
    memset(low,-1,sizeof low);
    memset(dis,-1,sizeof dis);
    for(int i=0; i<1009; i++)
        v[i].clear();
}

void dfs(int u)
{
    s.push(u);
    instack[u]=1;
    dis[u]=low[u]=++tim;
    for(int i=0; i<v[u].size(); i++)
    {
        int t=v[u][i];
        //if(t==par)continue;
        if(dis[t]==-1)
            dfs(t);
        if(dis[t]!=-1 and instack[t]==1)
            low[u]=min(low[u],low[t]);
    }
    if(low[u]==dis[u])
    {
        ++col;
        while(!s.empty())
        {
            int t=s.top();
            s.pop();
            instack[t]=0;
            color[t]=col;
            if(t==0)
                no_of_one=col;
            if(t==u)
                break;
        }
    }
}

void dfs2(int u)
{
    dis[u]=1;
    for(int i=0; i<v[u].size(); i++)
    {
        int t=v[u][i];
        if(dis[t]==0)
            dfs2(t);
    }
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int _t=1; _t<=test; _t++)
    {
        clean();
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            int x;
            scanf("%d",&x);
            for(int j=0; j<x; j++)
            {
                int a,b;
                scanf("%d %d",&a,&b);
                v[a].push_back(b);
                edge.push_back(make_pair(a,b));
            }
        }
        bool f=1;
        for(int i=0;i<edge.size();i++)
        {
            if(dis[edge[i].first]==-1)
                dfs(edge[i].first);
        }
        memset(dis,0,sizeof dis);
            for(int i=0; i<1009; i++)
        v[i].clear();
        for(int i=0; i<edge.size(); i++)
        {
            int u=edge[i].first;
            int vv=edge[i].second;
            if(color[u]!=color[vv])
            {
                outdegree[color[u]]++;
                if(outdegree[color[u]]>1)
                    f=0;
                v[color[u]].push_back(color[vv]);
            }
        }
        if(f)
        {
            dfs2(no_of_one);
            for(int i=1; i<=col; i++)
                if(dis[i]==0)
                {
                    f=0;
                    break;
                }
        }
        printf("Case %d: ",_t);
        if(f)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
