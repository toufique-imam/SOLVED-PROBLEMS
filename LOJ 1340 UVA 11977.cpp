#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x/gcd(x,y))*y
#define mod 10000019
const int N=100005;
bool _check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int _set(int N,int pos)
{
    return N=N| (1<<pos);
}
int isprime[N/32+3];
vector<ll>prime;

void seive()
{
    prime.push_back(2);
    for(int i=3; i*i<=N; i+=2)
        if(!_check(isprime[i/32],i%32))
            for(int j=i*i; j<=N; j+=i+i)
                isprime[j/32]=_set(isprime[j/32],j%32);
    for(int i=3; i<=N; i+=2)
        if(!_check(isprime[i/32],i%32))
            prime.push_back(i);
}

ll bigmod(ll base,ll power)
{
    if(power==0)
        return 1;
    if(power%2==0)
    {
        ll ret=bigmod(base,power/2)%mod;
        return (ret*ret)%mod;
    }
    return (base%mod)*(bigmod(base,power-1)%mod)%mod;
}
ll solve(ll n,ll t)
{
    //freopen("output.txt","r",stdout);
    ll ans=1,nx,cnt;
    for(int i=0; i<prime.size() and prime[i]<=n; i++)
    {
        cnt=0;
        nx=n;
        while(nx/prime[i])
        {
            cnt+=nx/prime[i];
            nx/=prime[i];
        }
        if(cnt>=t)
        {
            cnt/=t;
            ans*=bigmod(prime[i],cnt);
            ans%=mod;
           // printf("%lld\n",ans);
        }
    }
    if(ans==1)
        ans=-1;
    return ans;
}
int main()
{
    seive();
    int test;
    scanf("%d",&test);
    for(int _t=1; _t<=test; _t++)
    {
        ll n,t;
        scanf("%lld %lld",&n,&t);
        ll ans=solve(n,t);
        printf("Case %d: %lld\n",_t,ans);
    }
}
