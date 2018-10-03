/*
ID: sabertooth
LANG: C++11
TASK:
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define eps             1e-9
#define inf             0x3f3f3f3f
#define INF             2e18
#define PI              acos(-1.0)
#define ff              first
#define ss              second
#define all(v)          v.begin(),v.end()
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(min(a,b),min(c,d))
#define max4(a,b,c,d)   max(max(a,b),max(c,d))
#define max5(a,b,c,d,e) max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e) min(min3(a,b,c),min(d,e))
#define Iterator(a)     __typeof__(a.begin())
#define read            freopen("in.txt","r",stdin);
#define write           freopen("out.txt","w",stdout);
#define TEST            int test;scanf("%d",&test);for(int T=1;T<=test;T++)
#define PCAS            printf("Case %d:",T);
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define reunique(v)     v.resize(std::unique(all(v)) - v.begin())
#define MP              make_pair
#define PB              push_back
#define EB              emplace_back
#define segtree         int mid=(st+en)/2,lt=node*2,rg=node*2+1
#define MERGE(v1,v2,v)  merge(all(v1),all(v2),back_inserter(v))
//n! ~ sqrt(2*pi*n)*n^n*e^-n

int myLog2(int x)
{
    return __builtin_clz(1) - __builtin_clz(x);
}
const int N=50009;
class data
{
public:
    ll suffix,prefix,sum,bsum;
    data()
    {
        suffix=prefix=sum=bsum=0;
    }
    data(ll a,ll b,ll c,ll d)
    {
        suffix=a;
        prefix=b;
        sum=c;
        bsum=d;
    }
} tree[4*N];
ll ara[N];
inline void merge_(data &node,data &lt,data &rg)
{
    node.sum=lt.sum+rg.sum;
    node.prefix=max(lt.sum+rg.prefix,lt.prefix);
    node.suffix=max(rg.sum+lt.suffix,rg.suffix);
    node.bsum=max3(lt.bsum,rg.bsum,lt.suffix+rg.prefix);
}
void build(int node,int st,int en)
{
    if(st==en)
    {
        tree[node].prefix=tree[node].suffix=tree[node].sum=tree[node].bsum=ara[st];
        return;
    }
    segtree;
    build(lt,st,mid);
    build(rg,mid+1,en);
    merge_(tree[node],tree[lt],tree[rg]);
}
void update(int node,int st,int en,int l,int val)
{
    if(en<l || st>l)
        return;
    if(st==l and en==l)
    {
        tree[node].prefix=tree[node].suffix=tree[node].sum=tree[node].bsum=val;
        return;
    }
    segtree;
    update(lt,st,mid,l,val);
    update(rg,mid+1,en,l,val);
    merge_(tree[node],tree[lt],tree[rg]);
}
data query(int node,int st,int en,int l,int r)
{
    if(en<l || st>r)
        return data(-1e9,-1e9,-1e9,-1e9);
    if(st>=l and en<=r)
    {
        return tree[node];
    }
    segtree;
    data tmp,tmp1,tmp2;
    tmp1=query(lt,st,mid,l,r);
    tmp2=query(rg,mid+1,en,l,r);
    merge_(tmp,tmp1,tmp2);
    return tmp;
}
int32_t main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&ara[i]);
    }
    build(1,1,n);
    int q;
    int a,b,c;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a==0)
            update(1,1,n,b,c);
        else
        {
            printf("%lld\n",query(1,1,n,b,c).bsum);
        }
    }
}
