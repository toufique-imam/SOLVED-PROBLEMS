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
int main()
{
    int tc;
    scanf("%d",&tc);
    getchar();
    bool f=0;
    for(int T=1;T<=tc;T++)
    {
        bool f1,f2,f3;
        f1=f2=f3=0;
        string s;
        getline(cin,s);
        string g;
        map<char,double>mp;
        for(int i=0;i<(int)s.size();i++)
        {
            if(s[i]=='=')
            {
                if(s[i-1]=='P')f1=1;
                if(s[i-1]=='U')f2=1;
                if(s[i-1]=='I')f3=1;
                g="";
                int j=i+1;
                while(!isalpha(s[j]))
                {
                    g+=s[j];
                    j++;
                }
                stringstream ss(g);
                ss>>mp[s[i-1]];
                if(s[j]=='m')
                    mp[s[i-1]]/=1000;
                if(s[j]=='k')
                    mp[s[i-1]]*=1000;
                if(s[j]=='M')
                    mp[s[i-1]]*=1000000;
            }
        }
        printf("Problem #%d\n",T);
        if(f1 && f2)
        {
            printf("I=%0.2fA\n",mp['P']/mp['U']);
        }
        else if(f2 && f3)
        {
            printf("P=%0.2fW\n",mp['U']*mp['I']);
        }
        else
        {
            printf("U=%0.2fV\n",mp['P']/mp['I']);
        }
        puts("");
    }
}
