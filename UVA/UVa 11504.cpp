#include<bits/stdc++.h>
using namespace std;

vector<int>v[100009];
int dis[100009];
stack<int>S;

int tim,scc;
void clean()
{
    while(S.size())S.pop();
    for(int i=0;i<100009;i++)
    {
        v[i].clear();
    }
    tim=scc=0;
    //memset(low,0,sizeof low);
    memset(dis,-1,sizeof dis);
}
void DFS1(int u)
{
    dis[u]=++tim;
    //S.push(u);
    for(int i:v[u])
    {
        if(dis[i]==-1)
            DFS1(i);
    }
    S.push(u);
    //++tim;
    //vx.push_back(make_pair(u,tim));
}

void DFS2(int u)
{
    dis[u]=1;
    for(int i:v[u])
    {
        if(dis[i]==0)
            DFS2(i);
    }
}
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        clean();
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
        }
        for(int i=1;i<=n;i++)
        {
            if(dis[i]==-1)
                DFS1(i);
        }
        int cnt=0;
        memset(dis,0,sizeof dis);
        while(S.size())
        {
            int t=S.top();
            S.pop();
            if(!dis[t])
            {
                cnt++;
                DFS2(t);
            }
        }
        printf("%d\n",cnt);
    }
}
