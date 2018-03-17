#include<bits/stdc++.h>
using namespace std;

int par[109];
int tim;
vector<int>v[109];
int dis[109];
int low[109];
bool articulation[109];
int child;
void dfs(int x,int old,int root)
{
    low[x]=dis[x]=++tim;
    par[x]=old;
    for(int i:v[x])
    {
        if(i==old)
            continue;
        if(par[i]!=-1)
            low[x]=min(low[x],dis[i]);
        else
        {
            dfs(i,x,root);
            low[x]=min(low[x],low[i]);
            if(x==root)
                child++;
            else if(x!=root and low[i]>=dis[x])
                articulation[x]=1;
            low[x]=min(low[x],low[i]);
        }
    }
}
int articulation_points(int n)
{
    tim=0;
    for(int i=1; i<=n; i++)
    {
        if(par[i]==-1)
        {
            child=0;
            dfs(i,i,i);
            if(child>1)
                articulation[i]=1;
        }
    }
    int cnt=0;
    for(int i=1; i<=n; i++)
        if(articulation[i])
            cnt++;
    return cnt;
}

void clean()
{
    memset(low,0,sizeof low);
    memset(articulation,0,sizeof articulation);
    memset(par,-1,sizeof par);
    memset(dis,0,sizeof dis);
    for(int i=0; i<109; i++)
    {
        v[i].clear();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin>>n and n)
    {
        clean();
        //Graph g1(n+3);
        string s;
        stringstream ss;
        while(getline(cin,s) and s[0]!='0')
        {
            int a,b;
            stringstream ss(s);
            ss>>a;
            while(ss>>b)
            {
                v[a].push_back(b);
                v[b].push_back(a);
            }
        }
        cout<<articulation_points(n)<<endl;
    }
}
