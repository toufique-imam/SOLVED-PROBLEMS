
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define eps             1e-9
#define inf             0x3f3f3f3f
#define INF             2e18
#define PI              acos(-1.0)
#define ff              first
#define ss              second
#define all(v)          v.begin(),v.end()
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(min(a,b),min(c,d))
#define max4(a,b,c,d)   max(max(a,b),max(c,d))
#define max5(a,b,c,d,e) max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e) min(min3(a,b,c),min(d,e))
#define Iterator(a)     __typeof__(a.begin())
#define read            freopen("in.txt","r",stdin);
#define write           freopen("out.txt","w",stdout);
#define TEST            int test;scanf("%d",&test);for(int T=1;T<=test;T++)
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define reunique(v)     v.resize(std::unique(all(v)) - v.begin())
#define MP              make_pair
#define PB              push_back
#define EB              emplace_back
#define segtree         int mid=(st+en)/2,lt=node*2,rg=node*2+1
#define MERGE(v1,v2,v)  merge(all(v1),all(v2),back_inserter(v))
#define loop(a)         for(__typeof__(a.begin())itr=a.begin();itr!=a.end();itr++)
#define log2_(x)        __builtin_clz(1) - __builtin_clz(x);

//n! ~ sqrt(2*pi*n)*n^n*e^-n

int ara[30];
class data
{
public:
    int key;
    int lv;
    int sz;
    data *left,*right;
    data()
    {
        left=right=NULL;
        key=sz=0;
    }
};
data *root;
data* insert_(data *cur,int val)
{
    if(cur==NULL)
    {
        cur=new data();
        cur->key=val;
        cur->sz=1;
        return cur;
    }
    else if(cur->key>val)
    {
        cur->sz++;
        cur->left=insert_(cur->left,val);
        //cur->sz+=cur->left->sz;
    }
    else
    {
        cur->sz++;
        cur->right=insert_(cur->right,val);
        //cur->sz+=cur->right->sz;
    }
    return cur;
}
void del(data *cur)
{
    if(cur!=NULL)
    {
        if(cur->left)
            del(cur->left);
        if(cur->right)
            del(cur->right);
        delete cur;
    }
    else
        return;
}

const ll mod=9999991;
ll ncr[39][39];
ll solve(data *cur)
{
    ll ans=1;
    if(cur!=NULL)
    {
        if(cur->left!=NULL and cur->right!=NULL)
        {
            ans=(ans*ncr[cur->left->sz+cur->right->sz][cur->left->sz])%mod;
            ans=(ans*solve(cur->left))%mod;
            ans=(ans*solve(cur->right))%mod;
        }
        else if(cur->right!=NULL)
        {
            ans=(ans*ncr[cur->right->sz][cur->right->sz])%mod;
            ans=(ans*solve(cur->right))%mod;
        }
        else if(cur->left!=NULL)
        {
            ans=(ans*ncr[cur->left->sz][cur->left->sz])%mod;
            ans=(ans*solve(cur->left))%mod;
        }
    }
    return ans%mod;
}
void show(data *cur)
{
    if(cur->left!=NULL)
        show(cur->left);
    cout<<cur->key<<" "<<cur->sz<<endl;
    if(cur->right!=NULL)
        show(cur->right);
}
int main()
{
    ncr[0][0]=1;
    for(int i=1; i<=29; i++)
    {
        ncr[i][0]=1;
        for(int j=1; j<=i; j++)
        {
            ncr[i][j]=ncr[i-1][j-1]+ncr[i-1][j];
            ncr[i][j]%=mod;
        }
    }
    TEST
    {
        //memset(level,0,sizeof level);
        del(root);
        root=NULL;
  //      maxi=0;
        data *cur=root;
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&ara[i]);
        }
        root=insert_(cur,ara[0]);
        //level[root->lv]++;
        for(int i=1; i<n; i++)
        {
            // llvl=-1;
            insert_(root,ara[i]);
            //level[llvl]++;
        }
       // show(root);
        ll ans=solve(root);
        printf("%lld\n",ans);
    }
}
