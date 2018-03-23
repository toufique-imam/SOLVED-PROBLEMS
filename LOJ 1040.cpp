#include<bits/stdc++.h>
using namespace std;
int room[60][60];
vector< pair<int,pair<int,int> > >v;
vector< pair<int,int> >vx[60];
int visited[209];

void clean()
{
    v.clear();
    memset(visited,-1,sizeof visited);
    for(int i=0;i<60;i++)vx[i].clear();
}

int bfs(int x)
{
    int s=0;
    visited[x]=0;
    queue< pair<int,int> >q;
    q.push(make_pair(x,0));
    while(q.size())
    {
        pair<int,int> t=q.front();
        q.pop();
        for(int i=0;i<(int)vx[t.first].size();i++)
        {
            pair<int,int> p=vx[t.first][i];
            if(visited[p.first]==-1)
            {
                s+=p.second;
                visited[p.first]=visited[t.first]+p.second;
                q.push(make_pair(p.first,visited[p.first]));
            }
        }
    }
    return s;
}
class DSU{
    public:
    int n;
    int par[209];
    DSU(){};
    DSU(int k)
    {
        n=k;
        for(int i=0;i<n;i++)
        {
            par[i]=i;
        }
    }
    void UNION(int x,int y)
    {
        par[x]=par[y];
    }
    int ROOT(int x)
    {
        while(par[x]!=x)
        {
            par[x]=par[par[x]];
            x=par[x];
        }
        return x;
    }
};
bool comp(pair<int,pair<int,int> >p1,pair<int,pair<int,int> >p2)
{
    return p1.second.second<p2.second.second;
}
void MST(int n)
{
    DSU g(n);
    sort(v.begin(),v.end(),comp);
    for(int i=0;i<(int)v.size();i++)
    {
        pair< int,pair<int,int> >p=v[i];
        int tx=g.ROOT(p.first);
        int ty=g.ROOT(p.second.first);
        if(tx!=ty)
        {
            g.UNION(tx,ty);
            vx[p.first].push_back(make_pair(p.second.first,p.second.second));
            vx[p.second.first].push_back(make_pair(p.first,p.second.second));
        }
    }
}


int main()
{
    int test;
    scanf("%d",&test);
    for(int T=1; T<=test; T++)
    {
        int fs=0;
        int n;
        clean();
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                scanf("%d",&room[i][j]);
                fs+=room[i][j];
                if(room[i][j]>0 and i!=j)
                {
                    v.push_back(make_pair(i,make_pair(j,room[i][j])));
                    v.push_back(make_pair(j,make_pair(i,room[i][j])));
                }
            }
        MST(n);
        int ans=fs-bfs(0);
        for(int i=0;i<n;i++)
        {
            if(visited[i]==-1)
            {
                ans=-1;
                break;
            }
        }
        printf("Case %d: %d\n",T,ans);
    }
}
