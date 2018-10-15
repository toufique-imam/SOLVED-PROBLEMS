#include <bits/stdc++.h>
//#include<unordered_map>
typedef long long ll;
typedef unsigned long long ull;
#define PQ          priority_queue
#define ii          int,int
#define pii         pair<ii>
#define sf(x)       scanf("%I64d",&x)
#define sff(x,y)    scanf("%I64d %I64d",&x,&y)
#define sl(x)       scanf("%lld",&x)
#define sll(x,y)    scanf("%lld %lld",&x,&y)
#define ff          first
#define sc          second
using namespace std;
#define lchild(n) n*2
#define rchild(n) n*2+1;
const int N=100000;
class node
{
public:
    int cnt[3];
    int lazy;
    node()
    {
        lazy=0;
        memset(cnt,0,sizeof cnt);
    }
};
node operator +(node A,node B)
{
    node C;
    for(int i=0; i<3; i++)
        C.cnt[i]=A.cnt[i]+B.cnt[i];
    C.lazy=A.lazy+B.lazy;
    return C;
}
node tree[4*N+2];
void build(int par,int st,int en)
{
    if(st==en)
    {
        tree[par].cnt[0]=1;
        tree[par].lazy=0;
        tree[par].cnt[1]=tree[par].cnt[2]=0;
        return;
    }
    int lt=lchild(par);
    int rg=rchild(par);
    int mid=(st+en)/2;
    build(lt,st,mid);
    build(rg,mid+1,en);
    tree[par]=tree[lt]+tree[rg];
}
void push_down(int par)
{
    int lt=lchild(par);
    int rg=rchild(par);
    tree[lt].lazy+=tree[par].lazy;
    tree[lt].lazy%=3;
    tree[rg].lazy+=tree[par].lazy;
    tree[rg].lazy%=3;
    tree[par].lazy=0;
}
void free_lazy(int par,int st,int en)
{
    int h=en-st+1;
    if(tree[par].lazy%3==1)
    {
        int x=tree[par].cnt[2];
        for(int i=2; i>0; i--)
            tree[par].cnt[i]=tree[par].cnt[i-1];
        tree[par].cnt[0]=x;
    }
    else if(tree[par].lazy%3==2)
    {
        int x=tree[par].cnt[0];
        for(int i=0; i<2; i++)
            tree[par].cnt[i]=tree[par].cnt[i+1];
        tree[par].cnt[2]=x;
    }
    if(h>1)
        push_down(par);
    tree[par].lazy=0;
    return;
}
void update(int par,int st,int en,int L,int R)
{
    if(tree[par].lazy)
        free_lazy(par,st,en);
    if(L>en or R<st)
        return;
    if(st>=L and en<=R)
    {
        tree[par].lazy++;
        free_lazy(par,st,en);
        return;
    }
    int lt=lchild(par);
    int rg=rchild(par);
    int mid=(st+en)/2;
    update(lt,st,mid,L,R);
    update(rg,mid+1,en,L,R);
    tree[par]=tree[lt]+tree[rg];
}
int query(int par,int st,int en,int L,int R)
{
    if(tree[par].lazy)
        free_lazy(par,st,en);
    if(L>en or R<st)
        return 0;
    if(st>=L and en<=R)
    {
        if(tree[par].lazy)
        {
            free_lazy(par,st,en);
        }
        return tree[par].cnt[0];
    }
    int lt=lchild(par);
    int rg=rchild(par);
    int mid=(st+en)/2;
    return query(lt,st,mid,L,R)+query(rg,mid+1,en,L,R);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int test;
    scanf("%d",&test);
    for(int _t=1; _t<=test; _t++)
    {
        memset(tree,0,sizeof tree);
        int n,q;
        scanf("%d %d",&n,&q);
        build(1,1,n);
        int a,b,c;
        printf("Case %d:\n",_t);
        while(q--)
        {
            scanf("%d %d %d",&a,&b,&c);
            c++,b++;
            if(a)
                printf("%d\n",query(1,1,n,b,c));
            else
                update(1,1,n,b,c);
        }
    }
}
