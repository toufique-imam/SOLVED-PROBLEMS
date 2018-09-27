#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>v[109];
bool visited[109];
vector<int>ans;
void clean()
{
    for(int i=0; i<109; i++)
    {
        v[i].clear();
    }
    ans.clear();
    memset(visited,0,sizeof visited);
}

void dfs(int n)
{
    visited[n]=1;
    for(int i=0; i<v[n].size(); i++)
    {
        if(!visited[v[n][i]])
            dfs(v[n][i]);
    }
    ans.push_back(n);
}
int main()
{
    //freopen("output.txt","w",stdout);
    int n,m;
    while(scanf("%d %d",&n,&m)==2 and n or m)
    {
        clean();
        for(int i=0; i<m; i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
        }
        for(int i=1; i<=n; i++)
        {
            if(!visited[i])
            {
                dfs(i);
            }
        }
        //cout<<"out"<<endl;
        for(int i=ans.size()-1; i>-1; i--)
        {
            printf("%d",ans[i]);
            if(i!=0)
                printf(" ");
        }
        puts("");
    }
}
