#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x/gcd(x,y))*y

ll get_pow(ll n,ll x)
{
    ll cnt=0;
    while(n>0)
    {
        n/=x;
        cnt+=n;
    }
    return cnt;
}
ll get_pow2(ll n,ll x)
{
    ll cnt=0;
    if(n%x==0)
    {
        while(n%x==0)
        {
            n/=x;
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    //freopen("output.txt","w",stdout);
    int test;
    scanf("%d",&test);
    for(int _t=1; _t<=test; _t++)
    {
        ll n,r,p,q;
        scanf("%lld %lld %lld %lld",&n,&r,&p,&q);
        ll cnt2_1=get_pow(n,2);
        ll cnt2_2=get_pow(r,2)+get_pow(n-r,2);
        ll cnt5_1=get_pow(n,5);
        ll cnt5_2=get_pow(n-r,5)+get_pow(r,5);
        cnt2_1=cnt2_1+(get_pow2(p,2)*q);
        cnt5_1=cnt5_1+(get_pow2(p,5)*q);
        ll cnt2=cnt2_1-cnt2_2;
        ll cnt5=cnt5_1-cnt5_2;
        printf("Case %d: %lld\n",_t,min(cnt2,cnt5));
    }
}
