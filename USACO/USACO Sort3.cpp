/*
ID: sabertooth
LANG:C++11
TASK: sort3
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ara[1009];
int main()
{
    freopen("sort3.in","r",stdin);
    freopen("sort3.out","w",stdout);
    int n;
    scanf("%d",&n);
    int c1,c2;
    c1=c2=0;
    int ans=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d",ara+i);
        if(ara[i]==1)
            c1++;
        if(ara[i]==2)
            c2++;
    }
    for(int i=c1; i<n; i++)
    {
        if(ara[i]==1)
        {
            int t=0;
            for(int j=t=0; j<c1; j++)
            {
                if(ara[j]==2)
                {
                    t=j;
                    break;
                }
                else if(ara[j]==3)
                {
                    t=j;
                }
            }
            swap(ara[t],ara[i]);
            ans++;
        }
    }
    for(int i=c1+c2; i<n; i++)
    {
        if(ara[i]==2)
            ans++;
    }
    printf("%d\n",ans);
}
