#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll sum[10000];
ll cnt[100];
void calc(ll n)
{
    for(int i=0; i<n; i++)
    {
        sum[i]=sum[i/10]+i%10;
        cnt[sum[i]]++;
    }
}
int main()
{
    memset(cnt,0,sizeof(cnt));
    memset(sum,0,sizeof(sum));
    ll n;
    ll t1,t2;
    scanf("%lld",&n);
    t1=n/2;
    t2=powl(10,t1);
    calc(t2);
    ll ans=0;
    for(int i=0;i<t2;i++)
    {
        ans+=cnt[sum[i]]*cnt[sum[i]];
        cnt[sum[i]]=0;
    }
    printf("%lld\n",ans);

}
