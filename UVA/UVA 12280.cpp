#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii             pair<int,int>
#define pll             pair<ll,ll>
#define ff              first
#define ss              second
#define read            freopen("in.txt","r",stdin);
#define write           freopen("out.txt","w",stdout);
#define TEST            int test;scanf("%d",&test);for(int T=1;T<=test;T++)
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define all(v)          v.begin(),v.end()
#define reunique(v)     v.resize(std::unique(all(v)) - v.begin())
#define PQ              priority_queue< ll,vector<ll>,greater<ll> >pq;
#define PQii            priority_queue< pii,vector< pii >,greater< pii > >pq;
#define PQll            priority_queue< pll,vector< pll >,greater< pll > >pq;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int myLog2(int x)
{
    return __builtin_clz(1) - __builtin_clz(x);
}
void outsame(string g1,string g2)
{
    printf("........||........\n.../\\...||.../\\...\n../..\\..||../..\\..\n./....\\.||./....\\.\n");
    printf("/");
    cout<<g1;
    for(int i=0; i<6-(int)g1.size(); i++)
        printf(".");
    printf("\\||/");
    cout<<g2;
    for(int i=0; i<6-(int)g2.size(); i++)
        printf(".");
    printf("\\\n");
    printf("\\______/||\\______/\n........||........\n");
}
void outbig(string g1,string g2)
{
    printf("........||.../\\...\n........||../..\\..\n.../\\...||./....\\.\n../..\\..||/");
    cout<<g2;
    for(int i=0;i<6-(int)g2.size();i++)printf(".");
    printf("\\\n./....\\.||\\______/\n/");
    cout<<g1;
    for(int i=0;i<6-(int)g1.size();i++)printf(".");
    printf("\\||........\n\\______/||........\n");
}
void outsmall(string g1,string g2)
{
    printf(".../\\...||........\n../..\\..||........\n./....\\.||.../\\...\n/");
    cout<<g1;
    for(int i=0; i<6-(int)g1.size(); i++)
        printf(".");
    printf("\\||../..\\..\n\\______/||./....\\.\n........||/");
    cout<<g2;
    for(int i=0; i<6-(int)g2.size(); i++)
        printf(".");
    printf("\\\n........||\\______/\n");
}
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int T=1; T<=tc; T++)
    {
        string s;
        int pos1,pos2;
        bool f1,f2,tmp1,tmp2;
        f1=f2=0;
        tmp1=tmp2=0;
        int sum1,sum2;
        int sum3,sum4;
        sum1=sum2=0;
        sum3=sum4=0;
        string g1,g2;
        for(int i=0; i<8; i++)
        {
            cin>>s;
            tmp1=tmp2=0;
            // cout<<s<<endl;
            for(int j=0; j<(int)s.size(); j++)
            {
                if(tmp1==0 and tmp2==0)
                    tmp1=1;
                if(s[j]=='/' && f1==0 and tmp1)
                {
                    f1=1;
                    pos1=i;
                }
                else if(s[j]=='/' && f2==0 and tmp2)
                {
                    f2=1;
                    pos2=i;
                }
                else if(s[j]=='|')
                {
                    tmp1=0;
                    tmp2=1;
                }
                else if(isalpha(s[j]))
                {
                    if(tmp1)
                    {
                        g1+=s[j];
                        sum1+=total_1s(int(s[j]));
                        sum2+=7-total_1s(int(s[j]));
                    }
                    else
                    {
                        g2+=s[j];
                        sum3+=total_1s(int(s[j]));
                        sum4+=7-total_1s(int(s[j]));
                    }
                }
            }
        }
        printf("Case %d:\n",T);
        int ans1=sum1*500+sum2*250;
        int ans2=sum3*500+sum4*250;
        if(pos1<pos2)
        {
            if(ans1<ans2)
                puts("The figure is correct.");
            else
            {
                if(ans1==ans2)
                    outsame(g1,g2);
                else
                    outbig(g1,g2);
            }
        }
        else if(pos1>pos2)
        {
            if(ans1>ans2)
                puts("The figure is correct.");
            else
            {
                if(ans1==ans2)
                    outsame(g1,g2);
                else
                    outsmall(g1,g2);
            }
        }
        else
        {
            if(ans1==ans2)
                puts("The figure is correct.");
            else
            {
                if(ans1>ans2)
                    outbig(g1,g2);
                else
                    outsmall(g1,g2);
            }
        }
    }
}
