#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool visited1[109];
bool visited2[109];
vector<int>ara[109];

void dfs(int n)
{
    visited2[n]=1;
    for(int i=0; i<ara[n].size(); i++)
    {
        if(visited2[ara[n][i]]==0)
        {
            dfs(ara[n][i]);
        }
    }
    return;
}

void bfs()
{
    queue<int>q;
    q.push(0);
    visited2[0]=1;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(int i=0;i<ara[t].size();i++)
        {
            if(visited2[ara[t][i]]==0)
            {
                visited2[ara[t][i]]=1;
                q.push(ara[t][i]);
            }
        }
    }
    return;
}

void pat1(int n)
{
    n=2*n-1;
    printf("+");
    for(int i=0; i<n; i++)
        printf("-");
    printf("+\n");
}

void pat2(int n)
{
    int x=2*n+1,j=0;
    for(int i=0; i<x; i++)
    {
        if(i%2==0)
            printf("|");
        else
        {
            if(visited1[j]^visited2[j])
                printf("Y");
            else
                printf("N");
            j++;
        }
    }
    printf("\n");
}

int main()
{
    int test;
    scanf("%d",&test);
    test++;
    for(int t=1; t<test; t++)
    {
        for(int i=0; i<109; i++)
            ara[i].clear();
        memset(visited1,0,sizeof(visited1));
        memset(visited2,0,sizeof(visited2));
        int n,x;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d",&x);
                if(x==1)
                    ara[i].push_back(j);
            }
        }
        bfs();
        printf("Case %d:\n",t);
        pat1(n);
        pat2(n);
        pat1(n);
        for(int i=0;i<n;i++)
            visited1[i]=visited2[i];
        for(int i=1; i<n; i++)
        {
            memset(visited2,0,sizeof(visited2));
            visited2[i]=1;
            bfs();
            visited2[i]=0;
            pat2(n);
            pat1(n);
        }
    }
}
