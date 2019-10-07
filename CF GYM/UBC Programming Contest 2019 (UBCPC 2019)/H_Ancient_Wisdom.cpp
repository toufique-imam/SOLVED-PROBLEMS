#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using dijkstra = priority_queue<T, vector<T>, greater<T>>;
 
typedef long long ll;
#define fbo find_by_order // k th index
#define ook order_of_key // strictly smaller than k
#define pll pair<ll,ll>
#define ff first
#define ss second
#define FAST ios_base::sync_with_stdio(0), cin.tie(0)
#define all(v) v.begin(), v.end()
#define reunique(v) v.resize(std::unique(all(v)) - v.begin())
#define MERGE(v1, v2, v) merge(all(v1), all(v2), back_inserter(v))
#define MP make_pair
#define EB emplace_back
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
#define in_range(v, r, l) upper_bound(all(v), r) - lower_bound(all(v), l)
#define LCM(a, b) (a / __gcd(a, b)) * b;
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
typedef unsigned long long ull;
bool issquare(ull x){
    ull lo=1,hi=5000000000;
    ull mid,xx;
    while(lo<=hi){
        mid=(lo+hi)/2;
        xx=mid*mid;
        if(xx<x){
            lo=mid+1;
        }
        else if(xx>x){
            hi=mid-1;
        }
        else{
            return 1;
        }
    }
    return 0;
}
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
const int N=1e7;
int isprime[N/32+2];
ll prime[664579+3];
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
int main(){
    seive();
    ll n;
    cin>>n;
    ll ans=1;
    int cnt=0;
    for(int i=0;i<prmsz && prime[i]*prime[i]<=n;i++){
        if(n%prime[i]==0){
            cnt=0;
            while (n%prime[i]==0)
            {
                n/=prime[i];
                cnt++;
            }
            if(cnt&1){
                ans*=prime[i];
            }
        }
    }
    ll m=sqrt(n);
    if(m*m!=n){
        ans*=n;
    }
    cout<<ans<<endl;
}