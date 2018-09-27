#include<bits/stdc++.h>
using namespace std;
class DSU{
public:
    int n;
    int par[200009];
    DSU(){};
    DSU(int n)
    {
        this->n=n;
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
    void UNION_par(int x,int y)
    {
        par[x]=par[y];
    }
    void UNION(int x,int y)
    {
        int tx=ROOT(x);
        int ty=ROOT(y);
        par[tx]=par[ty];
    }
};
class NODE{
public:
    int u,v,w;
    NODE(){};
    NODE(int a,int b,int c)
    {
        this->u=a;
        this->v=b;
        this->w=c;
    }
};

bool comp (const NODE X,const NODE Y)
{
    return Y.w > X.w;
}
vector<NODE>vp;
map<pair<int,int>,bool>mp;
vector< pair<int,int> >v[200009];
int visited[200009];

void clean()
{
    mp.clear();
    for(int i=0;i<200009;i++)
        v[i].clear();
    memset(visited,-1,sizeof visited);
    vp.clear();
}
int bfs(int n)
{
    int cnt=0;
    visited[n]=0;
    queue< pair<int,int> >q;
    q.push(make_pair(n,0));
    while(q.size())
    {
        auto t=q.front();
        q.pop();
        for(int i=0;i<v[t.first].size();i++)
        {
            auto p=v[t.first][i];
            if(visited[p.first]==-1)
            {
                mp[make_pair(p.first,t.first)]=1;
                mp[make_pair(t.first,p.first)]=1;
                visited[p.first]=visited[t.first]+p.second;
                q.push(make_pair(p.first,visited[p.first]));
                cnt+=p.second;
            }
        }
    }
    return cnt;
}

void MST(int n)
{
    DSU G(n);
    sort(vp.begin(),vp.end(),comp);
    for(auto i:vp)
    {
        int tx=G.ROOT(i.v);
        int ty=G.ROOT(i.u);
        if(tx!=ty)
        {
            G.UNION_par(tx,ty);
            v[i.u].push_back(make_pair(i.v,i.w));
            v[i.v].push_back(make_pair(i.u,i.w));
        }
    }
    return;
}
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)==2 and n+m>0){
        int a,b,c,s;
        s=0;
        clean();
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            vp.push_back(NODE(a,b,c));
            s+=c;
        }
        MST(n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==-1)
                ans+=bfs(i);
        }
        printf("%d\n",s-ans);
    }
}
