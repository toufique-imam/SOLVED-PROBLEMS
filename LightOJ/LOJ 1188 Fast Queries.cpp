/*
ID: sabertooth
LANG: C++11
TASK:
*/
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cassert>
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
#include<unordered_map>
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
int ara[N];
int last[N];
pair<pair<int,int>,int>query[5*N];
int ans[5*N];
int tree[4*N];
void update(int node,int st,int en,int l,int val)
{
    if(l>en || l<st)
        return;
    if(st>=l and en<=l)
    {
        tree[node]=val;
        return;
    }
    segtree;
    update(lt,st,mid,l,val);
    update(rg,mid+1,en,l,val);
    tree[node]=tree[rg]+tree[lt];
}
int query_(int node,int st,int en,int l,int r)
{

    if(l>en || r<st)
        return 0;
    if(st>=l and en<=r)
        return tree[node];
    segtree;
    return query_(lt,st,mid,l,r)+query_(rg,mid+1,en,l,r);
}
int main()
{
    TEST
    {
        memset(last,-1,sizeof last);
        int n;
        scanf("%d",&n);
        int q,a,b,c;
        scanf("%d",&q);
        for(int i=1; i<=n; i++)
            scanf("%d",&ara[i]);
        for(int i=0; i<q; i++)
        {
            scanf("%d %d",&a,&b);
            query[i]=MP(MP(b,a),i);
        }
        sort(query,query+q);
        int idx=1;
        for(int i=0; i<q; i++)
        {
            a=query[i].ff.ss;
            b=query[i].ff.ff;
            c=query[i].ss;
            if(idx<=b)
            {
                for(int j=idx; j<=b; j++)
                {
                    if(last[ara[j]]==-1)
                    {
                        last[ara[j]]=j;
                        update(1,1,n,j,1);
                    }
                    else
                    {
                        update(1,1,n,last[ara[j]],0);
                        last[ara[j]]=j;
                        update(1,1,n,j,1);
                    }
                }
                idx=b;
            }
            ans[c]=query_(1,1,n,a,b);
        }
        printf("Case %d:\n",T);
        for(int i=0; i<q; i++)
            printf("%d\n",ans[i]);
    }
}
