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
const int N=111111;
//string ara[N];
//map<string,int>mp;
int node[N][52];
int cnt_word[N];
char s[N];
char a[N];
int root,nnode;
void Insert()
{
    int len=strlen(s);
    int  now=root,id;
    for(int i=0; i<len; i++)
    {
        if(s[i]>='A' and s[i]<='Z')
            id=s[i]-'A';
        else
            id=s[i]-'a'+26;
        if(node[now][id]==-1)
        {
            node[now][id]=++nnode;
            memset(node[nnode],-1,sizeof node[nnode]);
        }
        now=node[now][id];
    }
    cnt_word[now]++;
}
int find_()
{
    int len=strlen(s);
    int now=root,id;
    for(int i=0;i<len;i++)
    {
        if(s[i]>='A' and s[i]<='Z')
            id=s[i]-'A';
        else
            id=s[i]-'a'+26;
        if(node[now][id]==-1)return 0;
        now=node[now][id];
    }
    return cnt_word[now];
}
int main()
{
    // read;
    //write;
    TEST
    {
        root=0;
        nnode=0;
        memset(node,-1,sizeof node);
        memset(cnt_word,0,sizeof cnt_word);
        int n,l;
        scanf("%d",&n);
        getchar();
        for(int i=0; i<n; i++)
        {
            scanf("%s",s);
            l=strlen(s);
            if(l>2)
                sort(s+1,s+l-1);
            Insert();
        }
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",T);
        getchar();
        ll ans;
        while(q--)
        {
            ans=1;
            gets(a);
            char *p=strtok(a," ");
            while(p)
            {
                strcpy(s,p);
                l=strlen(s);
                if(l>2)
                    sort(s+1,s+l-1);
                ans*=find_();
                p=strtok(NULL," ");
            }
            printf("%lld\n",ans);
        }
    }
}
