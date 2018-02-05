#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main()
{
    //testcase();
    //freopen("input.txt","r",stdin);
    ll n,ans;
    ll cnt[10];
    while(scanf("%lld",&n)==1)
    {
        if(n==0)
            printf("10\n");
        else if(n==1)
            printf("1\n");
        else
        {
            memset(cnt,0,sizeof(cnt));
            for(int i=2; i<10 && n>0; i++)
            {
                if(n%i==0)
                {
                    ans=0;
                    while(n%i==0)
                    {
                        n/=i;
                        ans++;
                    }
                    cnt[i]=ans;
                }
            }
            if(n!=1)
            {
                printf("-1\n");
            }
            else
            {
                //9//8//6//4//
                for(int i=9; i>1; i--)
                {
                    if(i==9)
                    {
                        while(cnt[3]>=2)
                        {
                            cnt[9]++;
                            cnt[3]-=2;
                        }
                    }
                    else if(i==8)
                    {
                        while(cnt[2]>=3)
                        {
                            while(cnt[2]>=3)
                            {
                                cnt[2]-=3;
                                cnt[8]++;
                            }
                        }
                    }
                    else if(i==6)
                    {
                        while(cnt[3] && cnt[2])
                        {
                            cnt[3]--;
                            cnt[2]--;
                            cnt[6]++;
                        }
                    }
                    else if(i==4)
                    {
                        while(cnt[2]>=2)
                        {
                            cnt[2]-=2;
                            cnt[4]++;
                        }
                    }
                }
                for(int i=2;i<=9;i++)
                    for(int j=1;j<=cnt[i];j++)
                        printf("%d",i);
                printf("\n");
            }
        }
    }
}
