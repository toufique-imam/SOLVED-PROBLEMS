/*
ID:sabertooth
TASK:SPOj ADACYCLE
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int  inf = 0x3f3f3f3f;
vector< vector<int> >v;
int visited[10000];

void rest(int n)
{
    v=vector< vector<int> >(n+9);
}

bool bfs(int source)
{
    memset(visited,-1,sizeof(visited));
    queue<int>q;
    q.push(source);
    visited[source]=0;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(int i=0;i<v[t].size();i++)
        {
            int x=v[t][i];
            if(visited[x]==-1)
            {
                visited[x]=visited[t]+1;
                q.push(x);
            }
            else if(visited[x]!=-1 && x==source)
            {
                visited[x]=visited[t]+1;
                return 1;
            }
        }
    }
    return 0;
}

int main ()
{
    int n,i,j,a;
    scanf("%d",&n);
    rest(n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a);
            if(a)
            {
                v[i].push_back(j);
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        if(bfs(i))
            printf("%d\n",visited[i]);
        else
            printf("NO WAY\n");
    }
}
