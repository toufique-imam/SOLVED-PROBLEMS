/*
ID: sabertooth9
LANG: C++11
TASK: combo
*/
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int A[4],B[4];
int n;
map< pair<int,pair<int,int> >,bool >mp;
bool subcheck(int a,int b)
{
    if(abs(a-b)<3)return 1;
    if(abs(a-b)>=n-2)return 1;
    return 0;
}
bool check(int x[],int a[])
{
    int cnt=0;
    for(int i=0; i<3; i++)
    {
        if(subcheck(x[i],a[i]))
        cnt++;
    }
    return cnt==3;
}
int main()
{
    freopen("combo.in","r",stdin);
    freopen("combo.out","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<3; i++)
        scanf("%d",A+i);
    for(int i=0; i<3; i++)
        scanf("%d",B+i);
    int ans=0;
    int x[4];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            for(int k=1; k<=n; k++)
            {
                x[0]=i,x[1]=j,x[2]=k;
                pair<int,pair<int,int> >p= {i,{j,k}};
                if(check(x,A) or check(x,B) and mp[p]==0)
                    ans++,mp[p]=1;
            }
        }
    }
    cout<<ans<<endl;
}
