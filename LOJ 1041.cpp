#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
vector< pair<int,pair<int,int> > >v;
vector< pair<int,int> >vx[100];
int visited[109];

class DSU
{
    public:
    int n;
    int par[100];
    DSU() {};
    DSU(int k)
    {
        n=k;
        for(int i=0; i<=n; i++)
        {
            par[i]=i;
        }
    }
    int ROOT(int k)
    {
        while(k!=par[k])
        {
            par[k]=par[par[k]];
            k=par[k];
        }
        return k;
    }
    void UNION(int x,int y)
    {
        par[x]=par[y];
    }
};

bool comp(pair<int,pair<int,int> >p1,pair<int,pair<int,int> >p2)
{
    return p1.second.second<p2.second.second;
}


void clean(){
    memset(visited,-1,sizeof visited);
    for(int i=0;i<100;i++)
        vx[i].clear();
    v.clear();
    mp.clear();
}
int BFS(int S)
{
    int s=0;
    visited[S]=0;
    queue< pair<int,int> >q;
    q.push(make_pair(S,0));
    while(!q.empty())
    {
        pair<int,int>pp=q.front();
        q.pop();
        for(int i=0; i<vx[pp.first].size(); i++)
        {
            pair<int,int>pq=vx[pp.first][i];
            if(visited[pq.first]==-1)
            {
                visited[pq.first]=visited[pp.first]+pq.second;
                s+=pq.second;
                q.push(make_pair(pq.first,visited[pq.first]));
            }
        }
    }
    return s;
}
void MST(int n)
{
    DSU g(n);
    sort(v.begin(),v.end(),comp);
    for(int i=0; i<v.size(); i++)
    {
        int tx=g.ROOT(v[i].first);
        int ty=g.ROOT(v[i].second.first);
        if(tx!=ty)
        {
            vx[v[i].first].push_back(make_pair(v[i].second.first,v[i].second.second));
            vx[v[i].second.first].push_back(make_pair(v[i].first,v[i].second.second));
            g.UNION(tx,ty);
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    for(int T=1; T<=test; T++)
    {
        clean();
        string a,b;
        int cost;
        int n;
        int idx=1;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>a>>b>>cost;
            if(mp[a]==0)
                mp[a]=idx++;
            if(mp[b]==0)
                mp[b]=idx++;
            v.push_back(make_pair(mp[a],make_pair(mp[b],cost)));
            v.push_back(make_pair(mp[b],make_pair(mp[a],cost)));
        }
        MST(idx);
        int cnt=0,ans;
        for(int i=1; i<idx; i++)
        {
            if(visited[i]==-1)
            {
                ans=BFS(i);
                cnt++;
            }
            if(cnt>1)
            {
                break;
            }
        }
        printf("Case %d: ",T);
        if(cnt>1)
            printf("Impossible\n");
        else
            printf("%d\n",ans);
    }
}
