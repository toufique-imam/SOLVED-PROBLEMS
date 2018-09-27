#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        ll target;
        scanf("%lld",&target);
        vector< pair<ll,ll> >v(40009, {0,1e9});
        vector<ll>coins;
        ll n,x;
        scanf("%lld",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%lld",&x);
            coins.push_back(x);
        }
        v[0].first=1;
        v[0].second=0;
        for(int i=0; i<n; i++)
        {
            for(int j=40000; j>=coins[i]; j--)
            {
                v[j].first+=v[j-coins[i]].first;
                v[j].second=min(v[j].second,v[j-coins[i]].second+1);
            }
        }
        ll ans=target;
        while(v[ans].first==0)
        {
            ans++;
        }
        printf("%lld %lld\n",ans,v[ans].second);
    }
}
