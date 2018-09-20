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
#define lead_zero(x)    __builtin_clz(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define reunique(v)     v.resize(std::unique(all(v)) - v.begin())
int myLog2(int x)
{
    return lead_zero(1) - lead_zero(x);
}

//___________Static Trie__________//
//-------CPU :   0.400s  --------//
//-------Memory: 20632kb -------//

const int N=50000*32+3;
int sum[50009];
int node[N][2];
int ans[N];
int nnode;
void transform_(char *ans,int x)
{
    for(int i=0; i<32; i++)
    {
        ans[i]='0';
    }
    int i=31;
    while(x>0)
    {
        ans[i--]=(x%2)+'0';
        x/=2;
    }
    //return ans;
}
void Insert(char *s,int n)
{
    int id;
    int cur=0;
    for(int i=0;i<32;i++){
        id=s[i]-'0';
        if(node[cur][id]==-1){
            node[cur][id]=++nnode;
            assert(nnode<N);
            memset(node[nnode],-1,sizeof node[nnode]);
        }
        cur=node[cur][id];
    }
    ans[cur]=n;
}
int find_(char *s,int n,bool rev)
{
    int id,cur=0;
    for(int i=0;i<32;i++)
    {
        id=s[i]-'0';
        if(rev)id=!id;
        if(node[cur][id]==-1){
            id=!id;
        }
        cur=node[cur][id];
    }
    return n^ans[cur];
}

//____________ Dynamic Trie___________//
//-------CPU :   1.532s  ------------//
//-------Memory: 26040kb -----------//
/*
class node
{
public:
    node *next[2];
    int endmark;
    node()
    {
        next[0]=next[1]=NULL;
        endmark=0;
    }
};
node *root;

void Insert(string s,int x)
{
    int len=s.size();
    int now;
    node *cur=root;
    for(int i=0; i<32; i++)
    {
        now=s[i]-'0';
        if(cur->next[now]==NULL)
        {
            cur->next[now]=new node();
        }
        cur=cur->next[now];
    }
    cur->endmark=x;
}
int find_(string s,int x,bool rev)
{
    int len=s.size();
    int now;
    node *cur=root;
    for(int i=0; i<32; i++)
    {
        now=s[i]-'0';
        if(rev)
            now=!now;
        if(cur->next[now]==NULL)
            now=!now;
        cur=cur->next[now];
    }
    return cur->endmark^x;
}
void del(node *cur)
{
    if(cur->next[0])
        del(cur->next[0]);
    if(cur->next[1])
        del(cur->next[1]);
    delete cur;
}
*/
int main()
{
    TEST
    {
        //root=new node();
        memset(ans,0,sizeof ans);
        memset(node,-1,sizeof node);
        memset(sum,0,sizeof sum);
        nnode=0;
        int n,x;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&x);
            if(i)sum[i]=sum[i-1]^x;
            else sum[i]=x;
        }
        char a[33];
        transform_(a,0);
        Insert(a,0);
        int mini=1e9;
        int maxi=-1e9;
        for(int i=0; i<n; i++)
        {
            transform_(a,sum[i]);

            x=find_(a,sum[i],1);
            maxi=max(maxi,x);

            x=find_(a,sum[i],0);
            mini=min(mini,x);

            Insert(a,sum[i]);
        }
        printf("Case %d: %d %d\n",T,maxi,mini);
        //del(root);
    }
}
