#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x/gcd(x,y))*y
#define mod 1000000007
const int N=100000000;
bool _check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int _set(int N,int pos)
{
    return N=N| (1<<pos);
}
int isprime[N+3];
vector<ll>prime;

void seive()
{
    memset(isprime,0,sizeof isprime);
    prime.push_back(2);
    for(int i=3;i*i<=N;i+=2)
        if(!isprime[i])
            for(int j=i*i;j<=N;j+=i*i)
                isprime[j]=1;
    for(int i=3;i<=N;i+=2)
        if(!isprime[i])
            prime.push_back(i);
}

ll bigmod(ll base,ll p)
{
    ll x=1,y=base;
    long long power=p;
    while(power>0)
    {
        if(power&1)
            x*=y;
        y*=y;
        power>>=1;
    }
    return x;
}
inline void update_val(ll &S,ll p,ll power)
{
    if(power==1)
        S*=(p+1);
    else
        S*=((bigmod(p,power+1)-1)/(p-1));
}

ll solve(ll n)
{
    ll p,cnt,ans=1;
    ll sz=prime.size();
    for(ll i=0;i<sz and prime[i]*prime[i]<=n;i++)
    {
        p=prime[i];
        if(n%p==0)
        {
            cnt=0;
            while(n%p==0)
            {
                cnt++;
                n/=p;
            }
            update_val(ans,p,cnt);
        }
    }
    if(n>1)
        update_val(ans,n,1);
    return ans;
}
int main()
{
    seive();
    int test;
    //freopen("input.txt","r",stdin);
    scanf("%d",&test);
    while(test--)
    {
        ll a;
        scanf("%llu",&a);
        printf("%llu\n",solve(a)-a);
    }
}
