#include <bits/stdc++.h>
#define ll long long
#define M 4000002
using namespace std;
int ara[309][309];
int dp[309][309];
int n;
int recur(int posrow,int poscol)
{
    int r=posrow+1;
    if(posrow>2*n-1)
        return 0;
    if(dp[posrow][poscol]!=-1)return dp[posrow][poscol];
    int limit,limit1;
    if(r<n)
        limit=r+1;
    else
        limit=2*n-r-1;
    if(posrow<n)
        limit1=posrow+1;
    else
        limit1=2*n-posrow-1;
    int ans=ara[posrow][poscol];
    int r1,r2;
    if(r<n)
    {
        r1=poscol;
        r2=poscol+1;
    }
    else
    {
        if(poscol==0)
            r1=r2=poscol;
        else if(poscol==limit1-1)r1=r2=limit-1;
        else
        {
            r1=max(0,poscol-1);
            r2=poscol;
        }
    }
    ans+=max(recur(posrow+1,r1),recur(posrow+1,r2));
    dp[posrow][poscol]=ans;
    return ans;
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int T=1; T<=test; T++)
    {
        memset(ara,0,sizeof ara);
        memset(dp,-1,sizeof dp);
        scanf("%d",&n);
        for(int i=0; i<2*n-1; i++)
        {
            if(i<n)
                for(int j=0; j<=i; j++)
                    scanf("%d",&ara[i][j]);
            else
                for(int j=0; j<2*n-i-1; j++)
                    scanf("%d",&ara[i][j]);
        }
        printf("Case %d: %d\n",T,recur(0,0));
    }
}
