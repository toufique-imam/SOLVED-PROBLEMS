#include<bits/stdc++.h>
using namespace std;

int n;
pair<int,int> ara[109];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d",&n)==1 and n)
    {
        int a,b;
        for(int i=0; i<2*n; i++)
        {
            scanf("%d%d",&ara[i].first,&ara[i].second);
        }
        int ansa=-1,ansb=-1;
        int cnt=0,tmp;
        bool f=1;
        for(int i=500; i>-501 and f; i--)
        {
            for(int j=-500; j<501 and f; j++)
            {
                a=i;
                b=j;
                cnt=0;
                for(int k=0; k<2*n; k++)
                {
                    tmp=a*ara[k].first+b*ara[k].second;
                    if(tmp==0){
                        cnt=0;
                        break;
                    }
                    if(tmp<0)
                        cnt++;
                }
                if(cnt==n)
                {
                    ansa=a;
                    ansb=b;
                    f=0;
                    break;
                }
            }
        }
        printf("%d %d\n",ansa,ansb);
    }
}
