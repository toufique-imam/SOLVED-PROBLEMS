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
#define PQ              priority_queue
#define ii              int,int
#define pll             pair<ll,ll>
#define PI              2*acos(0.0)
#define all(v)          v.begin(),v.end()
#define pii             pair<ii>
#define pb              push_back
#define sf(x)           scanf("%I64d",&x)
#define sff(x,y)        scanf("%I64d %I64d",&x,&y)
#define sl(x)           scanf("%lld",&x)
#define sll(x,y)        scanf("%lld %lld",&x,&y)
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
#define set_(n,pos)     n|(1<<pos)
#define check(n,pos)    n &(1<<pos)
#define toggle(n,pos)   n ^(1<<pos)
#define off(n,pos)      if(!check(n,pos))toggle(n,pos)
using namespace std;
int dp[16][65540];
int dist[16][16];
int Limit,szz;
pii v[16];
int stx,sty,n,m,stin;
int dx[]= {1,1,0,-1,-1,-1,0,1};
int dy[]= {0,1,1,1,0,-1,-1,-1};
bool cango(int x,int y)
{
    return x>-1 and y>-1 and x<n and y<m;
}
void cln()
{
    memset(dp,-1,sizeof dp);
    memset(dist,-1,sizeof dist);
    Limit=szz=0;
    memset(v,-1,sizeof v);
}
void process(string s,int row)
{
    for(int i=0; i<m; i++)
    {
        if(s[i]=='g')
            v[szz++]=make_pair(row,i);
        else if(s[i]=='x')
        {
            v[szz]=make_pair(row,i);
            stx=row,sty=i,stin=szz;
            szz++;
        }
    }
}
int recur(int pos,int mask)
{
    if(mask==Limit)
        return dist[pos][0];
    if(dp[pos][mask]!=-1)
        return dp[pos][mask];
    int r;
    r=1e9;
    for(int i=0; i<szz; i++)
        if(i!=pos and !(mask&(1<<i)))
            r=min(r,dist[pos][i]+recur(i,mask|(1<<i)));
    return dp[pos][mask]=r;
}
/*
x= abs (x1-x2)
y= abs (y1-y2)
ans= min (x,y)+ abs (x-y)
*/
int distanc(pii x,pii y)
{
    int X=abs(x.ff-y.ff);
    int Y=abs(x.ss-y.ss);
    return min(X,Y)+abs(X-Y);
}
int main()
{
   // read;
   // write;
    fast;
    int test;
    cin>>test;
    for(int T=1; T<=test; T++)
    {
        cln();
        cin>>n>>m;
        string s;
        for(int i=0; i<n; i++)
        {
            cin>>s;
            process(s,i);
        }
        if(stin!=0)
            swap(v[0],v[stin]);
        Limit=(1<<szz)-1;
        for(int i=0; i<szz; i++)
            for(int j=0;j<szz;j++)
                dist[i][j]=distanc(v[i],v[j]);
        printf("Case %d: %d\n",T,recur(0,1));
    }
}
