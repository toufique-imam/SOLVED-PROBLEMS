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
#define pii pair<int,int>
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
#define SEGMENT_TREE int mid=(st+en)/2,lt=node*2,rg=lt+1
#define LCM(a, b) (a / __gcd(a, b)) * b;
#define PI acos(-1.0)
#define inf 1e9
const int N=1e5+9;
ll ara[N];
ll sumtree[4*N];
ll minitr[4*N];
int alive[4*N];
ll lazy[4*N];
inline void merge_(int node){
    int lt=node*2,rg=node*2+1;
    minitr[node]=min(minitr[lt],minitr[rg]);
    sumtree[node]=sumtree[lt]+sumtree[rg];
    alive[node]=alive[lt]+alive[rg];
}
inline void push_down(int node,int st,int en){
    sumtree[node]-=alive[node]*lazy[node];
    minitr[node]-=lazy[node];
    if(st!=en){
        int lt=node*2,rg=node*2+1;
        lazy[lt]+=lazy[node];
        lazy[rg]+=lazy[node];
    }
    lazy[node]=0;
}
void build(int node,int st,int en){
    if(st==en){
        sumtree[node]=ara[st];
        alive[node]=1;
        lazy[node]=0;
        minitr[node]=ara[st];
        return;
    }
    SEGMENT_TREE;
    build(lt,st,mid);
    build(rg,mid+1,en);
    merge_(node);
}
void update_kill(int node,int st,int en,int l,int r,ll s){
    if(lazy[node]>0)push_down(node,st,en);
    if(st>r || en<l)return;
    if(alive[node]==0)return;
    if(minitr[node]>s)return;
    if(st==en){
        minitr[node]=1e9;
        alive[node]=0;
        sumtree[node]=0;
        lazy[node]=0;
        return;
    }
    SEGMENT_TREE;
    update_kill(lt,st,mid,l,r,s);
    update_kill(rg,mid+1,en,l,r,s);
    merge_(node);
}
void update_sum(int node,int st,int en,int l,int r,ll s){
    if(lazy[node]>0)push_down(node,st,en);
    if(st>r || en<l)return;
    if(alive[node]==0)return;
    if(st>=l && en<=r){
        lazy[node]+=s;
        push_down(node,st,en);
        return;
    }
    SEGMENT_TREE;
    update_sum(lt,st,mid,l,r,s);
    update_sum(rg,mid+1,en,l,r,s);
    merge_(node);
}
ll query(int node,int st,int en,int l,int r){
    if(lazy[node])push_down(node,st,en);
    if(st>r || en<l)return 0;
    if(alive[node]==0)return 0;
    if(st>=l && en<=r)return sumtree[node];
    SEGMENT_TREE;
    ll q1=query(lt,st,mid,l,r);
    ll q2=query(rg,mid+1,en,l,r);
    return q1+q2;
}
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%lld",&ara[i]);
    }
    build(1,1,n);
    ll type,l,r,s,ans;
    while (q--)
    {
        scanf("%lld",&type);
        if(type==1){
            scanf("%lld %lld",&l,&r);
            ans=0;
            if(r<l){
                ans=query(1,1,n,l,n);
                l=1;
            }
            ans+=query(1,1,n,l,r);
            printf("%lld\n",ans);
        }
        else{
            scanf("%lld %lld %lld",&l,&r,&s);
            if(r<l){
                update_kill(1,1,n,l,n,s);
                update_kill(1,1,n,1,r,s);
                update_sum(1,1,n,l,n,s);
                update_sum(1,1,n,1,r,s);
            }
            else{
                update_kill(1,1,n,l,r,s);
                update_sum(1,1,n,l,r,s);
            }
        }
    }
    
}