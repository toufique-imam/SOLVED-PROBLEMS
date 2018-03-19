#include<bits/stdc++.h>
using namespace std;

vector< pair<int,int> >vp;
vector<int>v[100009];
int dis[100009];
int low[100009];
int ti,sc;
stack<int>S;
int gone[100009];
bool instack[100009];
void clean()
{
    vp.clear();
    ti=sc=0;
    while(S.size())
        S.pop();
    for(int i=0; i<100009; i++)
    {
        v[i].clear();
    }
    memset(instack,0,sizeof instack);
    memset(gone,-1,sizeof gone);
    memset(dis,-1,sizeof dis);
    memset(low,0,sizeof low);
}


void dfs1(int u)
{
    instack[u]=1;
    S.push(u);
    dis[u]=low[u]=++ti;
    for(int i=0;i<v[u].size();i++)
    {
        int t1=v[u][i];
        if(dis[t1]==-1)
            dfs1(t1);
        if(dis[t1]!=-1 and instack[t1])
            low[u]=min(low[t1],low[u]);
    }
    if(dis[u]==low[u])
    {
        while(1)
        {
            int x=S.top();
            S.pop();
            instack[x]=0;
            gone[x]=sc;
            if(x==u)
                break;
        }
        sc++;
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
            vp.push_back(make_pair(a,b));
        }
        for(int i=1; i<=n; i++)
        {
            if(dis[i]==-1)
                dfs1(i);
        }
        printf("Case %d: ",T);
        if(sc>1)
        {
            memset(dis,0,sizeof dis);
            memset(low,0,sizeof low);
            for(int i=0; i<m; i++)
            {
                if(gone[vp[i].first]!=gone[vp[i].second])
                {
                    dis[gone[vp[i].first]]++;
                    low[gone[vp[i].second]]++;
                }
            }
            int cnt1,cnt2;
            cnt1=cnt2=0;
            for(int i=0; i<sc; i++)
            {
                if(dis[i]==0)
                    cnt1++;
                if(low[i]==0)
                    cnt2++;
            }
            printf("%d\n",max(cnt1,cnt2));
        }
        else
            printf("0\n");
    }
}
