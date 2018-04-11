#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const long long mod=4294967296;
const long long sz=5761460;
const int N=1e8;
bool _check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int _set(int N,int pos)
{
    return N=N| (1<<pos);
}
unsigned int isprime[sz];
int prime[sz];
int pos;
void seive()
{
    pos=0;
    prime[pos++]=2;
    for(int i=3; i*i<=N; i+=2)
        if(!_check(isprime[i/32],i%32))
            for(ll j=i*i; j<=N; j+=i+i)
                isprime[j/32]=_set(isprime[j/32],j%32);
    for(int i=3; i<=N; i+=2)
        if(!_check(isprime[i/32],i%32))
            prime[pos++]=i;
}

inline void PRE()
{
    isprime[0]=prime[0];
    for(int i=1; i<pos; i++)
        isprime[i]=isprime[i-1]*prime[i],isprime[i]%mod;
}

ll bigmod(ll base, ll power)
{
    ll x=base%mod,res=1;
    while(power>0)
    {
        if(power & 1)
            res*=x,res%=mod;
        x*=x,x%=mod;
        power>>=1;
    }
    return res;
}
ll bin_lower(ll n)
{
    ll l=0,h=pos-1,mid,ans=0;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(prime[mid]<=n)
            ans=mid,l=mid+1;
        else
            h=mid-1;
    }
    return ans;
}
ll solve(ll n)
{
    ll posx=bin_lower(n);
    ll ans=isprime[posx],p,cnt,nx;
    for(int i=0; i<pos and prime[i]*prime[i]<=n; i++)
    {
        p=prime[i];
        cnt=0;
        nx=n;
        while(nx>0)
        {
            nx/=prime[i];
            cnt++;
        }
        cnt-=2;
        if(cnt>0)
        {
            ans*=bigmod(p,cnt);
            ans%=mod;
        }
    }
    return ans;
}
int main()
{

    seive();
    PRE();
    int test;
    scanf("%d",&test);
    for(int _t=1; _t<=test; _t++)
    {
        ll n;
        scanf("%llu",&n);
        printf("Case %d: %llu\n",_t,solve(n));
    }
}
