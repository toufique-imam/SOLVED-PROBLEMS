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
const int mod=100000007;
string dp[102][102];
string res,s1,s2;
ll l1,l2;
string recur(int pos1,int pos2)
{
    if(pos1>=l1 or pos2>=l2)
        return "";
    if(dp[pos1][pos2]!="")
        return dp[pos1][pos2];
    string r1,r2;
    if(s1[pos1]==s2[pos2])
    {
        r1=s1[pos1]+recur(pos1+1,pos2+1);
        dp[pos1][pos2]=r1;
    }
    else
    {
        r1=recur(pos1,pos2+1);
        r2=recur(pos1+1,pos2);
        if(r1.length()==r2.length())
            dp[pos1][pos2]=min(r1,r2);
        else if(r1.length()>r2.length())
            dp[pos1][pos2]=r1;
        else
            dp[pos1][pos2]=r2;
    }
    return dp[pos1][pos2];
}
int main()
{
    int test;
    scanf("%d",&test);
    getchar();
    for(int T=1; T<=test; T++)
    {
        cin>>s1>>s2;
        res="";
        for(int i=0;i<101;i++)for(int j=0;j<101;j++)dp[i][j]="";
        l1=s1.size(),l2=s2.size();
        res=recur(0,0);
        printf("Case %d: ",T);
        if(res!="")
        cout<<res<<endl;
        else printf(":(\n");
    }
}
