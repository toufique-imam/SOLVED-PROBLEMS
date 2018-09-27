#include <bits/stdc++.h>
//#include<unordered_map>
typedef long long ll;
typedef unsigned long long ull;
//#define gcd(A,B)    __gcd(A,B)
#define PQ 			priority_queue
#define ii 			int,int
#define pll         pair<ll,ll>
#define PI          2*acos(0.0)
#define all(v)      v.begin(),v.end()
#define pii 		pair<ii>
#define sf(x) 		scanf("%I64d",&x)
#define sff(x,y) 	scanf("%I64d %I64d",&x,&y)
#define sl(x)   	scanf("%lld",&x)
#define sll(x,y)   	scanf("%lld %lld",&x,&y)
#define ff          first
#define ss          second
#define segtree     lt=2*par,rg=2*par+1,mid=(st+en)/2
#define read        freopen("input.txt","r",stdin)
#define write       freopen("output.txt","w",stdout)
using namespace std;

ll gcd(ll a,ll b)
{
    while(b)
    {
        a=a%b;
        swap(a,b);
    }
    return a;
}

ll extended_euclid(ll a, ll b, ll &x, ll &y)
{
    ll xx = y = 0;
    ll yy = x = 1;
    while (b)
    {
        ll q = a / b;
        ll t = b;b = a%b;a = t;
        t = xx; xx = x - q*xx;x = t;
        t = yy;yy = y - q*yy;y = t;
    }
    return a;
}
bool linear_diophantine(ll A,ll B,ll C,ll &x,ll &y)
{
   ll g=gcd(A,B);
    if(C%g)
        return false;
    ll a=A/g,b=B/g,c=C/g;
    extended_euclid(a,b,x,y);
    if(g<0)
        a*=-1,b*=-1,c*=-1;
    x*=c,y*=c;
    return true;
}
//x'=x+k*B/g=>(x'-x)*g/B=k
//y'=y-k*A/g=>(y-y')*g/A=k
int main()
{
   // read;
   // write;
    int test;
    scanf("%d",&test);
    for(int T=1;T<=test;T++)
    {
        ll a,b,c,l1,r1,l2,r2;
        sll(a,b);
        sl(c);
        sll(l1,r1);
        sll(l2,r2);
        ll x,y;
        c=-c;
        if(a<0)
        {
            a*=-1;
            swap(l1,r1);
            l1*=-1,r1*=-1;
        }
        if(b<0)
        {
            b*=-1;
            swap(l2,r2);
            l2*=-1,r2*=-1;
        }
        ll g=gcd(a,b);
        printf("Case %d: ",T);
        if(g and c%g)
            puts("0");
        else if(!a and !b)
        {
            if(!c) printf("%lld\n",(r1-l1+1)*(r2-l2+1));
            else puts("0");
        }
        else if(!a)
        {
            if(c/b>=l2 and c/b<=r2) printf("%lld\n",r1-l1+1);
            else puts("0");
        }
        else if(!b)
        {
            if(c/a>=l1 and c/a<=r1) printf("%lld\n",r2-l2+1);
            else puts("0");
        }
        else if(linear_diophantine(a,b,c,x,y))
        {
            ll k[4];
            k[0]=ceil((l1-x)/double(b/g));
            k[1]=floor((r1-x)/double(b/g));
            k[2]=floor((y-l2)/double(a/g));
            k[3]=ceil((y-r2)/double(a/g));
            ll ans=max(0ll,min(k[1],k[2])-max(k[0],k[3])+1);
            printf("%lld\n",ans);
        }
        else
        {
            puts("0");
        }
    }
}
