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
#define fast            ios_base::sync_with_stdio(0);cin.tie(0);
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define max_ull         18446744073709551615
#define max_ll          9223372036854775807;
using namespace std;
int dp[109][109];
string s;
int recur(int lt,int rg)
{
    if(lt>rg)return 0;
    if(dp[lt][rg]!=-1)return dp[lt][rg];
    if(s[lt]==s[rg])return dp[lt][rg]=recur(lt+1,rg-1);
    else
        return dp[lt][rg]=min(recur(lt+1,rg),recur(lt,rg-1))+1;
}
int main()
{
    int test;
    scanf("%d",&test);
    getchar();
    for(int T=1;T<=test;T++)
    {
        memset(dp,-1,sizeof dp);
        cin>>s;
        int l=(int)s.size();
        printf("Case %d: %d\n",T,recur(0,l-1));
    }
}
