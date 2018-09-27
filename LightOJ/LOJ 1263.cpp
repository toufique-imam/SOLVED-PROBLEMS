#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int taka[1009];
vector<int>v[1009];
bool visited[1009];

void clean()
{
    for(int i=0; i<1009; i++)
        v[i].clear();
    memset(taka,0,sizeof taka);
    memset(visited,0,sizeof(visited));
}
bool dfs(int child,int person,int need,int req)
{
    if(taka[child]>req)
    {
        taka[person]+=min(need,taka[child]-req);
        taka[child]-=min(need,taka[child]-req);
    }
    if(taka[person]==req)
        return 1;
    visited[child]=1;
    bool ans=0;
    for(int i=0; i<v[child].size(); i++)
    {
        int x=v[child][i];
        if(!visited[x])
            ans= dfs(x,person,req-taka[person],req);
    }
    return ans;
}
int main()
{
//    freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
    int test;
    scanf("%d",&test);
    for(int _t=1; _t<=test; _t++)
    {
        clean();
        int n,m,s=0;
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++)
        {
            scanf("%d",taka+i);
            s+=taka[i];
        }
        for(int i=0; i<m; i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            a--;
            b--;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        bool f=1;
        if(s%n)
        {
            f=0;
        }
        else
        {
            int req=s/n;
            for(int i=0; i<n; i++)
            {
                if(taka[i]<req)
                {
                    memset(visited,0,sizeof visited);
                    if(!dfs(i,i,req-taka[i],req))
                    {
                        f=0;
                        break;
                    }
                }
            }
        }
        if(f)
            printf("Case %d: Yes\n",_t);
        else
            printf("Case %d: No\n",_t);
    }
}

