#include <bits/stdc++.h>
#define ll long long
#define M 4000002
using namespace std;
ll dp[2][2000009];
ll mx=2000000;
vector< pair<ll,ll> >v;
int main()
{
    ll n,k;
    scanf("%lld %lld",&k,&n);
    ll a,b;
    for(int i=0; i<n; i++)
    {
        scanf("%lld %lld",&a,&b);
        v.push_back(make_pair(a,b));
    }
    ll ans=0;
    int now=1,i,j,prev;
    for(i=0; i<n; i++)
    {
        if(now==1)
            prev=0;
        else
            prev=1;
       // for(int j=1;j<=k;j++)dp[now][j]=dp[prev][j];
        for(j=1; j<=k; j++)
        {
            dp[now][j]=dp[prev][j];
            if(v[i].second<=j)
            if(dp[prev][j]<dp[prev][j-v[i].second]+v[i].first)
                dp[now][j]=dp[prev][j-v[i].second]+v[i].first;
            else
                dp[now][j]=dp[prev][j];
            ans=max(ans,dp[now][j]);
        }
        if(now)
            now=0;
        else
            now=1;
    }
    printf("%lld\n",ans);
}
