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
ll ara[N];
ll tree[4*N];
bool done[4*N];
void build(int node,int st,int en)
{
    if(st==en)
    {
        tree[node]=ara[st];
        done[node]=(tree[node]<=1?false:true);
        return;
    }
    segtree;
    build(lt,st,mid);
    build(rg,mid+1,en);
    tree[node]=tree[lt]+tree[rg];
    done[node]=done[lt]|done[rg];
}
void update(int node,int st,int en,int l,int r)
{
    if(!done[node])return;
    if(st>r || en<l)return;
    if(st==en)
    {
        tree[node]=sqrt(tree[node]);
        done[node]=(tree[node]<=1?false:true);
        return;
    }
    segtree;
    if(l<=mid)update(lt,st,mid,l,r);
    if(mid<r)update(rg,mid+1,en,l,r);
    tree[node]=tree[lt]+tree[rg];
    done[node]=done[lt]|done[rg];
}
ll query(int node,int st,int en,int l,int r)
{
    if(st>=l and en<=r)
        return tree[node];
    if(st>r || en<l)return 0;
    segtree;
    ll ans=0;
    if(l<=mid)ans=query(lt,st,mid,l,r);
    if(mid<r)ans+=query(rg,mid+1,en,l,r);
    return ans;
}
int main()
{
    int cas=1;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
       // memset(tree,0,sizeof tree);
        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&ara[i]);
        }
        build(1,1,n);
        printf("Case #%d:\n",cas++);
        int q,a,b,c;
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d %d %d",&c,&a,&b);
            if(a>b)
                swap(a,b);
            if(c)
            {
                printf("%lld\n",query(1,1,n,a,b));
            }
            else
            {
                update(1,1,n,a,b);
            }
        }
        puts("");
    }
}
