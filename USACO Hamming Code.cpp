/*
ID: sabertooth
LANG:C++11
TASK: hamming
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,b,d;
int lim;
int sofar[200];
int pos;
int hamming(int x,int y)
{
    int cnt=0;
    while(x>0 or y>0)
    {
        int xx=x%2;
        int yy=y%2;
        if(xx!=yy)
            cnt++;
        x/=2;
        y/=2;
    }
    return cnt;
}
bool check(int x)
{
    for(int i=0; i<pos; i++)
    {
        if(hamming(sofar[i],x)<d)
            return 0;
    }
    return 1;
}
void recur(int x)
{
    if(pos>=n)
        return;
    for(int i=x+1; i<=lim; i++)
    {
        if(pos>=n)
            return;
        if(check(i))
        {
            sofar[pos++]=i;
            recur(i);
        }
    }
}
int main()
{
    freopen("hamming.in","r",stdin);
    freopen("hamming.out","w",stdout);
    scanf("%d %d %d",&n,&b,&d);
    lim=powl(2,b);
    sofar[0]=0;
    pos=1;
    recur(0);
    bool f=0;
    for(int i=0; i<pos; i++)
    {
        printf("%d",sofar[i]);
        if(i%10!=9 and i!=pos-1)
        {
            f=0,printf(" ");
        }
        else
        {
            f=1,printf("\n");
        }
    }
    if(!f)
        printf("\n");
}
