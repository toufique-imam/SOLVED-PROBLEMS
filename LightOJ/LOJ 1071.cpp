#include<bits/stdc++.h>
using namespace std;

/*
#include<unordered_map>
#include<unordered_set>
*/

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fbo         find_by_order
#define ook         order_of_key
*/

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
#define set(N,cur)      N=(N|(1LL<<cur))
#define reset(N,cur)    N=(N&(~(1LL<<cur)))
#define check(N,cur)    ((N&(1LL<<cur))==0)
#define all(v)          v.begin(),v.end()
#define reunique(v)     v.resize(std::unique(all(v)) - v.begin())
/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction
/*

Here asks to find two disjoint path one from 1,1 to n,m and other from n,m to 1,1
->we can also say that we need two disjoint path from 1,1 to n,n 
So We can say two man Standing in 1,1 will go to either down or right, we can write this combination like this
--------------------
man1 | man2
--------------------
right | right
down | down
right | down
down | right
--------------------
Now we can denote total_steps_by_man1=ROW1+COLOUMN1
As they are moving together there step count will be same
->So if we know their pos in col or row and Number of Steps they have taken, we can calc their corresponding pos for row/col
so our dp will have 3 state
1.no of steps
2.Number of row that Man1 Stands
3.Number of row that Man2 stands 

*/
int n,m;
int grid[109][109];
int dp[209][109][109];
void cln()
{
    memset(dp,-1,sizeof dp);
}
int dfs(int step,int x1,int x2)
{
    if(x1==x2 and !(x1==0 or x2==n-1))
        return -1e9;
    if(step==n+m-2 and x1==x2 and (x1==n-1))
        return grid[n-1][m-1];
    if(dp[step][x1][x2]>-1)
        return dp[step][x1][x2];
    int ans=-1e9;
    if(x1+1<n and x2+1<n)//down -down
        ans=max(ans,dfs(step+1,x1+1,x2+1));
    if(x1+1<n and step-x2+1<m)//down right
        ans=max(ans,dfs(step+1,x1+1,x2));
    if(step-x1+1<m and step-x2+1<m)//right-right
        ans=max(ans,dfs(step+1,x1,x2));
    if(step-x1+1<m and x2+1<n)//right-down
        ans=max(ans,dfs(step+1,x1,x2+1));
    ans+=grid[x1][step-x1];
    if(x1!=x2)
        ans+=grid[x2][step-x2];
    return dp[step][x1][x2]=ans;
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int T=1; T<=test; T++)
    {
        cln();
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                scanf("%d",&grid[i][j]);
        int ans=dfs(0,0,0);
        printf("Case %d: %d\n",T,ans);
    }
}