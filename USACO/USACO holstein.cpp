/*
ID: sabertooth
LANG: C++11
TASK: holstein
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class vitamin
{
public:
    int V[30];
};
vitamin G[20];
vitamin need;
int g,n;
bool canuse[30];
bool bigger(vitamin X)
{
    for(int i=0; i<n; i++)if(X.V[i]<need.V[i])return 0;
    return 1;
}
void input(int pos)
{
    for(int i=0; i<n; i++)scanf("%d",&G[pos].V[i]);
}
int ans=1e9;
int ansara[20];
void recur(vitamin taken,int tot,int pos)
{
    if(bigger(taken) and ans>tot)
    {
        int pos=0;
        ans=tot;
        for(int i=0; i<g; i++)if(canuse[i])ansara[pos++]=i+1;
        return;
    }
    for(int i=pos; i<g; i++)
        if(!canuse[i])
        {
            canuse[i]=1;
            for(int j=0; j<n; j++)taken.V[j]+=G[i].V[j];
            recur(taken,tot+1,i);
            canuse[i]=0;
            for(int j=0; j<n; j++)taken.V[j]-=G[i].V[j];
        }
}
int main()
{
    freopen("holstein.in","r",stdin);
    freopen("holstein.out","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<n; i++)scanf("%d",&need.V[i]);
    scanf("%d",&g);
    for(int i=0; i<g; i++)input(i);
    vitamin taken;
    for(int i=0; i<n; i++)taken.V[i]=0;
    recur(taken,0,0);
    printf("%d ",ans);
    for(int i=0; i<ans; i++)
    {
        printf("%d",ansara[i]);
        if(i!=ans-1)
            printf(" ");
    }
    printf("\n");
}
