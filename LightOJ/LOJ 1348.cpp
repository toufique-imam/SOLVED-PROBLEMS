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
typedef long long ll;

#define SEGTREE int lt = node * 2, rg = node * 2 + 1, mid = (st + en) / 2
const int N = 30009;
int color[N];
vector<int> v[N];
int sparse_table[N][16];
int tim;
int dfs_low[N];
int level[N];
int dfs_high[N];
int tree_[9 * N];
int lazy[9 * N];
void dfs(int x = 0, int par = 0)
{
    dfs_low[x] = ++tim;
    for (int i = 0; i < (int)v[x].size(); i++)
    {
        int gg = v[x][i];
        if (gg != par && sparse_table[gg][0] == -1)
        {
            level[gg] = level[x] + 1;
            sparse_table[gg][0] = x;
            dfs(gg, x);
        }
    }
    dfs_high[x] = ++tim;
}
void create_sparse(int n)
{
    tim = 0;
    level[0] = 0;
    dfs();
    for (int j = 1; (1 << j) < n; j++)
        for (int i = 0; i < n; i++)
            if (sparse_table[i][j - 1] != -1)
                sparse_table[i][j] = sparse_table[sparse_table[i][j - 1]][j - 1];
}
int find_lca(int v1, int v2)
{
    if (level[v1] < level[v2]) //Bigger level in V1
        swap(v1, v2);
    int lg = 1;
    int nxt = lg + 1;
    while ((1 << nxt) <= level[v1])
    { //highest depth for 2^i
        lg++;
        nxt = lg + 1;
    }
    for (int i = lg; i > -1; i--)
        if (level[v1] - (1 << i) >= level[v2])
            v1 = sparse_table[v1][i];
    if (v1 == v2)
        return v1;
    for (int i = lg; i >= 0; i--)
        if (sparse_table[v1][i] != -1 and sparse_table[v1][i] != sparse_table[v2][i])
            v1 = sparse_table[v1][i], v2 = sparse_table[v2][i];
    return sparse_table[v1][0];
}
inline void push_down(int node, int st, int en)
{
    SEGTREE;
    tree_[lt] += (mid - st + 1) * lazy[node];
    tree_[rg] += (en - mid) * lazy[node];
    if (st != en)
    {
        lazy[lt] += lazy[node];
        lazy[rg] += lazy[node];
    }
    lazy[node] = 0;
}
void update(int node, int st, int en, int l, int r, int val)
{
    if (lazy[node])
        push_down(node, st, en);
    if (st >= l && en <= r)
    {
        tree_[node] += (en - st + 1) * val;
        if (st != en)
            lazy[node] += val;
        return;
    }
    if (st > r || en < l)
        return;
    SEGTREE;
    update(lt, st, mid, l, r, val);
    update(rg, mid + 1, en, l, r, val);
    tree_[node] = tree_[lt] + tree_[rg];
}
int query(int node, int st, int en, int l, int r)
{
    if (lazy[node])
        push_down(node, st, en);
    if (st >= l && en <= r)
        return tree_[node];
    if (st > r || en < l)
        return 0;
    SEGTREE;
    return query(lt, st, mid, l, r) + query(rg, mid + 1, en, l, r);
}
int main()
{
    int test;
    scanf("%d", &test);
    for (int _T = 1; _T <= test; _T++)
    {
        int n;
        memset(tree_, 0, sizeof tree_);
        memset(lazy, 0, sizeof lazy);
        memset(sparse_table, -1, sizeof sparse_table);
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &color[i]);
            v[i].clear();
        }
        int a, b;
        for (int i = 1; i < n; i++)
        {
            scanf("%d %d", &a, &b);
            v[a].emplace_back(b);
            v[b].emplace_back(a);
        }
        create_sparse(n);
        for (int i = 0; i < n; i++)
            update(1, 1, tim, dfs_low[i], dfs_high[i] - 1, color[i]);
        int q;
        scanf("%d", &q);
        int c;
        printf("Case %d:\n", _T);
        while (q--)
        {
            scanf("%d%d%d", &a, &b, &c);
            if (a)
            {
                update(1, 1, tim, dfs_low[b], dfs_high[b] - 1, -1 * color[b]);
                color[b] = c;
                update(1, 1, tim, dfs_low[b], dfs_high[b] - 1, c);
            }
            else
            {
                int x = find_lca(b, c);
                int q1 = query(1, 1, tim, dfs_low[b], dfs_low[b]);
                int q2 = query(1, 1, tim, dfs_low[c], dfs_low[c]);
                int q3 = query(1, 1, tim, dfs_low[x], dfs_low[x]);
                int y = sparse_table[x][0];
                int q4 = 0;
                if (y != -1)
                    q4 = query(1, 1, tim, dfs_low[y], dfs_low[y]);
                printf("%d\n", q1 + q2 - q3 - q4);
            }
        }
    }
}
