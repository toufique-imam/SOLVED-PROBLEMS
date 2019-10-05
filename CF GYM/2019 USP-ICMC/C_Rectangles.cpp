#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ff first
#define ss second
#define pll pair<ll,ll>
#define MP make_pair
#define all(v) v.begin(),v.end()
#define in_range(v, r, l) upper_bound(all(v), r) - lower_bound(all(v), l)
#define reunique(v) v.resize(std::unique(all(v)) - v.begin())
const int N = 4009;
vector<ll>vx[N];
vector<ll>vy[N];
vector< pair<ll, ll> >v;
vector<ll>tmp;
map<ll, int>mp;
set< pair<pll, pll> >s;
ll grid[N][N];
ll find_prev(vector<ll>&vv, ll x) {
    int lo = 0, hi = vv.size() - 1;
    int mid;
    ll ans = -1;
    while(lo <= hi) {
        mid = (lo + hi) / 2;
        if(vv[mid] < x) {
            ans = mid;
            lo = mid + 1;
        } else
            hi = mid - 1;
    }
    return ans;
}
bool bhitore_kew_asen(ll x1, ll y1, ll x2, ll y2) {
    if(x1 > x2)
        swap(x1, x2);
    if(y1 > y2)
        swap(y1, y2);
    int ans=0;
    for(pll i : v) {
        if(i.ff >= x1 && i.ff <= x2 && i.ss >= y1 && i.ss <= y2)
            ans++;
    }
    return ans!=4;
}
ll find_next(vector<ll>&vv, ll x) {
    int lo = 0, hi = vv.size() - 1;
    int mid;
    ll ans = -1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if(vv[mid] > x) {
            ans = mid;
            hi = mid - 1;
        } else
            lo = mid + 1;
    }
    return ans;

}
bool find_(vector<ll>&vv, ll x) {
    int lo = 0, hi = vv.size() - 1;
    int mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if(vv[mid] == x) {
            return 1;
        }
        if(vv[mid] < x) {
            lo = mid + 1;
        } else
            hi = mid - 1;
    }
    return 0;

}
void case_4(ll x, ll y) {
    ll idy1 = find_next(vx[mp[x]], y);
    if(idy1 == -1)
        return;
    ll y1 = vx[mp[x]][idy1];

    ll idx1 = find_next(vy[mp[y1]], x);
    if(idx1 == -1)
        return;
    ll x1 = vy[mp[y1]][idx1];

    if(!find_(vx[mp[x1]], y))
        return;

    int cnt = in_range(vx[mp[x1]], y1, y);
    if(cnt != 2)
        return;
    cnt = in_range(vy[mp[y]], x1, x);
    if(cnt != 2)
        return;
    cnt = in_range(vy[mp[y1]], x1, x);
    if(cnt != 2)
        return;
    cnt = in_range(vx[mp[x]], y1, y);
    if(cnt != 2)
        return;

    pll xx = MP(min(x, x1), min(y, y1));
    pll yy = MP(max(x, x1), max(y, y1));
    if(xx == yy)
        return;
    if(!bhitore_kew_asen(x, y, x1, y1))
        s.insert(MP(xx, yy));
}
void case_3(ll x, ll y) {
    ll idy1 = find_next(vx[mp[x]], y);
    if(idy1 == -1)
        return;
    ll y1 = vx[mp[x]][idy1];

    ll idx1 = find_prev(vy[mp[y1]], x);
    if(idx1 == -1)
        return;
    ll x1 = vy[mp[y1]][idx1];

    if(!find_(vx[mp[x1]], y))
        return;

    int cnt = in_range(vx[mp[x1]], y1, y);
    if(cnt != 2)
        return;
    cnt = in_range(vy[mp[y]], x1, x);
    if(cnt != 2)
        return;
    cnt = in_range(vx[mp[x]], y1, y);
    if(cnt != 2)
        return;
    cnt = in_range(vy[mp[y1]], x1, x);
    if(cnt != 2)
        return;

    pll xx = MP(min(x, x1), min(y, y1));
    pll yy = MP(max(x, x1), max(y, y1));
    if(xx == yy)
        return;
    if(!bhitore_kew_asen(x, y, x1, y1))
        s.insert(MP(xx, yy));
    return;
}
void case_1(ll x, ll y) {
    ll idy1 = find_prev(vx[mp[x]], y);
    if(idy1 == -1)
        return;
    ll y1 = vx[mp[x]][idy1];

    ll idx1 = find_next(vy[mp[y1]], x);
    if(idx1 == -1)
        return;
    ll x1 = vy[mp[y1]][idx1];

    if(!find_(vx[mp[x1]], y))
        return;

    int cnt = in_range(vx[mp[x1]], y, y1);
    if(cnt != 2)
        return;
    cnt = in_range(vx[mp[x]], y, y1);
    if(cnt != 2)
        return;
    cnt = in_range(vy[mp[y]], x1, x);
    if(cnt != 2)
        return;
    cnt = in_range(vy[mp[y1]], x1, x);
    if(cnt != 2)
        return;

    pll xx = MP(min(x, x1), min(y, y1));
    pll yy = MP(max(x, x1), max(y, y1));
    if(xx == yy)
        return;
    if(!bhitore_kew_asen(x, y, x1, y1))
        s.insert(MP(xx, yy));
    return;
}
void case_2(ll x, ll y) {
    ll idy1 = find_prev(vx[mp[x]], y);
    if(idy1 == -1)
        return;
    ll y1 = vx[mp[x]][idy1];

    ll idx1 = find_prev(vy[mp[y1]], x);
    if(idx1 == -1)
        return;
    ll x1 = vy[mp[y1]][idx1];

    if(!find_(vx[mp[x1]], y))
        return;
    int cnt = in_range(vx[mp[x1]], y, y1);
    if(cnt != 2)
        return;
    cnt = in_range(vx[mp[x]], y, y1);
    if(cnt != 2)
        return;
    cnt = in_range(vy[mp[y]], x, x1);
    if(cnt != 2)
        return;
    cnt = in_range(vy[mp[y1]], x, x1);
    if(cnt != 2)
        return;

    pll xx = MP(min(x, x1), min(y, y1));
    pll yy = MP(max(x, x1), max(y, y1));
    if(xx == yy)
        return;
    if(!bhitore_kew_asen(x, y, x1, y1))
        s.insert(MP(xx, yy));
    return;
}
int main() {
    int n;
    scanf("%d", &n);
    ll x, y;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &x, &y);
        tmp.emplace_back(x);
        tmp.emplace_back(y);
        v.emplace_back(make_pair(x, y));
    }
    sort(all(tmp));
    for(ll i : tmp) {
        if(mp.find(i) == mp.end()) {
            mp[i] = ++cnt;
        }
    }
    sort(all(v));
    for(int i = 0; i < n; i++) {
        vx[mp[v[i].ff]].emplace_back(v[i].ss);
        vy[mp[v[i].ss]].emplace_back(v[i].ff);
    }
    ll prev = -1;
    for(ll i : tmp) {
        if(i != prev) {
            sort(all(vx[mp[i]]));
            reunique(vx[mp[i]]);
            sort(all(vy[mp[i]]));
            reunique(vy[mp[i]]);
        }
        prev = i;
    }
    for(int i = 0; i < n; i++) {
        x = v[i].ff;
        y = v[i].ss;
        case_1(x, y);
        case_2(x, y);
        case_3(x, y);
        case_4(x, y);
    }
    printf("%d\n", s.size());
}
