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
const int N=30000+9;
int tree_min[4*N];
//int tree_max[4*N];
int ara[N];
int n;
void build(int node,int st,int en)
{
    if(st==en)
    {
        tree_min[node]=st;
        //tree_max[node]=ara[st];
        return;
    }
    int mid=(st+en)/2;
    build(node*2,st,mid);
    build(node*2+1,mid+1,en);
    tree_min[node]=ara[tree_min[node*2]]<ara[tree_min[node*2+1]]?tree_min[node*2]:tree_min[node*2+1];
    //tree_max[node]=min(tree1[node*2],tree1[node*2+1]);
}
int query_min(int node,int st,int en,int l,int r)
{
    if(st>r || en<l)
        return 0;
    if(st>=l and en<=r)
    {
        return tree_min[node];
    }
    int mid=(st+en)/2;

    int t1=query_min(node*2,st,mid,l,r),t2=query_min(node*2+1,mid+1,en,l,r);
    return ara[t1]<ara[t2]?t1:t2;
}
int recur(int y,int x)
{
    if(y>x)return -1e9;
    if(x>n)return -1e9;
    if(y<1)return -1e9;
    if(x<1)return -1e9;
    int mini=query_min(1,1,n,y,x);
    return max3((x-y+1)*ara[mini],recur(y,mini-1),recur(mini+1,x));
}
int main()
{
    TEST
    {
        ara[0]=1e9;
        memset(tree_min,inf,sizeof tree_min);
        //memset(tree1,inf,sizeof tree1);
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&ara[i]);
            //maxi=max(maxi,ara[i]);
        }
        printf("Case %d: ",T);
        build(1,1,n);
        printf("%d\n",recur(1,n));
    }
}
