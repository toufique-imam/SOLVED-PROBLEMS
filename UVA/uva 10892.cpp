#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 10000
#define all(v) v.begin(),v.end()
ll m;
vector<bool>isprime(1e7+9);
vector<ll>prime;
vector<ll>factors;
vector<ll>segseive;
vector<ll>ans;

void seive()
{
    ll i,n=1e7+9,j;
    isprime[1]=1;
    isprime[0]=1;

    for(i=4; i<=n; i+=2)
        isprime[i]=1;

    for(i=3; i*i<=n; i+=2)
    {
        if(isprime[i]==0)
            for(j=i*i; j<=n; j+=i)
                isprime[j]=1;
    }
    for(i=0; i<=n; i++)
    {
        if(!isprime[i])
            prime.push_back(i);
    }
}

ll factorize(ll n)
{
    ll i,cnt=0;
    ll res=1;
    ll sqrtn =sqrt(n);
    for(i=0; i<prime.size() && prime[i]<=sqrtn; i++)
    {
        if(n%prime[i]==0)
        {
            cnt=0;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                cnt++;
            }
            sqrtn=sqrt(n);
            cnt++;
            res*=cnt;
        }
    }
    if(n!=1)
        res*=2;
    return res;
}

ll GCD(ll a,ll b)
{
    while(b)
    {
        a=a%b;
        swap(a,b);
    }
    return a;
}

ll LCM(ll a,ll b)
{
    return (a/GCD(a,b))*b;
}

ll bigmod(ll b,ll p)
{
    ll ans;
    if(p==0)
        return 1;
    if(p&1)
        return ((b%m)*(bigmod(b,p-1)%m))%m;
    else
    {
        ans=bigmod(b,p/2);
        return ((ans%m)*(ans%m))%m;
    }
}

ll get_pow(ll n,ll p)
{
    ll res=0;
    n/=p;
    do
    {
        res+=n;
        n/=p;
    }
    while(n>0);
    return res;
}

void segmentseive(ll a,ll b)
{
    ll p,j,sqrtn,i;
    if(a==1)
        a++;
    ll sz=b-a;
    segseive.resize(sz);
    sqrtn=sqrt(b);
    for(i=0; i<prime.size() && prime[i]<=sqrtn; i++)
    {
        p=prime[i];
        j=p*p;
        if(j<a)
            j=((a+p-1)/p)*p;
        for(; j<=b; j+=p)
            segseive[j-a]=1;
    }
    for(i=a; i<=b; i++)
    {
        if(segseive[i-a]==0)
            ans.push_back(i);

    }
}
int main()
{
    //freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    ll n;
    while(scanf("%lld",&n)==1 && n)
    {
        ll i,cnt=0;
        vector<ll>ans;
        for(i=1; i*i<=n; i++)
        {
            if(n%i==0)
            {
                ans.push_back(i);
                if(i!=n/i)
                {
                    ans.push_back(n/i);
                }
            }
        }
        for(i=0; i<ans.size(); i++)
        {
            for(ll j=i; j<ans.size(); j++)
            {
                if(LCM(ans[i],ans[j])==n && i!=j)
                    cnt++;
            }
        }
        printf("%lld %lld\n",n,cnt+1);
    }
}