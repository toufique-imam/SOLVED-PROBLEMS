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
#define MP              make_pair
#define PB              push_back
#define EB              emplace_back
#define segtree         int mid=(st+en)/2,lt=node*2,rg=node*2+1
#define MERGE(v1,v2,v)  merge(all(v1),all(v2),back_inserter(v))

int myLog2(int x)
{
    return __builtin_clz(1) - __builtin_clz(x);
}
const int N=200000+9;
pair<int,int> ara[N];
int points[N];
int tot[N];
int main()
{
    TEST
    {
        map<int,bool>mp_t;
        map<int,int>mp;
        memset(tot,0,sizeof tot);
        int n,q,a,b,sz=0,idx=1;
        scanf("%d%d",&n,&q);
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&a,&b);
            if(a>b)
                swap(a,b);
            ara[i]=MP(a,b);
            assert(sz<N);
            if(mp_t[a]==0)
            {
                mp_t[a]=1;
                points[sz++]=a;
            }
            if(mp_t[b]==0)
            {
                mp_t[b]=1;
                points[sz++]=b;
            }
        }
        sort(points,points+sz);
        for(int i=0; i<sz; i++)
        {
            mp[points[i]]=idx;
            idx+=2;
        }
        for(int i=0; i<n; i++)
        {
            tot[mp[ara[i].ff]]++;
            tot[mp[ara[i].ss]+1]--;
        }
        for(int i=1; i<=idx; i++)
        {
            tot[i]+=tot[i-1];
        }
        printf("Case %d:\n",T);
        int tmp;
        int ans;
        while(q--)
        {
            scanf("%d",&a);
            tmp=lower_bound(points,points+sz,a)-points;
            if(tmp==sz)
            {
                puts("0");
                continue;
            }
            ans=mp[points[tmp]];
            if(points[tmp]>a)
                ans--;
            printf("%d\n",max(0,tot[ans]));
        }
    }
}
