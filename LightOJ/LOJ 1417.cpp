#include<bits/stdc++.h>
using namespace std;
const int arrsz=50000;

vector<int>v[arrsz+9];
stack<int>s;
bool visited[arrsz+9];
void clean()
{
    memset(visited,0,sizeof visited);
    for(int i=0; i<arrsz; i++)
    {
        v[i].clear();
    }
    while(!s.empty())
        s.pop();
}

void dfs1(int u)
{
    visited[u]=1;
    for(int i=0; i<(int)v[u].size(); i++)
    {
        int x=v[u][i];
        if(!visited[x])
            dfs1(x);
    }
    s.push(u);
}
int cnt;
void dfs2(int u)
{
    cnt++;
    visited[u]=1;
    for(int i=0; i<(int)v[u].size(); i++)
    {
        int x=v[u][i];
        if(!visited[x])
            dfs2(x);
    }
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int T=1;T<=test;T++){
        int n;
        clean();
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
        }
        for(int i=1;i<=n;i++){
            if(!visited[i])
                dfs1(i);
        }
        int ans=-1e9,qz;
        memset(visited,0,sizeof visited);
        while(!s.empty()){
            int t=s.top();
            s.pop();
            if(!visited[t]){
                memset(visited,0,sizeof visited);
                cnt=0;
                dfs2(t);
                if(cnt>ans){
                    ans=cnt;
                    qz=t;
                }
                else if(cnt==ans and t<qz){
                    ans=cnt;
                    qz=t;
                }
            }
        }
        printf("Case %d: %d\n",T,qz);
    }
}
