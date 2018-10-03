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
const int N=30009;
class data
{
    public:
    int cf,cs,tot;
    data()
    {
        cf=cs=tot=0;
    }
};
data tree[4*N];
char s[N];
void build(int node,int st,int en)
{
    if(st==en)
    {
        tree[node].cf=(s[st]=='('?1:0);
        tree[node].cs=(s[st]==')'?1:0);
        tree[node].tot=0;
        return;
    }
    segtree;
    build(lt,st,mid);
    build(rg,mid+1,en);
    int t=min(tree[lt].cf,tree[rg].cs);
    tree[node].cf=tree[lt].cf+tree[rg].cf-t;
    tree[node].cs=tree[lt].cs+tree[rg].cs-t;
    tree[node].tot=tree[lt].tot+tree[rg].tot+t;
}
void update(int node,int st,int en,int l)
{
    if(en<l || st>l)
        return;
    if(st==l and en==l)
    {
        swap(tree[node].cs,tree[node].cf);
        return;
    }
    segtree;
    update(lt,st,mid,l);
    update(rg,mid+1,en,l);
    int t=min(tree[lt].cf,tree[rg].cs);
    tree[node].cf=tree[lt].cf+tree[rg].cf-t;
    tree[node].cs=tree[lt].cs+tree[rg].cs-t;
    tree[node].tot=tree[lt].tot+tree[rg].tot+t;
}
int32_t main()
{
    for(int T=1;T<=10;T++)
    {
        int n;
        scanf("%d%s",&n,s+1);
        build(1,1,n);
        printf("Test %d:\n",T);
        int q,a;
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d",&a);
            if(a)
                update(1,1,n,a);
            else
            {
                if(tree[1].cf==tree[1].cs and tree[1].cs==0)
                {
                    puts("YES");
                }
                else
                {
                    puts("NO");
                }
            }
        }
    }
}
