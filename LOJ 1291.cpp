#include<bits/stdc++.h>
using namespace std;
const int arrsz=10000;

vector<int>v[arrsz+9];
int low[arrsz+9];
int dis[arrsz+9];
int color[arrsz+9];
int cnt,tim,col;
stack<int>s;
void clean()
{
    while(!s.empty())
        s.pop();
    cnt=tim=col=0;
    memset(color,0,sizeof color);
    memset(low,0,sizeof low);
    memset(dis,-1,sizeof dis);
    for(int i=0; i<arrsz+9; i++)
        v[i].clear();
}
void dfs(int x,int y)
{
    dis[x]=low[x]=++tim;
    s.push(x);
    for(int i=0; i<v[x].size(); i++)
    {
        int xd=v[x][i];
        if(xd==y)
            continue;
        if(dis[xd]==-1)
        {
            dfs(xd,x);
            low[x]=min(low[x],low[xd]);
        }
        else
            low[x]=min(low[x],dis[xd]);
    }
    if(low[x]==dis[x])
    {
        ++col;
        while(!s.empty())
        {
            int qq=s.top();
            s.pop();
            color[qq]=col;
            if(x==qq)
                break;
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
        dfs(0,-1);
        memset(dis,0,sizeof dis);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<(int)v[i].size(); j++)
            {
                if(color[i]!=color[v[i][j]])
                {
                    dis[color[i]]++;
                    dis[color[v[i][j]]]++;
                }
            }
        }
        cnt=0;
        for(int i=0;i<=col;i++){
            if(dis[i]==2)
                cnt++;
        }
        cnt++;
        cnt/=2;
        printf("Case %d: %d\n",T,cnt);
    }
}
