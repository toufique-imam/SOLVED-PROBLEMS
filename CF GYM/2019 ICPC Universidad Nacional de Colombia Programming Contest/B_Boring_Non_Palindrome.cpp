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
const int N=1e6+9;
string t,p;
int b[N];
void kmpPreprocess() {
    int m=p.size();
    int i=0,j=-1;
    b[0]=-1;
    while(i<m) {
        if(j==-1 || p[i]==p[j])
            b[++i]=++j;
        else
            j=b[j];
    }
}
void debugkmp() {
    for(int i=0; i<p.size(); i++)
        cerr<<b[i]<<" ";
    cerr<<endl;
}
int kmpSearch() {
    int i=0,j=0;
    int m=p.size();
    int n=t.size();
    while(i<n) {
        if(j==-1 || t[i]==p[j]) {
            i++;
            j++;
        } else
            j=b[j];
        //if j==m match found
    }
    //cerr<<2*m-j<<endl;
    return j;
}
int main(){
    cin>>p;
    t=p;
    reverse(all(t));
    swap(t,p);
    kmpPreprocess();
    int len=p.size();
    int x=kmpSearch();
    string ans=t,qq;
    int total_=len-x,j=len-1;
    while (total_--)
    {
        qq+=p[j];
        j--;
    }
    reverse(all(qq));
    ans+=qq;
    cout<<ans<<"\n";
}