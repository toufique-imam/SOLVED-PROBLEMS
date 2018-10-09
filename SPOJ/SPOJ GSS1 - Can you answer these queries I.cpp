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
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define reunique(v)     v.resize(std::unique(all(v)) - v.begin())
#define MP              make_pair
#define PB              push_back
#define EB              emplace_back
#define segtree         int mid=(st+en)/2,lt=node*2,rg=node*2+1
#define MERGE(v1,v2,v)  merge(all(v1),all(v2),back_inserter(v))
#define loop(a)         for(__typeof__(a.begin())itr=a.begin();itr!=a.end();itr++)
#define log2_(x)        __builtin_clz(1) - __builtin_clz(x);
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/
//n! ~ sqrt(2*pi*n)*n^n*e^-n

const int N=100009;
const int scale=100000;
int ara[N];
//pair<int,pair<int,int> >query[N];
//ll ans[N];
//int pos[3*N];
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
};
data tree[4*N];
void merge_(data &node,data &lt,data &rg)
{
    node.sum=lt.sum+rg.sum;
    node.prefix=max(lt.sum+rg.prefix,lt.prefix);
    node.suffix=max(rg.sum+lt.suffix,rg.suffix);
    node.bsum=max3(lt.bsum,rg.bsum,lt.suffix+rg.prefix);
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
data query_(int node,int st,int en,int l,int r)
{
    if(en<l || st>r)
        return data(-1e9,-1e9,-1e9,-1e9);
    if(st>=l and en<=r)
    {
        return tree[node];
    }
    segtree;
    data tmp,tmp1,tmp2;
    tmp1=query_(lt,st,mid,l,r);
    tmp2=query_(rg,mid+1,en,l,r);
    merge_(tmp,tmp1,tmp2);
    return tmp;
}
int main()
{
   // memset(pos,-1,sizeof pos);
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&ara[i]);
        update(1,1,n,i,ara[i]);
    }
    int q,a,b;
    scanf("%d",&q);
    for(int i=0; i<q; i++)
    {
        scanf("%d %d",&a,&b);
        printf("%lld\n",query_(1,1,n,a,b).bsum);
        //query[i]=MP(b,MP(a,i));
    }
}
