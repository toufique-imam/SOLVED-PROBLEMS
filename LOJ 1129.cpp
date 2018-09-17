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
const int N=10000+9;
string ara[N];
struct node
{
    node *a[27];
    bool endmark;
    node()
    {
        endmark=false;
        for(int i=0; i<10; i++)
        {
            a[i]=NULL;
        }
    }
};
node *root;
bool mark;
void insert(string s)
{
    node *curr=root;
    for(int i=0; i<(int)s.size(); i++)
    {
        int id=s[i]-'0';
        if(curr->a[id]==NULL)
        {
            curr->a[id]=new node();
        }
        curr=curr->a[id];
        if(curr->endmark==1)
            mark=1;
    }
    curr->endmark=true;
}
void del(node *cur)
{
    for(int i=0; i<10; i++)
    {
        if(cur->a[i]!=NULL)
            del(cur->a[i]);
    }
    delete(cur);
}
int main()
{
    TEST
    {
        mark=0;
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
            insert(ara[i]);
        }
        printf("Case %d: ",T);
        if(mark==1)
        {
            printf("NO\n");
        }
        else
            printf("YES\n");
        del(root);
    }
}
