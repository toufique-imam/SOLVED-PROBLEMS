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
const int N=1e6;
int ara[N+2];
class node
{
public:
    pii L,M,R;
    node()
    {
        L= {-1,-1};
        M= {-1,-1};
        R= {-1,-1};
    }
};
node tree[4*N+2];
map<int,int>ans;
int maxi;
void assign_(int lt,int rg,int par)
{
    tree[par].L=tree[lt].L;
    tree[par].R=tree[rg].R;
    if(tree[lt].L.ff==tree[lt].M.ff)
        tree[par].L=tree[lt].M;
    if(tree[rg].R.ff==tree[rg].M.ff)
        tree[par].R=tree[rg].M;
    //M-M
    if(tree[lt].M.ff==tree[rg].M.ff)tree[par].M= {tree[lt].M.ff,tree[lt].M.sc+tree[rg].M.sc};
    //R-L
    if(tree[lt].R.ff==tree[rg].L.ff and tree[par].M.sc<tree[lt].R.sc+tree[rg].L.sc)tree[par].M= {tree[lt].R.ff,tree[lt].R.sc+tree[rg].L.sc};
    //R-M
    if(tree[lt].R.ff==tree[rg].M.ff and tree[par].M.sc<tree[lt].R.sc+tree[rg].M.sc)tree[par].M= {tree[lt].R.ff,tree[lt].R.sc+tree[rg].M.sc};
    //M-L
    if(tree[lt].M.ff==tree[rg].L.ff and tree[par].M.sc<tree[lt].M.sc+tree[rg].L.sc)tree[par].M= {tree[lt].M.ff,tree[lt].M.sc+tree[rg].L.sc};
    //no overlap
    if(tree[lt].M.sc>=tree[rg].M.sc and tree[lt].M.sc>tree[par].M.sc)tree[par].M=tree[lt].M;
    if(tree[lt].M.sc<tree[rg].M.sc and tree[rg].M.sc>tree[par].M.sc)tree[par].M=tree[rg].M;
}

void build(int par,int st,int en)
{
    tree[par].L= {-1,-1};
    tree[par].R= {-1,-1};
    tree[par].M= {-1,-1};
    if(st==en)
    {
        tree[par].L= {ara[st],1};
        tree[par].M= {ara[st],1};
        tree[par].R= {ara[st],1};
        return;
    }
    int lt=par*2;
    int rg=par*2+1;
    int mid=(st+en)/2;
    build(lt,st,mid);
    build(rg,mid+1,en);
    assign_(lt,rg,par);
}
void query(int par,int st,int en,int lt,int rg)
{
    if(lt>en or rg<st)return;
    if(st>=lt and en<=rg)
    {
        ans[tree[par].M.ff]+=tree[par].M.sc;
        if(tree[par].M.ff!=tree[par].L.ff)
            ans[tree[par].L.ff]+=tree[par].L.sc;
        if(tree[par].M.ff!=tree[par].R.ff)
            ans[tree[par].R.ff]+=tree[par].R.sc;
        maxi=max(maxi,max(ans[tree[par].L.ff],max(ans[tree[par].M.ff],ans[tree[par].R.ff])));
        return;
    }
    int LL=par*2;
    int RR=par*2+1;
    int mid=(st+en)/2;
    query(LL,st,mid,lt,rg);
    query(RR,mid+1,en,lt,rg);
}
int main()
{
    int n,q;
    while(scanf("%d",&n)==1 and n)
    {
        scanf("%d",&q);
        for(int i=1; i<=n; i++)
            scanf("%d",ara+i);
        build(1,1,n);
        int a,b;
        while(q--)
        {
            ans.clear();
            maxi=-1e9;
            scanf("%d %d",&a,&b);
            query(1,1,n,a,b);
            printf("%d\n",maxi);
        }
    }
}
