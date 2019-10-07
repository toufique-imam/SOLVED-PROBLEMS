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
#define LCM(a, b) (a / __gcd(a, b)) * b;
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
struct fighter
{
    string name;
    int HP,AT,DF;
    fighter(){
        name="";
        HP=AT=DF=0;
    }
    int canbeat(fighter &x){
        int ats=max(0,AT-x.DF);
        int ato=max(0,x.AT-DF);
        if(ats==ato){
            if(ats==0)return 0;
            if(HP==x.HP)return 0;
            else{
                if(HP>x.HP)return 1;
                return -1;
            }
        }
        else if(ats==0){
            return -1;
        }
        else if(ato==0){
            return 1;
        }
        else{
            int ts=x.HP/ats+(x.HP%ats?1:0);
            int to=HP/ato+(HP%ato?1:0);
            if(ts==to)return 0;
            else if(ts>to)return -1;
            return 1;
        }
    }
    void print(){
        cout<<name<<" "<<HP<<" "<<AT<<" "<<DF<<"\n";
    }
};
fighter ara[109];
set< vector<int> >v;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>ara[i].name>>ara[i].HP>>ara[i].AT>>ara[i].DF;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)continue;
            for(int k=0;k<n;k++){
                    if(k==i || k==j)continue;
                    if(ara[i].canbeat(ara[j])==1 && ara[j].canbeat(ara[k])==1 && ara[k].canbeat(ara[i])==1){
                        vector<int>tmp;
                        tmp.EB(i);
                        tmp.EB(j);
                        tmp.EB(k);
                        sort(all(tmp));
                        v.insert(tmp);
                    }
            }
        }
    }
    printf("%d\n",v.size());
    for(vector<int>vv:v){
        cout<<ara[vv[0]].name<<" "<<ara[vv[1]].name<<" "<<ara[vv[2]].name<<endl;
    }
}