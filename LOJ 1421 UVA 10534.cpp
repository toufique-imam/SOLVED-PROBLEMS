#include<bits/stdc++.h>
//#include<unordered_map>
//#include<unordered_set>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
/*
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
priority_queue<int, greater<int>, pairing_heap_tag> pq[1009];
#define fbo         find_by_order
#define ook         order_of_key
*/

typedef long long ll;
typedef unsigned long long ull;
#define gcd(A,B)        __gcd(A,B)
#define PQ              priority_queue
#define ii              int,int
#define pll             pair<ll,ll>
#define PI              2*acos(0.0)
#define all(v)          v.begin(),v.end()
#define pii             pair<ii>
#define pb              push_back
#define sf(x)           scanf("%I64d",&x)
#define sff(x,y)        scanf("%I64d %I64d",&x,&y)
#define sl(x)           scanf("%lld",&x)
#define sll(x,y)        scanf("%lld %lld",&x,&y)
#define ff              first
#define ss              second
#define segtree         lt=2*par,rg=2*par+1,mid=(st+en)/2
#define read            freopen("input.txt","r",stdin)
#define write           freopen("output.txt","w",stdout)
#define fast            ios_base::sync_with_stdio(0),cin.tie(0)
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define max_ull         18446744073709551615
#define max_ll          9223372036854775807;
#define set(N,cur)      N=(N|(1LL<<cur))
#define reset(N,cur)    N=(N&(~(1LL<<cur)))
#define check(N,cur)    ((N&(1LL<<cur))==0)
#define all(v)          v.begin(),v.end()
#define reunique(v)     v.resize(std::unique(all(v)) - v.begin())
typedef vector< vector<ll> >matrix;
/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction
const int sz=1e5+9;
int LIS1[sz];
int LIS2[sz];
int ara1[sz];
int main()
{
    int test;
    scanf("%d",&test);
    multiset<int>s;
    multiset<int>::iterator itr;
    for(int T=1; T<=test; T++)
    {
        s.clear();
        memset(LIS1,0,sizeof LIS1);
        memset(LIS2,0,sizeof LIS2);
        int n;
        scanf("%d",&n);
        int j=n-1;
        for(int i=0; i<n; i++,j--)
        {
            scanf("%d",&ara1[i]);
            LIS1[i]=LIS2[i]=1;
        }
        for(int i=0; i<n; i++)
        {
            s.insert(ara1[i]);
            itr=s.lower_bound(ara1[i]);
            itr++;
            if(itr!=s.end())
                s.erase(itr);
            LIS1[i]=max(LIS1[i],(int)s.size());
            //if(i)LIS1[i]=max(LIS1[i],LIS1[i-1]);
        }
        s.clear();
        for(int j=n-1; j>-1; j--)
        {
            s.insert(ara1[j]);
            itr=s.lower_bound(ara1[j]);
            itr++;
            if(itr!=s.end())
                s.erase(itr);
            LIS2[j]=max(LIS2[j],(int)s.size());
            //if(j!=n-1)LIS2[j]=max(LIS2[j],LIS2[j+1]);
        }
        int ans=0;
        for(int i=0; i<n; i++)
            if(2*min(LIS1[i],LIS2[i])-1>ans)
                ans=2*min(LIS1[i],LIS2[i])-1;
        printf("Case %d: %d\n",T,ans);
    }
}
