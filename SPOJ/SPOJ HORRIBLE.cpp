#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include <iomanip>
using namespace std;
//#include<unordered_map>
//#include<unordered_set>
typedef long long ll;
typedef unsigned long long ull;
#define gcd(A,B)        __gcd(A,B)
#define PQ 			    priority_queue
#define ii 			    int,int
#define pll             pair<ll,ll>
#define PI              2*acos(0.0)
#define all(v)          v.begin(),v.end()
#define pii 		    pair<ii>
#define pb              push_back
#define sf(x) 		    scanf("%I64d",&x)
#define sff(x,y) 	    scanf("%I64d %I64d",&x,&y)
#define sl(x)   	    scanf("%lld",&x)
#define sll(x,y)   	    scanf("%lld %lld",&x,&y)
#define ff              first
#define ss              second
#define segtree         lt=2*par,rg=2*par+1,mid=(st+en)/2
#define read            freopen("input.txt","r",stdin)
#define write           freopen("output.txt","w",stdout)
#define fast            ios_base::sync_with_stdio(0),cin.tie(0)
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define max_ull         18446744073709551615
#define max_ll          9223372036854775807;
#define set(N,cur)      N=(N|(1LL<<cur))
#define reset(N,cur)    N=(N&(~(1LL<<cur)))
#define check(N,cur)    (!((N&(1LL<<cur))==0))
#define all(v)          v.begin(),v.end()
using namespace std;
const int N=100000;
ll tree[4*N+3];
ll lazy[4*N+3];
void cln()
{
    memset(tree,0,sizeof tree);
    memset(lazy,0,sizeof lazy);
}
void push_down(int par)
{
    int lt=par*2,rg=par*2+1;
    lazy[lt]+=lazy[par];
    lazy[rg]+=lazy[par];
}
void update(int par,int st,int en,int L,int R,ll val)
{
    int lt=par*2,rg=par*2+1,h=(en-st+1),mid=(st+en)/2;
    if(lazy[par])
    {
        tree[par]+=lazy[par]*h;
        if(h>1)
            push_down(par);
        lazy[par]=0;
    }
    if(st>R or en<L)return;
    if(st>=L and en<=R)
    {
        tree[par]+=h*val;
        if(h>1)
        {
            lazy[lt]+=val;
            lazy[rg]+=val;
        }
        return;
    }
    update(lt,st,mid,L,R,val);
    update(rg,mid+1,en,L,R,val);
    tree[par]=tree[lt]+tree[rg];
}
ll query(int par,int st,int en,int L,int R)
{
    int lt=par*2,rg=par*2+1,h=(en-st+1),mid=(st+en)/2;
    if(lazy[par])
    {
        tree[par]+=lazy[par]*h;
        if(h>1)
            push_down(par);
        lazy[par]=0;
    }
    if(st>R or en<L)return 0;
    if(st>=L and en<=R)
        return tree[par];
    ll r1=query(lt,st,mid,L,R);
    r1+=query(rg,mid+1,en,L,R);
    return r1;
}
int main()
{
    int test,n,c;
    scanf("%d",&test);
    for(ll T=1; T<=test; T++)
    {
        cln();
        int a,b,q;
        ll x;
        scanf("%d %d",&n,&c);
        for(ll i=0; i<c; i++)
        {
            scanf("%d",&q);
            if(q==0)
            {
                scanf("%d %d %lld",&a,&b,&x);
                update(1,1,n,a,b,x);
            }
            else
            {
                scanf("%d %d",&a,&b);
                printf("%lld\n",query(1,1,n,a,b));
            }
        }
    }
}
