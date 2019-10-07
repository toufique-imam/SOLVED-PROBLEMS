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

int main(){
    int n;
    cin>>n;
    if(n<3){
        cout<<"! 1"<<endl;
        return 0;
    }
    set<int>ss;
    for(int i=3;i<=n;i++){
        ss.insert(i);
    }
    bool f=1;
    int par=1,mid=2;

    while(f){
        f=0;
        vector<int>v;
        for(int i:ss){
            cout<<"? "<<par<<" "<<mid<<" "<<i<<endl;
            cin>>f;
            v.EB(i);
            if(f){
                par=mid;
                mid=i;
                break;
            }
        }
        for(int i:v)ss.erase(i);
    }
    cout<<"! "<<mid<<endl;
    return 0;
}