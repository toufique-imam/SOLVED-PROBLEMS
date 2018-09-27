#include <bits/stdc++.h>
//#include<unordered_map>
typedef long long ll;
typedef unsigned long long ull;
#define PQ 			priority_queue
#define ii 			int,int
#define pii 		pair<ii>
#define sf(x) 		scanf("%I64d",&x)
#define sff(x,y) 	scanf("%I64d %I64d",&x,&y)
#define sl(x)   	scanf("%lld",&x)
#define sll(x,y)   	scanf("%lld %lld",&x,&y)
#define ff          first
#define sc          second
using namespace std;
#define Lchild(n) n*2
#define Rchild(n) n*2+1;
const int N=1e5;
int ara[N+2];
int tree[4*N+2];
void build(int par,int st,int en)
{
    if(st==en)
    {
        tree[par]=ara[st];
        return;
    }
    int lt=Lchild(par);
    int rg=Rchild(par);
    int mid=(st+en)/2;
    build(lt,st,mid);
    build(rg,mid+1,en);
    tree[par]=tree[lt]+tree[rg];
}
int query(int par,int st,int en,int L,int R)
{
    if(L>en or R<st)return 0;
    if(st>=L and en<=R)
        return tree[par];
    int lt=Lchild(par);
    int rg=Rchild(par);
    int mid=(st+en)/2;
    return query(lt,st,mid,L,R)+query(rg,mid+1,en,L,R);
}
void update(int par,int st,int en,int L,int val)
{
    if(L>en or L<st)
        return;
    if(st>=L and en<=L)
    {
        tree[par]+=val;
        return;
    }
    int lt=Lchild(par);
    int rg=Rchild(par);
    int mid=(st+en)/2;
    update(lt,st,mid,L,val);
    update(rg,mid+1,en,L,val);
    tree[par]=tree[lt]+tree[rg];
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int _t=1;_t<=test;_t++)
    {
        memset(tree,0,sizeof tree);
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++)
            scanf("%d",&ara[i]);
        int a,b,c;
        build(1,1,n);
        printf("Case %d:\n",_t);
        while(q--)
        {
            scanf("%d",&a);
            if(a==1)
            {
                scanf("%d",&b);
                b++;
                int t=query(1,1,n,b,b);
                printf("%d\n",t);
                update(1,1,n,b,-t);
            }
            else if(a==2)
            {
                scanf("%d %d",&b,&c);
                b++;
                update(1,1,n,b,c);
            }
            else if(a==3)
            {
                scanf("%d %d",&b,&c);
                b++;
                c++;
                printf("%d\n",query(1,1,n,b,c));
            }
        }
    }
}
