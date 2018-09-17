#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e5;
int ara[N+2];
int tree[4*N+2];
void build(int node,int st,int en)
{
    if(st==en)
    {
        tree[node]=ara[en];
        return;
    }
    int leftt=node*2;
    int rightt=node*2+1;
    int mid=(st+en)/2;
    build(leftt,st,mid);
    build(rightt,mid+1,en);
    tree[node]=min(tree[leftt],tree[rightt]);
}
int query(int node,int st,int en,int l,int r)
{
    if(l>en or r<st)
        return 1e9;
    if(st>=l and en<=r)
        return tree[node];
    int rg=node*2+1;
    int lt=node*2;
    int mid=(st+en)/2;
    return min(query(lt,st,mid,l,r),query(rg,mid+1,en,l,r));
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int _t=1;_t<=test;_t++)
    {
        memset(ara,0,sizeof ara);
        memset(tree,0,sizeof tree);
        int n,q,x,y;
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++)scanf("%d",&ara[i]);
        build(1,1,n);
        printf("Case %d:\n",_t);
        while(q--)
        {
            scanf("%d %d",&x,&y);
            printf("%d\n",query(1,1,n,x,y));
        }
    }
}
