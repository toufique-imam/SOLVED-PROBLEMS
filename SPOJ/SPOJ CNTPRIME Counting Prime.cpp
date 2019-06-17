#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_set_rev = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using dijkstra = priority_queue<T, vector<T>, greater<T>>;

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define fbo find_by_order //k th index
#define ook order_of_key // strictly smaller than k
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define max_ull 18446744073709551615
#define max_ll 9223372036854775807
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define max5(a, b, c, d, e) max(max3(a, b, c), max(d, e))
#define min5(a, b, c, d, e) min(min3(a, b, c), min(d, e))
#define lead_zero(x) __builtin_clzll(x)
#define trail_zero(x) __builtin_ctzll(x)
#define total_1s(x) __builtin_popcountll(x)
#define first_1(x) __builtin_ffsll(x)
#define log2_(x) __builtin_clz(1) - __builtin_clz(x)
#define isLeap(x) ((x % 400 == 0) || (x % 100 ? x % 4 == 0 : false))
#define QUERY int test;scanf("%d", &test);for (int _T = 1; _T <= test; _T++)
#define FAST ios_base::sync_with_stdio(0), cin.tie(0)
#define all(v) v.begin(), v.end()
#define reunique(v) v.resize(std::unique(all(v)) - v.begin())
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
#define MERGE(v1, v2, v) merge(all(v1), all(v2), back_inserter(v))
#define MP make_pair
#define EB emplace_back
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
#define in_range(v, r, l) upper_bound(all(v), r) - lower_bound(all(v), l)
#define LCM(a,b) (a/__gcd(a,b))*b;
template<typename T1,typename T2>
ostream& operator<<(ostream &fout,const pair<T1,T2>&ps) {
    fout<<ps.ff<<" "<<ps.ss;
    return fout;
}
template<typename T1,typename T2>
ostream& operator<<(ostream &fout,const map<T1,T2>&mp) {
    for(pair<T1,T2> i:mp)
        fout<<i.first<<" : "<<i.second<<endl;
    return fout;
}
template<typename T>
ostream& operator<<(ostream& fout,const vector<T>&v) {
    for(T i:v)
        fout<<i<<"\n";
    return fout;
}
template<typename T>
ostream& operator<<(ostream& fout,const set<T>&v) {
    for(T i:v)
        fout<<i<<" ";
    return fout;
}
template<typename T>
ostream& operator<<(ostream& fout,const ordered_set<T>&v) {
    for(T i:v)
        fout<<i<<" ";
    return fout;
}
ll rdn(int y, int m, int d) {
    /* Rata Die day one is 0001-01-01 */
    if (m < 3)
        y--, m += 12;
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}
/* Direction arrays */
/*int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};                         */// 4 Direction
/*int dx[] = {1,-1,0,0,1,1,-1,-1}, dy[] = {0,0,1,-1,1,-1,1,-1};        */// 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */            // Hexagonal Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */            // Hexagonal Direction
/* int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; */
const int N1=1e4+9;
bool _check(int n,int pos)
{
	return (n & (1<<pos));
}
int _set(int n,int pos)
{
	return n=n|(1<<pos);
}
/*no of prime in range
1e9=50847534
1e8=5761455
1e7=664579
1e6=78498
1e5=9592*/
const int N=1e6;
int isprime[N/32+2];
int prime[78498 + 3];
int prmsz;
void seive()
{
    prmsz=0;
	prime[prmsz++]=2;
	for(int i=3;i*i<=N;i+=2)
	{
		if(!_check(isprime[i/32],i%32))
		for(int j=i*i;j<=N;j+=i+i)
		{
			isprime[j/32]=_set(isprime[j/32],j%32);
		}
	}
	for(int i=3;i<=N;i+=2)
	{
		if(!_check(isprime[i/32],i%32))
			prime[prmsz++]=i;
	}
	return;
}

bool check_prime(int x) {
    if(x<2)
        return 0;
    if(x==2)
        return 1;
    if(x%2==0)
        return 0;
    return !_check(isprime[x/32],x%32);
}
int ara[N1];
int treex[N1*4];
int lazy[N1*4];
int lazy_val[N1*4];
void build(int node,int st,int en){
    lazy[node]=lazy_val[node]=0;
    if(st==en){
        treex[node]=check_prime(ara[st]);
        return;
    }
    int lt=node*2;
    int rg=lt+1;
    int mid=(st+en)/2;
    build(lt,st,mid);
    build(rg,mid+1,en);
    treex[node]=treex[lt]+treex[rg];
}
inline void push_down(int node,int st,int en){
    treex[node]=(en-st+1)*lazy_val[node];
    if(st!=en){
        int lt = node * 2;
        int rg = lt + 1;
        lazy[lt]=lazy[rg]=1;
        lazy_val[lt]=lazy_val[rg]=lazy_val[node];
    }
    lazy[node]=lazy_val[node]=0;
}
void update(int node,int st,int en,int l,int r,int val){
    if(lazy[node])push_down(node,st,en);
    if(st>=l && en<=r){
        lazy[node]=1;
        lazy_val[node]=val;
        push_down(node,st,en);
        return;
    }
    if(r<st || l>en)return;
    int lt = node * 2;
    int rg = lt + 1;
    int mid = (st + en) / 2;
    update(lt,st,mid,l,r,val);
    update(rg,mid+1,en,l,r,val);
    treex[node]=treex[lt]+treex[rg];
}
int SQuery(int node,int st,int en,int l,int r){
    if(lazy[node])push_down(node,st,en);
    if (st >= l && en <= r)
    {
        return treex[node];
    }
    if (r < st || l > en)
        return 0;
    int lt = node * 2;
    int rg = lt + 1;
    int mid = (st + en) / 2;
    int s1=SQuery(lt,st,mid,l,r);
    int s2=SQuery(rg,mid+1,en,l,r);
    return s1+s2;
}
int main() {
    seive();
    QUERY{
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++){
            scanf("%d",&ara[i]);
        }
        int a,b,c,d;
        build(1,1,n);
        printf("Case %d:\n",_T);
        while (q--)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(a==1){
                printf("%d\n",SQuery(1,1,n,b,c));
            }else{
                scanf("%d",&d);
                d=check_prime(d);
                update(1,1,n,b,c,d);
            }
        }
        
    }
}
