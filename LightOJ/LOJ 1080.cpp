/*
ID: sabertooth
LANG: C++11
TASK:
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define ff first
#define ss second
#define gcd(x,y) abs(__gcd(x,y))
#define all(v) v.begin(),v.end()
#define read freopen("in.txt","r",stdin);
#define write freopen("out.txt","w",stdout);
const int N=1e5;
bool segment[4*N+3];
bool ara[4*N+3];
bool data[N+3];
void build(int node,int st,int en)
{
    if(st==en)
    {
        segment[node]=false;
        ara[node]=data[st];
        return;
    }
    int mid=(st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);
    segment[node]=false;
}
void update(int node,int st,int en,int lo,int hi)
{
    if(en<lo or st>hi)return;
    if(st>=lo and en<=hi)
    {
        segment[node]=!(segment[node]);
        return;
    }
    int mid=(st+en)/2;
    update(node*2,st,mid,lo,hi);
    update(node*2+1,mid+1,en,lo,hi);
    //segment[node]=segment[lt]+segment[rg];
}
bool query(int node,int st,int en,int idx)
{
    if(idx==st and idx==en)
    {
        if(segment[node])return !ara[node];
        else return ara[node];
    }
    bool bit;
    int mid=(st+en)/2;
    if(idx<=mid)
        bit= query(2*node,st,mid,idx);
    else
        bit= query(2*node+1,mid+1,en,idx);
    if(segment[node])
        bit=!bit;
    return bit;
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int T=1; T<=test; T++)
    {
        memset(segment,0,sizeof segment);
        memset(data,0,sizeof data);
        memset(ara,0,sizeof ara);
        string s;
        cin>>s;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')data[i+1]=1;
            else data[i+1]=0;
        }
        int q,x,y;
        char xx;
        scanf("%d",&q);
        build(1,1,n);
        printf("Case %d:\n",T);
        while(q--)
        {
            scanf("%c",&xx);
            while(xx=='\n')
                scanf("%c",&xx);
            if(xx=='I')
            {
                scanf("%d %d",&x,&y);
                update(1,1,n,x,y);
            }
            else
            {
                scanf("%d",&x);
                printf("%d\n",query(1,1,n,x));
            }
        }
    }
}
