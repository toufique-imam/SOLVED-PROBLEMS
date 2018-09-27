#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int>v[309];
int visited[309];

int bfs(int x)
{
    queue<int>q;
    q.push(x);
    visited[x]=1;
    while(q.size())
    {
        int t=q.front();
        q.pop();
        for(int i=0; i<v[t].size(); i++)
        {
            int p=v[t][i];
            if(visited[p]==-1)
            {
                q.push(p);
                visited[p]=!(visited[t] & 1);
            }
            else if(visited[p]==visited[t])
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int n;
    while(scanf("%d",&n)==1 and n)
    {
        int a,b;
        for(int i=0; i<309; i++)
            v[i].clear();
        memset(visited,-1,sizeof visited);
        while(scanf("%d %d",&a,&b)==2 and (a or b))
        {
            v[a].push_back(b);
            v[b].push_back(a);
        }
        bool f=1;
        for(int i=1; i<=n; i++)
        {
            if(visited[i]==-1)
            {
                if(!bfs(i))
                {
                    f=0;
                    break;
                }
            }
        }
        if(f)
            puts("YES");
        else
            puts("NO");
    }
}
