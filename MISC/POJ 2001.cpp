/*
ID: sabertooth
LANG: C++11
TASK:
*/
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cassert>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
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

int myLog2(int x)
{
    return __builtin_clz(1) - __builtin_clz(x);
}
string ara[10009];
class node
{
    public:
    bool endmark;
    node *next[27];
    int cnt[27];
    node()
    {
        endmark=0;
        memset(cnt,0,sizeof cnt);
        for(int i=0;i<26;i++)next[i]=NULL;
    }
};
node* root;
void insert_(int x)
{
    node *cur=root;
    int len=ara[x].size();
    for(int i=0;i<len;i++)
    {
        int now=ara[x][i]-'a';
        if(cur->next[now]==NULL)
            cur->next[now]=new node();
        cur->cnt[now]++;
        cur=cur->next[now];
    }
    cur->endmark=1;
}
string count_(int x)
{
    int len=ara[x].size();
    node *cur=root;
    string ans="";
    for(int i=0;i<len;i++)
    {
        int now=ara[x][i]-'a';
        ans+=ara[x][i];
        if(cur->cnt[now]==1)
            return ans;
        cur=cur->next[now];
    }
    return ans;
}
void del(node *cur)
{
    for(int i=0;i<26;i++)
    {
        if(cur->next[i])
            del(cur->next[i]);
    }
    delete cur;
}
int main()
{
    root=new node();
    //map< pair<int,pair< int,int> >,int>mp;
    int i=0;
    while(cin>>ara[i]  and i<1000)
    {
        //cout<<ara[i]<<endl;
        insert_(i);
        i++;
    }
    for(int j=0;j<i;j++)
    {
        cout<<ara[j]<<" "<<count_(j)<<endl;
    }
    del(root);
}
