/*
ID: sabertooth
LANG: C++11
TASK:
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
int myLog2(int x)
{
    return __builtin_clz(1) - __builtin_clz(x);
}
const int N=50009;
char ara[N][52];
class node
{
public:
    node *next[4];
    int cnt[4];
    bool endmark;
    node()
    {
        memset(cnt,0,sizeof cnt);
        for(int i=0; i<4; i++)
            next[i]=NULL;
        endmark=0;
    }
};
node *root;

void insert_(int idx)
{
    node *cur=root;
    int now;
    for(int i=0; i<(int)strlen(ara[idx]); i++)
    {
        if(ara[idx][i]=='A')
            now=0;
        else if(ara[idx][i]=='C')
            now=1;
        else if(ara[idx][i]=='G')
            now=2;
        else if(ara[idx][i]=='T')
            now=3;
        if(cur->next[now]==NULL)
        {
            cur->next[now]=new node();
        }
        cur->cnt[now]++;
        cur=cur->next[now];
    }
    cur->endmark=true;
}
int count_(int idx)
{
    int l=strlen(ara[idx]);
    int maxi=0;
    node *cur=root;
    int now;
    for(int i=0; i<l; i++)
    {
        if(ara[idx][i]=='A')
            now=0;
        else if(ara[idx][i]=='C')
            now=1;
        else if(ara[idx][i]=='G')
            now=2;
        else if(ara[idx][i]=='T')
            now=3;
        if(cur->next[now]!=NULL)
        {
            maxi=max(cur->cnt[now]*(i+1),maxi);
            cur=cur->next[now];
        }
        else break;
    }
    return maxi;
}
void del(node *cur)
{
    for(int i=0; i<4; i++)
    {
        if(cur->next[i]!=NULL)
        {
            del(cur->next[i]);
        }
    }
    delete cur;
}
int main()
{
    TEST
    {
        root=new node();
        int n;
        scanf("%d",&n);
        getchar();
        for(int i=0; i<n; i++)
        {
            scanf("%s",&ara[i]);
            insert_(i);
        }
        int x=0;
        for(int i=0; i<n; i++)
        {
            x=max(x,count_(i));
        }
        printf("Case %d: %d\n",T,x);
        del(root);
    }
}
