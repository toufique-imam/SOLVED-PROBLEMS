#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<int>v[209];
int visited[209];
int ans[2];
void clean()
{
    for(int i=0; i<209; i++)
    {
        v[i].clear();
    }
    memset(ans,0,sizeof ans);
    memset(visited,-1,sizeof visited);
}

int bfs(int x)
{
    memset(ans,0,sizeof ans);
    queue<int>q;
    q.push(x);
    visited[x]=0;
    ans[visited[x]]++;
    while(q.size())
    {
        int t=q.front();
        q.pop();
        for(int i=0; i<v[t].size(); i++)
        {
            int px=v[t][i];
            if(visited[px]==-1)
            {
                visited[px]=!(visited[t] & 1);
                q.push(px);
                ans[visited[px]]++;
            }
            else if(visited[px]==visited[t])
                return -1;
        }
    }
    return 1;
}
int main()
{
/*    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    int test;
    scanf("%d",&test);
    for(int _t=1; _t<=test; _t++)
    {
        clean();
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0; i<m; i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        bool f=1;
        int tc=0;
        for(int i=0; i<n; i++)
        {
            if(visited[i]==-1)
            {
                int x=bfs(i);
                if(x==-1)
                {
                    f=0;
                    break;
                }
                else
                {
                    tc+=max(1,min(ans[0],ans[1]));
                }
            }
        }
        if(f)
            printf("%d\n",tc);
        else
            printf("-1\n");
    }
}
