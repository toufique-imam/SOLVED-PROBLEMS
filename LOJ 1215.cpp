#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x/gcd(x,y))*y
#define mod 1000000007
const int N=1e6+9;
int notprime[N/2+3];
vector<int>prime;
void seive()
{
    prime.push_back(2);
    for(int i=3; i*i<N; i+=2)
        if(!notprime[i>>1])
            for(int j=i*i; j<N; j+=2*i)
                notprime[j>>1]=1;
    for(int i=3; i<N; i+=2)
        if(!notprime[i>>1])
            prime.push_back(i);
}

ll get_pow(ll n,ll p)
{
    ll cnt=0;
    if(n%p==0)
    {
        while(n%p==0)
        {
            n/=p;
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    seive();
    int test;
    scanf("%d",&test);
    for(int _t=1; _t<=test; _t++)
    {
        ll a,b,L,cnt=0,cnt1,cnt2,C=1;
        bool f=1;
        scanf("%lld %lld %lld",&a,&b,&L);
        if(L%a or L%b)
            f=0;
        if(f)
        {
            for(int i=0; i<prime.size() and prime[i]*prime[i]<=L; i++)
            {
                if(L%prime[i]==0)
                {
                    cnt=0;
                    while(L%prime[i]==0)
                    {
                        L/=prime[i];
                        cnt++;
                    }
                    cnt1=get_pow(a,prime[i]);
                    cnt2=get_pow(b,prime[i]);
                    if(max(cnt1,cnt2)<cnt)
                    {
                        C=C*powl(prime[i],cnt);
                    }
                }
            }
            if(L!=1)
            {
                cnt1=get_pow(a,L);
                cnt2=get_pow(b,L);
                if(cnt1<1 and cnt2<1)
                {
                    C*=L;
                }
            }
        }
        printf("Case %d: ",_t);
        f==1?printf("%lld\n",C):printf("impossible\n");
    }
}
