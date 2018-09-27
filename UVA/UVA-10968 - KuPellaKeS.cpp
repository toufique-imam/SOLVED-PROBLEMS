/*
ID:sabertooth
TASK:uva-10968
LANG: C++11
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1000;

vector< int >v[N+9];
int visited[N+9];
void rest()
{
    for(int i=0; i<=N; i++)
        v[i].clear();
    memset(visited,-1,sizeof(visited));
}


bool big2(int n)
{
    for(int i=1; i<=n; i++)
    {
        if(v[i].size()<2)
            return 1;
    }
    return 0;
}

int solve(int n)
{
    queue<int>q;
    int m=-1;
    //int visited[n+9];
    //memset(visited,-1,sizeof(visited));
    for(int i=1; i<=n; i++)
        if(v[i].size() &1)
        {
            q.push(i);
            visited[i]=0;
            m=max(m,0);
            break;
        }
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(int i=0; i<v[t].size(); i++)
        {
            int x=v[t][i];
            if(visited[x]==-1 && v[x].size()!=2)
            {
                visited[x]=visited[t]+1;
                q.push(x);
                if(v[x].size() & 1)
                    m=max(m,visited[x]);
            }
        }
    }
    return m;
}

int main ()
{
    int n,m,a,b;
    while(scanf("%d %d",&n,&m)==2)
    {
        rest();
        if(n==0 && m==0)
            break;
        int i,j;
        for(i=0; i<m; i++)
        {
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        if(big2(n))
            printf("Poor Koorosh\n");
        else
        {
            int ans=solve(n);
            if(ans==-1)
                printf("0\n");
            else if(ans==0)
            {
                printf("Poor Koorosh\n");
            }
            else
            {
                bool f=0;
                for(i=1; i<=n; i++)
                {
                    if(visited[i]==-1 && v[i].size()!=2)
                    {
                        f=1;
                        break;
                    }
                }
                if(f)
                    printf("Poor Koorosh\n");
                else
                    printf("%d\n",ans);
            }
        }
    }
}
