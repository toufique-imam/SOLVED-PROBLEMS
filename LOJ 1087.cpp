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
int myLog2(int x)
{
    return __builtin_clz(1) - __builtin_clz(x);
}
const int N=2*1e5+9;
int ara[N+3];
int tree[4*N+3];
int a[N+3];
void build(int node,int st,int en)
{
    if(st==en)
    {
        tree[node]=a[st];
        return;
    }
    segtree;
    build(lt,st,mid);
    build(rg,mid+1,en);
    tree[node]=tree[lt]+tree[rg];
}
void update(int node,int st,int en,int l,int val)
{

    if(en<l || l<st)
        return;
    if(st>=l and en<=l)
    {
        tree[node]=val;
        return;
    }
    segtree;
    update(lt,st,mid,l,val);
    update(rg,mid+1,en,l,val);
    tree[node]=tree[lt]+tree[rg];
}
int query(int node,int st,int en,int l,int r)
{
    if(en<l || r<st)
        return 0;
    if(st>=l and en<=r)
        return tree[node];
    segtree;
    return query(lt,st,mid,l,r)+query(rg,mid+1,en,l,r);
}
int main()
{
    TEST
    {
        memset(a,0,sizeof ara);
        int n,q,v;
        scanf("%d %d",&n,&q);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&ara[i]);
            a[i]=1;
        }
        char x;
        int limit=n+q;
        build(1,1,limit);
        printf("Case %d:\n",T);
        getchar();
        while(q--)
        {
            x=getchar();
            scanf("%d",&v);
            getchar();
            if(x=='a')
            {
                n++;
                ara[n]=v;
                a[n]=1;
                update(1,1,limit,n,1);
            }
            else
            {
                int cnt=20;
                int lo=1,hi=n;
                int mid;
                int ans=-1;
                while(cnt--)
                {
                    mid=(lo+hi)/2;
                    int sum=query(1,1,limit,1,mid);
                    if(sum>=v)
                    {
                        ans=mid;
                        hi=mid-1;
                    }
                    else
                        lo=mid+1;
                }
                if(ans==-1)
                    puts("none");
                else
                {
                    a[ans]=0;
                    update(1,1,limit,ans,0);
                    printf("%d\n",ara[ans]);
                }
            }
        }
    }
}
