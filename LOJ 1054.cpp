#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x/gcd(x,y))*y
#define mod 1000000007
const int N=1e6;
ll bigmod(ll base,ll power)
{
    ll res=1,x=base%mod;
    while(power)
    {
        if(power & 1)
            res=(res*x)%mod;
        x=(x*x)%mod;
        power>>=1;
    }
    return res;
}
int notprime[N/2];
vector<int>prime;
void seive()
{
    for(int i=3; i*i<=N; i+=2)
        if(!notprime[i]>>1)
            for(int j=i*i; j<=N; j+=i+i)
                notprime[j>>1]=1;
    prime.push_back(2);
    for(int i=3; i<=N; i+=2)
        if(!notprime[i>>1])
            prime.push_back(i);
}

ll dolve(ll n,ll power)
{
    ll res=1,cnt,mn,new_pow;
    for(int i=0; i<prime.size() and prime[i]*prime[i]<=n; i++)
    {
        if(n%prime[i]==0)
        {
            cnt=0;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                cnt++;
            }
            mn=((bigmod(prime[i],cnt*power+1)-1)%mod*bigmod(prime[i]-1,mod-2)%mod)%mod;
            res=(res%mod*mn%mod)%mod;
        }
    }
    if(n!=1)
    {
        mn=((bigmod(n,power+1)-1)%mod*bigmod(n-1,mod-2)%mod)%mod;
        res=(res%mod*mn%mod)%mod;
    }
    return max(1ll,res);
}
int main()
{
    seive();
    int test;
    scanf("%d",&test);
    for(int _t=1; _t<=test; _t++)
    {
        ll base,power;
        scanf("%lld %lld",&base,&power);
        printf("Case %d: %lld\n",_t,dolve(base,power));
    }
}
