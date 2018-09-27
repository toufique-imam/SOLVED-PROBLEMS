#include <bits/stdc++.h>
#define ll long long
#define M 4000002
using namespace std;
int dp[209][209];
int ara[20];
int n;
int knapsack(ll pos,ll sz_a,ll sz_b)
{
    if(pos>=n)
        return sz_a==sz_b;
    if(dp[sz_a][sz_b]!=-1)return dp[sz_a][sz_b];
    dp[sz_a][sz_b]=knapsack(pos+1,sz_a+ara[pos],sz_b) | knapsack(pos+1,sz_a,sz_b+ara[pos]);
    return dp[sz_a][sz_b];
}
int main()
{
    int test;
    scanf("%d",&test);
    getchar();
    for(int T=1;T<=test;T++)
    {
        memset(dp,-1,sizeof dp);
        string s;
        getline(cin,s);
        stringstream ss(s);
        int i=0;
        while(ss>>ara[i])
            i++;
        n=i;
        int ans=knapsack(0,0,0);
        if(ans)
            puts("YES");
        else
            puts("NO");
    }
}
