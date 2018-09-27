/*
ID:sabertooth
TASK:UVA 524
LANG: C++11
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[17];
int prime[35];
int number[20];
void seive()
{
    memset(prime,0,sizeof(prime));
    for(int i=4; i<=35; i+=2)
        prime[i]=1;
    for(int i=3; i<=35; i+=2)
    {
        if(!prime[i])
            for(int j=i*i; j<=35; j+=i)
                prime[j]=1;
    }
}

void backtrack(int att,int n)
{
    if(att==n+1)
    {
        for(int i=1; i<=n; i++)
        {
            printf("%d",number[i]);
            if(i<n)
                printf(" ");
        }
        printf("\n");
    }
    for(int i=2; i<=n; i++)
    {
        if(a[i]==0 && prime[number[att-1]+i]==0)
        {
            if(att==n)
            {
                if(prime[i+1]==0)
                {
                    a[i]=1;
                    number[att]=i;
                    backtrack(att+1,n);
                    a[i]=0;
                }
            }
            else
            {
                a[i]=1;
                number[att]=i;
                backtrack(att+1,n);
                a[i]=0;
            }
        }
    }
}

int main()
{
    seive();
    int n;
    bool f=0;
    int cas=1;
    while(scanf("%d",&n)==1)
    {
        if(f)
            printf("\n");
        printf("Case %d:\n",cas++);
        memset(a,0,sizeof(a));
        a[1]=1;
        number[1]=1;
        backtrack(2,n);
        f=1;
    }
}
