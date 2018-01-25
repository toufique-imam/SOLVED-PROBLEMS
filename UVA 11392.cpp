/*
ID:sabertooth
TASK:UVA 11392
LANG: C++11
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1000000;
int visited[N+9];
int ans;
int bfs(int n)
{
    queue<int>q;
    q.push(3%n);
    int l=1;
    visited[3%n]=1;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        int x=t*10+3;
        int rem=x%n;
        l++;
        if(visited[rem])
        {
            int j=visited[rem];
            ans=abs(j-l);
            return l;
        }
        else if(rem==0)
        {
            ans=l;
            return l;
        }
        else
        {
            visited[rem]=l;
            q.push(rem);
        }
    }
}

int main ()
{
    int n,t;
    while(scanf("%d",&n)==1)
    {
        memset(visited,0,sizeof(visited));
        if(n==3 || n==1)
        {
            ans=1;
            t=1;
        }
        else if(n==0)
        {
            t=1;
            ans=0;
        }
        else
            t=bfs(n);
        printf("%d %d %d\n",t,ans,t-ans);
    }
}
