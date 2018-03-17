#include <bits/stdc++.h>
using namespace std;

int leftt[109];
int rightt[109];

void clean(){
    memset(leftt,0,sizeof leftt);
    memset(rightt,0,sizeof rightt);
}
int main()
{
    int test;
    scanf("%d\n",&test);
    for(int _t=1; _t<=test; _t++)
    {
        clean();
        int n;
        scanf("%d",&n);
        int t1,t2;
        t1=t2=0;
        for(int i=0; i<n; i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            if(!leftt[a] and !rightt[b]){
                leftt[a]++;
                rightt[b]++;
                t1+=c;
            }
            else
            {
                rightt[a]++;
                leftt[b]++;
                t2+=c;
            }
        }
        printf("Case %d: %d\n",_t,min(t1,t2));
    }
}
