/*
ID:sabertooth
TASK:SPOJ DIGOKEYS - Find the Treasure
LANG: C++11
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N= 100000;
const int  inf = 0x3f3f3f3f;
vector< vector<int> >v;
vector< int >path;
int visited[N+9];

void rest(int n)
{
    path=vector< int >(n+9);
    v=vector< vector<int> >(n+9);
    memset(visited,-1,sizeof(visited));
}

void bfs()
{
    queue<int>q;
    q.push(1);
    visited[1]=0;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(int i=0; i<v[t].size(); i++)
        {
            int x=v[t][i];
            if(visited[x]==-1)
            {
                visited[x]=visited[t]+1;
                q.push(x);
                path[x]=t;
            }
        }
    }
}

bool solve_path(vector<int>&fin,int n)
{
    if(visited[n]==-1)
        return 0;
    else
    {
        int m;
        for(int i=path[n];; i=path[i])
        {
            fin.push_back(i);
            if(i==1)
                break;
        }
        return 1;
    }
}

void sorrt(int n)
{
    for(int i=0;i<=n;i++)
    {
        if(v[i].size())
        {
            sort(v[i].begin(),v[i].end());
        }
    }
}
int main ()
{
    int test;
    scanf("%d",&test);
    int t;
    for(t=0; t<test; t++)
    {
        int n;
        scanf("%d",&n);
        rest(n);
        int i,j,m,a,b;
        for(i=1; i<n; i++)
        {
            scanf("%d",&m);
            for(j=0; j<m; j++)
            {
                scanf("%d",&a);
                v[i].push_back(a);
            }
        }
        sorrt(n);
        bfs();
        vector<int>ans;
        if(solve_path(ans,n))
        {
            printf("%d\n",visited[n]);
            for(int qw=ans.size()-1; qw>-1; qw--)
            {
                printf("%d",ans[qw]);
                if(qw!=0)
                    printf(" ");
            }
        }
        else
            printf("-1");
        if(t!=test-1)
            printf("\n\n");
    }
}
