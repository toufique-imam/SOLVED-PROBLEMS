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
using namespace std;
//#include<unordered_map>
typedef long long ll;
typedef unsigned long long ull;
//#define gcd(A,B)    __gcd(A,B)
#define PQ 			priority_queue
#define ii 			int,int
#define pll         pair<ll,ll>
#define PI          2*acos(0.0)
#define all(v)      v.begin(),v.end()
#define pii 		pair<ii>
#define sf(x) 		scanf("%I64d",&x)
#define sff(x,y) 	scanf("%I64d %I64d",&x,&y)
#define sl(x)   	scanf("%lld",&x)
#define sll(x,y)   	scanf("%lld %lld",&x,&y)
#define ff          first
#define ss          second
#define segtree     lt=2*par,rg=2*par+1,mid=(st+en)/2
#define read        freopen("input.txt","r",stdin)
#define write       freopen("output.txt","w",stdout)
using namespace std;
const ll mod=100000007;
bool dp[109][70000];
int ara[10009];
int n,k;
string result;
bool recur(int idx,int sum,string sign)
{
    if(idx>=n)
    {
        if(sum==k){result=sign;return 1;}
        return 0;
    }
    if(sum< -32000 or sum> 32000)return 0;
    if(dp[idx][sum+32001])return 0;
    dp[idx][sum+32001]=1;
    bool res=0;
    res=recur(idx+1,sum+ara[idx],sign+'+') | recur(idx+1,sum-ara[idx],sign+'-') | recur(idx+1,sum*ara[idx],sign+'*');
    if(sum%ara[idx]==0)
        res|=recur(idx+1,sum/ara[idx],sign+'/');
    return res;
}
int main()
{
  int test;
  scanf("%d",&test);
  for(int T=1;T<=test;T++)
  {
      memset(dp,0,sizeof dp);
      scanf("%d",&n);
      for(int i=0;i<n;i++)
        scanf("%d",ara+i);
      scanf("%d",&k);
      result="";
      string temp="";
      if(recur(1,ara[0],temp))
      {
          int j=0;
          for(int i=0;i<n;i++)
          {
              if(i)
                printf("%c",result[j++]);
            printf("%d",ara[i]);
          }
          printf("=%d\n",k);
      }
      else
        printf("NO EXPRESSION\n");
  }
}
