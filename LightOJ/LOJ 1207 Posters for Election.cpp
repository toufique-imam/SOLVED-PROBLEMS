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
const int N1=2*N;
pair<int,int>ara[N];
int tree[4*N1];
int lazy[4*N1];
void push_down(int node,int st,int en)
{
    if(st!=en)
    {
        segtree;
        tree[lt]=lazy[node];
        tree[rg]=lazy[node];
        lazy[lt]=lazy[node];
        lazy[rg]=lazy[node];
    }
    lazy[node]=0;
}
void update(int node,int st,int en,int l,int r,int val)
{
    if(lazy[node])
        push_down(node,st,en);
    if(st>r || en<l)return;
    if(st>=l and en<=r)
    {
        tree[node]=val;
        lazy[node]=val;
        return;
    }
    segtree;
    update(lt,st,mid,l,r,val);
    update(rg,mid+1,en,l,r,val);
    if(tree[lt]==tree[rg])
        tree[node]=tree[lt];
    else tree[node]=-1;
}
set<int>S;
void query(int node,int st,int en)
{
    if(lazy[node])push_down(node,st,en);
    if(tree[node]!=-1 and tree[node]!=0)
    {
        S.insert(tree[node]);
        return;
    }
    if(st==en)
    {
        return;
    }
    segtree;
    query(lt,st,mid);
    query(rg,mid+1,en);
}
int main()
{
    TEST
    {
        memset(tree,0,sizeof tree);
        memset(lazy,0,sizeof lazy);
        S.clear();
        int sz=0;
        int idx=1;
        int n;
        scanf("%d",&n);
        int mini=1,maxi=1;
        for(int i=0; i<n; i++)
        {
            scanf("%d %d",&ara[i].ff,&ara[i].ss);
            if(ara[i].ff>ara[i].ss)swap(ara[i].ff,ara[i].ss);
            maxi=max(ara[i].ss,maxi);
        }
        for(int i=0;i<n;i++)
        {
            update(1,1,maxi,ara[i].ff,ara[i].ss,i+1);
        }
        query(1,1,maxi);
        int cnt=S.size();
        printf("Case %d: %d\n",T,cnt);
    }
}
