#include<bits/stdc++.h>
using namespace std;
 
const int arrsize=1000;
class edge
{
public:
    int u,x,w;
    edge(int a,int b,int c)
    {
        u=a,x=b,w=c;
    }
    edge() {};
};
 
vector<edge>v;
vector<int>ansr;
bool visited[arrsize+9];
int dist[arrsize+9];
vector<int>rev_edge[arrsize+9];
void clean();
void dfs(int s);
bool belmenford(int n,int m);
 
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int test;
    scanf("%d",&test);
    for(int t=1; t<=test; t++)
    {
        clean();
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0; i<m; i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            rev_edge[b].push_back(a);
            v.push_back(edge(b,a,c));
        }
        printf("Case %d: ",t);
        if(belmenford(n,m))
        {
            sort(ansr.begin(),ansr.end());
            for(int i=0; i<ansr.size(); i++)
            {
                printf("%d",ansr[i]);
                if(i!=ansr.size()-1)
                    printf(" ");
            }
        }
        else
        {
            printf("impossible");
        }
        printf("\n");
    }
}
 
void dfs(int s)
{
    visited[s]=1;
    ansr.push_back(s);
    for(int i=0; i<rev_edge[s].size(); i++)
    {
        if(visited[rev_edge[s][i]]==0)
        {
            dfs(rev_edge[s][i]);
        }
    }
}
 
 
void clean()
{
    ansr.clear();
    v.clear();
    memset(visited,0,sizeof(visited));
    for(int i=0; i<=arrsize; i++)
    {
        rev_edge[i].clear();
    }
    fill(dist,dist+arrsize+9,1e8);
}
 
bool belmenford(int n,int m)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(dist[v[j].u]+v[j].w<dist[v[j].x])
                dist[v[j].x]=dist[v[j].u]+v[j].w;
 
        }
    }
    bool ans=0;
    for(int j=0; j<m; j++)
    {
        if(dist[v[j].u]+v[j].w<dist[v[j].x])
        {
            ans=1;
            dist[v[j].x]=dist[v[j].u]+v[j].w;
            if(!visited[v[j].u])
                dfs(v[j].u);
        }
    }
    return ans;
}
