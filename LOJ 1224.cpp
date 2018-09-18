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
string ara[N];
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

void insert_(string s)
{
    node *cur=root;
    int now;
    for(int i=0; i<(int)s.size(); i++)
    {
        if(s[i]=='A')
            now=0;
        else if(s[i]=='C')
            now=1;
        else if(s[i]=='G')
            now=2;
        else if(s[i]=='T')
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
int count_(string s)
{
    int l=s.size();
    int maxi=0;
    node *cur=root;
    int now;
    for(int i=0; i<l; i++)
    {
        if(s[i]=='A')
            now=0;
        else if(s[i]=='C')
            now=1;
        else if(s[i]=='G')
            now=2;
        else if(s[i]=='T')
            now=3;
        if(cur->next[now]!=NULL)
        {
            maxi=max(cur->cnt[now]*(i+1),maxi);
            cur=cur->next[now];
        }
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
        for(int i=0; i<n; i++)
        {
            cin>>ara[i];
        }
        sort(ara,ara+n);
        for(int i=0; i<n; i++)
        {
            insert_(ara[i]);
        }
        int x=0;
        for(int i=0; i<n; i++)
        {
            x=max(x,count_(ara[i]));
        }
        printf("Case %d: %d\n",T,x);
        del(root);
    }
}
