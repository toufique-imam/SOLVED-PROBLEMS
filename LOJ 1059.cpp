#include <bits/stdc++.h>
using namespace std;

const int N=10000;
int n,m,a,cnt;
vector< pair<int,int> >v[N+9];
int visited[N+9];
vector< pair<int, pair<int,int> > >vp;
class DSU
{
public:

    int n;
    int par[N+9];
    DSU(){};
    DSU(int x)
    {
        n=x;
        for(int i=0;i<=n;i++)
            par[i]=i;
    }
    int ROOT(int x)
    {
        while(x!=par[x])
        {
            par[x]=par[par[x]];
            x=par[x];
        }
        return x;
    }
    void UNION(int x,int y)
    {
        par[x]=par[y];
    }
};

bool comp(pair<int, pair<int,int> >p1,pair<int,pair<int,int> >p2)
{
    return p1.second.second<p2.second.second;
}
void MST()
{
    sort(vp.begin(),vp.end(),comp);
    DSU g(n);
    for(int i=0;i<m;i++)
    {
        int uu=vp[i].first;
        int vv=vp[i].second.first;
        int tx=g.ROOT(uu);
        int ty=g.ROOT(vv);
        if(tx!=ty)
        {
            g.UNION(tx,ty);
            v[uu].push_back(make_pair(vv,vp[i].second.second));
            v[vv].push_back(make_pair(uu,vp[i].second.second));
        }
    }
}
int bfs(int x)
{
    visited[x]=0;
    queue<int>q;
    q.push(x);
    int cost=a;
    cnt++;
    while(!q.empty())
    {
        int tx=q.front();
        q.pop();
        for(int i=0;i<v[tx].size();i++)
        {
            int px=v[tx][i].first;
            int py=v[tx][i].second;
            if(visited[px]==-1)
            {
                if(py>=a)
                {
                    cnt++;
                    cost+=a;
                }
                else
                {
                    cost+=py;
                }
                visited[px]=0;
                q.push(px);
            }
        }
    }
    return cost;
}
void clean()
{
    n=m=a=cnt=0;
    vp.clear();
    memset(visited,-1,sizeof visited);
    for(int i=0;i<=N;i++)v[i].clear();
}


int main()
{
    int test;
    scanf("%d",&test);
    for(int _t=1;_t<=test;_t++)
    {
        clean();
        int x,y,c;
        scanf("%d %d %d",&n,&m,&a);
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&x,&y,&c);
            vp.push_back(make_pair(x,make_pair(y,c)));
        }
        MST();
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(visited[i]==-1)
            {
                ans+=bfs(i);
            }
        }
        printf("Case %d: %d %d\n",_t,ans,cnt);
    }
}
