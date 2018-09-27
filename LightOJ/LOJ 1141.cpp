#include<bits/stdc++.h>
using namespace std;

int ax[]= {1,-1,0,0};
int ay[]= {0,0,1,-1};

bool valid(int x,int y,int n,int m)
{
    return (x>-1 && y>-1 && x<n && y<m);
}

bool isprime[1009];
int visited[10009];
vector<int>prime;
void seive()
{
    for(int i=3;i*i<=1000;i+=2)
        if(!isprime[i])
            for(int j=i*i;j<=1000;j+=i)
                isprime[j]=1;
    prime.push_back(2);
    for(int i=3;i<=1000;i+=2)
        if(!isprime[i])
            prime.push_back(i);
    return;
}
int bfs(int from,int to)
{
    visited[from]=0;
    queue<int>q;
    q.push(from);
    while(q.size())
    {
        int t=q.front();
        q.pop();
        if(t==to)
            return visited[to];
        if(t<to)
        {
            for(int i=0; prime[i]<t; i++)
            {
                if(t%prime[i]==0 && t+prime[i]<=to && visited[t+prime[i]]==-1)
                {
                    q.push(t+prime[i]);
                    visited[t+prime[i]]=visited[t]+1;
                }
            }
        }
    }
    return visited[to];
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    memset(isprime,0,sizeof(isprime));
    seive();
    int test;
    scanf("%d",&test);
    for(int t=1; t<=test; t++)
    {
        memset(visited,-1,sizeof(visited));
        int n,m;
        scanf("%d %d",&n,&m);
        printf("Case %d: %d\n",t,bfs(n,m));
    }
}
