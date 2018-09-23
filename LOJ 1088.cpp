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
#define segtree         int mid=(st+en)/2,lt=nd*2,rg=nd*2+1

int myLog2(int x)
{
    return __builtin_clz(1) - __builtin_clz(x);
}
const int N=1e5+9;
int ara[N];
class node
{
public:
    int first,second,cnt;
    node()
    {
        first=second=cnt=0;
    }
    node(int x,int y,int c)
    {
        first=min(x,y);
        second=max(x,y);
        cnt=c;
    }
    node(node A,node B)
    {
        first=min4(A.first,B.first,A.second,B.second);
        second=max4(A.first,B.first,A.second,B.second);
        cnt=A.cnt+B.cnt;
    }
};
node tree[4*N+9];
void build(int nd,int st,int en)
{
    if(st==en)
    {
        tree[nd]=node(ara[st],ara[st],1);
        return;
    }
    segtree;
    build(lt,st,mid);
    build(rg,mid+1,en);
    tree[nd]=node(tree[lt],tree[rg]);
}
int query(int nd,int st,int en,int l,int r)
{
    if(tree[nd].ff>r || tree[nd].ss<l)
        return 0;
    if(tree[nd].ff>=l and tree[nd].ss<=r)
        return tree[nd].cnt;
    if(st==en)return 0;
    segtree;
    return query(lt,st,mid,l,r)+query(rg,mid+1,en,l,r);
}
int main()
{
    TEST
    {
        memset(tree,0,sizeof tree);
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=1; i<=n; i++)
            scanf("%d",&ara[i]);
        build(1,1,n);
        printf("Case %d:\n",T);
        int a,b;
        //______Segment Tree ______//
        //______456ms || 6768kB____//
        while(q--)
        {
            scanf("%d %d",&a,&b);
            printf("%d\n",query(1,1,n,a,b));
        }
        /*
        //______Binary Serach_________//
        //______356ms|| 2080kB________//
        int a,b,ans;
        while(q--)
        {
            scanf("%d %d",&a,&b);
            if(ara[0]>b)
            {
                puts("0");
                continue;
            }
            int it1=lower_bound(ara,ara+n,a)-ara;
            if(it1 and ara[it1-1]>=a)
                it1--;
            int it2=lower_bound(ara,ara+n,b)-ara;
            if(it2 and ara[it2]>b)
                it2--;
            it2=min(it2,n-1);
            printf("%d\n",it2-it1+1);
        }
        */
    }
}
