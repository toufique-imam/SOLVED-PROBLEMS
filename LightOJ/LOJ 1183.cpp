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
#define MP              make_pair
#define PB              push_back
#define EB              emplace_back
#define segtree         int mid=(st+en)/2,lt=node*2,rg=node*2+1
#define MERGE(v1,v2,v)  merge(all(v1),all(v2),back_inserter(v))
 
int myLog2(int x)
{
    return __builtin_clz(1) - __builtin_clz(x);
}
 
const int N=1e5+9;
//pair<int,int>ara[N];
ll tree[4*N];
ll lazy[4*N];
void push_down(int node,int st,int en)
{
    if(st!=en)
    {
        segtree;
        tree[lt]=(mid-st+1)*lazy[node];
        tree[rg]=(en-mid)*lazy[node];
        lazy[lt]=lazy[node];
        lazy[rg]=lazy[node];
    }
    lazy[node]=-1;
}
void update(int node,int st,int en,int l,int r,int val)
{
    if(lazy[node]!=-1)
        push_down(node,st,en);
    if(st>r || en<l)
        return;
    if(st>=l and en<=r)
    {
        tree[node]=(en-st+1)*val;
        if(st!=en)
            lazy[node]=val;
        return;
    }
    segtree;
    update(lt,st,mid,l,r,val);
    update(rg,mid+1,en,l,r,val);
    tree[node]=tree[lt]+tree[rg];
}
ll query(int node,int st,int en,int l,int r)
{
    if(lazy[node]!=-1)
        push_down(node,st,en);
    if(st>r || en<l)
        return 0;
    if(st>=l and en<=r)
        return tree[node];
    segtree;
    return query(lt,st,mid,l,r)+query(rg,mid+1,en,l,r);
}
int main()
{
   //  read;
    //write;
    TEST
    {
        memset(tree,0,sizeof tree);
        memset(lazy,-1,sizeof lazy);
        int n,q;
        scanf("%d%d",&n,&q);
        int qq,a,b,c;
        printf("Case %d:\n",T);
        while(q--)
        {
            scanf("%d%d%d",&qq,&a,&b);
            a++;
            b++;
            if(qq==1)
            {
                scanf("%d",&c);
                update(1,1,n,a,b,c);
            }
            else
            {
                ll ans=query(1,1,n,a,b);
                if(ans==0)
                {
                    printf("0\n");
                    continue;
                }
                ll lim=(b-a+1);
                ll g=__gcd(lim,ans);
                lim/=g;
                ans/=g;
                if(lim!=1)
                    printf("%lld/%lld\n",ans,lim);
                else
                    printf("%lld\n",ans);
            }
        }
    }
}
 