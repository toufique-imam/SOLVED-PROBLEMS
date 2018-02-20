#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int ans[209][209];
    memset(ans,0,sizeof(ans));
    for(int i=1; i<201; i++)
    {
        for(int j=1; j<201; j++)
        {
            if(ans[i][j]==0)
            {
                if(i==1)
                    ans[i][j]=max(i,j);
                else if(i==2)
                {
                    int x=j;
                    x/=4;
                    x*=4;
                    if(j%4==3)
                        x+=2;
                    ans[i][j]=max(ans[i][j],i*j-x);
                }
                else
                {
                    if(j%2)
                    {
                        ans[i][j]=(i/2)*(j);
                        if(i%2)
                            ans[i][j]+=(j/2)+1;
                    }
                    else
                        ans[i][j]=i*(j/2);
                }
                ans[j][i]=ans[i][j];
            }
        }
    }
    int test;
    scanf("%d",&test);
    for(int t=1; t<=test; t++)
    {
        int i,j;
        scanf("%d %d",&i,&j);
        printf("Case %d: %d\n",t,ans[i][j]);
    }
}
