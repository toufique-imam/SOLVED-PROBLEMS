#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll ara[105][105];
ll gain[105][105];
bool visited[105][105];
const ll inf=1000000000;

ll drx[]= {0,0,1,-1};
ll dry[]= {1,-1,0,0};

bool check(ll x,ll y)
{
    return x>=0 and x<n and y>=0 and y<m and visited[x][y]==false;
}

void dfs(ll x,ll y)
{
    visited[x][y]=true;
    gain[x][y]=ara[x][y];
    for(ll i=0; i<4; i++)
    {
        ll vx=x+drx[i];
        ll vy=y+dry[i];
        if(check(vx,vy) and ara[vx][vy]>=ara[x][y])
        {
            dfs(vx,vy);
        }
    }

}

int main()
{
    //freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(visited,false,sizeof visited);
        scanf("%lld%lld",&n,&m);
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                scanf("%lld",&ara[i][j]);
                gain[i][j]=inf;
            }
        }
        ll ans=0;

        for(int i=0; i<n; i++)
        {
            if(!visited[i][0])dfs(i,0);
            if(!visited[i][m-1])dfs(i,m-1);
        }
        for(int i=0; i<m; i++)
        {
            if(!visited[0][i])dfs(0,i);
            if(!visited[n-1][i])dfs(n-1,i);
        }
        bool done=false;
        while(!done)
        {
            done=true;

            for(ll i=1; i<n-1; i++)
            {
                for(ll j=1; j<m-1; j++)
                {
                    if(!visited[i][j])
                    {
                        ll mini=inf;
                        for(ll k=0; k<4; k++)
                        {
                            ll vx=i+drx[k];
                            ll vy=j+dry[k];
                            if(vx<0 or vx>=n or vy<0 or vy>=m) continue;
                            mini=min(mini,max(gain[vx][vy],ara[vx][vy]));
                        }
                        if(mini<gain[i][j])
                        {
                            done=false;
                            gain[i][j]=mini;
                        }
                    }
                }
            }
        }
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                if(gain[i][j]>ara[i][j])ans+=(gain[i][j]-ara[i][j]);
            }
        }
        printf("%lld\n",ans);
    }
}
