#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class DSU
{
public:
    int n;
    int par[10009];
    DSU() {};
    DSU(int x)
    {
        this->n=x;
        for(int i=0; i<=n; i++)
            par[i]=i;
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
    void UNION_VAL(int x,int y)
    {
        int t1=ROOT(x);
        int t2=ROOT(y);
        par[t1]=par[t2];
    }
    void UNION_PAR(int x,int y)
    {
        par[x]=par[y];
    }
};

class node
{
public:
    int u,v,w;
    node() {};
    node(int a,int b,int c) {
        this->u = a;
        this->v = b;
        this->w = c;
    }
};


bool comp(const node X,const node Y)
{
    return X.w<Y.w;
}

map< pair<int,int>,int >mp;
vector<int>ans;
vector< pair<int,int> >v[10009];
vector<node>vp;
int visited[10009];

void clean()
{
     memset(visited,-1,sizeof visited);
    for(int i=0; i<1009; i++)
        v[i].clear();
    vp.clear();
    mp.clear();
    ans.clear();
}
void MST(int n,int m)
{
    DSU g(n);
    sort(vp.begin(),vp.end(),comp);
    for(int i=0; i<m; i++)
    {
        node t=vp[i];
        int tx=g.ROOT(vp[i].u);
        int ty=g.ROOT(vp[i].v);
        if(tx!=ty)
        {
            g.UNION_PAR(tx,ty);
            v[t.u].push_back(make_pair(t.v,t.w));
            v[t.v].push_back(make_pair(t.u,t.w));
        }
    }
}

void bfs(int n)
{
    queue< pair<int,int> >q;
    q.push(make_pair(n,0));
    visited[n]=0;
    while(q.size())
    {
        pair<int,int>p=q.front();
        q.pop();
        for(int i=0; i<v[p.first].size(); i++)
        {
            pair<int,int>tx=v[p.first][i];
            if(visited[tx.first]==-1)
            {
                mp[make_pair(tx.first,p.first)]=1;
                mp[make_pair(p.first,tx.first)]=1;
                visited[tx.first]=visited[p.first]+tx.second;
                q.push(make_pair(tx.first,visited[tx.first]));
            }
        }
    }

}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)==2 and n+m>0)
    {
        clean();
        for(int i=0; i<m; i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            vp.push_back(node(a,b,c));
        }
        MST(n,m);
        for(int i=0;i<n;i++)
        {
            if(visited[i]==-1)
                bfs(i);
        }
        for(int i=0;i<m;i++)
        {
            if(mp[make_pair(vp[i].u,vp[i].v)]==0 and mp[make_pair(vp[i].v,vp[i].u)]==0)
            {
                ans.push_back(vp[i].w);
                mp[make_pair(vp[i].u,vp[i].v)]=1;
                mp[make_pair(vp[i].v,vp[i].u)]=1;
            }
        }
        if(ans.size())
        {
            for(int i=0;i<ans.size();i++)
                {
                    cout<<ans[i];
                    if(i!=ans.size()-1)
                        cout<<" ";
                }
        }
        else
            cout<<"forest";
        cout<<endl;
    }
}
