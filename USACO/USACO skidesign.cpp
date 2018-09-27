/*
ID: sabertooth9
LANG: C++11
TASK: skidesign
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1009][1009];
ll ara[1009];
ll n;
ll mini,maxi;
void go_left(ll pos1,ll pos2){for(ll i=pos2-1; i>=0;i--)dp[pos1][i]=dp[pos1][i+1]+1;}
void go_rigth(ll pos1,ll pos2){for(ll i=pos2+1; i<=1000; i++)dp[pos1][i]=dp[pos1][i-1]+1;}
void gen()
{
    for(ll i=0; i<n; i++)
    {
        dp[i][ara[i]]=0;
        go_left(i,ara[i]);
        go_rigth(i,ara[i]);
    }
}
ll calc(ll pos)
{
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        ll minii=1e9;
        for(ll j=pos;j<=pos+17;j++)minii=min(minii,dp[i][j]);
        ans+=minii*minii;
    }
    return ans;
}
int main()
{
    freopen("skidesign.in","r",stdin);
    freopen("skidesign.out","w",stdout);
    scanf("%lld",&n);
    mini=1e9;
    maxi=-1e9;
    for(int i=0; i<n; i++)
    {
        scanf("%lld",ara+i);
        mini=min(mini,ara[i]);
        maxi=max(maxi,ara[i]);
    }
    gen();
    ll ans=1e18;
    for(ll i=0;i<400;i++)ans=min(ans,calc(i));
    cout<<ans<<endl;
}
