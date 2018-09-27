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
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define reunique(v)     v.resize(std::unique(all(v)) - v.begin())
int myLog2(int x)
{
    return __builtin_clz(1) - __builtin_clz(x);
}
const int N=1e5+9;
int ara[N];
long long tree[4*N];
long long lazy[4*N];
inline void push_down(int node,int st,int en)
{
    tree[node]+=(en-st+1)*lazy[node];
    if(st!=en)
    {
        lazy[node*2]+=lazy[node];
        lazy[node*2+1]+=lazy[node];
    }
    lazy[node]=0;
}
void update(int node,int st,int en,int l,int r,int val)
{
    if(lazy[node])
    {
        push_down(node,st,en);
    }
    if(en<l || st>r)
        return;
    if(st>=l and en<=r)
    {
        tree[node]+=(en-st+1)*val;
        if(st!=en)
        {
            lazy[node*2]+=val;
            lazy[node*2+1]+=val;
        }
        return;
    }
    int mid=(st+en)/2;
    update(node*2,st,mid,l,r,val);
    update(node*2+1,mid+1,en,l,r,val);
    tree[node]=tree[node*2]+tree[node*2+1];
}
ll query(int node,int st,int en,int l,int r)
{
    if(lazy[node])
        push_down(node,st,en);
    if(en<l || st>r)
        return 0;
    if(st>=l and en<=r)
    {
        return tree[node];
    }
    int mid=(st+en)/2;
    return query(node*2,st,mid,l,r)+query(node*2+1,mid+1,en,l,r);
}
int main()
{
    TEST
    {
        memset(tree,0,sizeof tree);
        memset(lazy,0,sizeof lazy);
        int n,q;
        scanf("%d %d",&n,&q);
        printf("Case %d:\n",T);
        int a,b,c;
        while(q--)
        {
            scanf("%d",&a);
            if(a==0)
            {
                scanf("%d %d %d",&a,&b,&c);
                a++;
                b++;
                update(1,1,n,a,b,c);
            }
            else
            {
                scanf("%d %d",&a,&b);
                a++;
                b++;
                printf("%lld\n",query(1,1,n,a,b));
            }
        }
    }
}
