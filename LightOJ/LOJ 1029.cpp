#include<bits/stdc++.h>
using namespace std;
class DSU {
public:
    int n;
    int par[109];

    DSU() {};

    DSU(int k) {
        n = k;
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
    }

    int ROOT(int x) {
        while (x != par[x]) {
            par[x] = par[par[x]];
            x = par[x];
        }
        return x;
    }

    void UNION(int x, int y) {
        par[x] = par[y];
    }
};
class NODE2 {
public:
    int a, b;

    NODE2() {};

    NODE2(int a, int b) {
        this->a = a;
        this->b = b;
    }

    bool operator<(const NODE2 &x) {
        return this->b > x.b;
    }
};
class NODE3 {
public:
    int a, b, c;

    NODE3() {};

    NODE3(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    friend bool comp1(const NODE3 X, const NODE3 Y);

    friend bool comp2(const NODE3 X, const NODE3 Y);
};
bool comp1(const NODE3 X, const NODE3 Y) {
    return X.c > Y.c;
}
bool comp2(const NODE3 X, const NODE3 Y) {
    return X.c < Y.c;
}
vector<NODE3> vx;
vector<NODE2> vp[1009];
bool visited[1009];
void clear(){
    vx.clear();
    for(int i=0;i<1009;i++){
        vp[i].clear();
    }
}
void MST(int n, bool mark) {
    DSU g(n);
    if (mark)
        sort(vx.begin(), vx.end(), comp1);
    else
        sort(vx.begin(), vx.end(), comp2);
    for (int i = 0; i < vx.size(); i++) {
        NODE3 t = vx[i];
        int tx = g.ROOT(t.a);
        int ty = g.ROOT(t.b);
        if (tx != ty) {
            g.UNION(tx, ty);
            vp[t.a].push_back(NODE2(t.b, t.c));
            vp[t.b].push_back(NODE2(t.a, t.c));
        }
    }
}
int BFS(){
    memset(visited,0,sizeof visited);
    int cnt=0;
    visited[0]=1;
    queue<NODE2>q;
    q.push(NODE2(0,0));
    while(q.size()){
        NODE2 t=q.front();
        q.pop();
        for(int i=0;i<vp[t.a].size();i++){
            NODE2 px=vp[t.a][i];
            if(visited[px.a]==0){
                visited[px.a]=1;
                q.push(px);
                cnt+=px.b;
            }
        }
    }
    return cnt;
}
int main() {
    int test;
    scanf("%d",&test);
    for(int T=1;T<=test;T++){
        clear();
        int n,a,b,c;
        scanf("%d",&n);
        while(scanf("%d %d %d",&a,&b,&c)==3 and a+b+c>0){
            vx.push_back(NODE3(a,b,c));
        }
        MST(n,0);
        int ans=0;
        ans=BFS();
        for(int i=0;i<1009;i++)
            vp[i].clear();
        MST(n,1);
        ans+=BFS();
        printf("Case %d: ",T);
        if(ans%2)
            printf("%d/2\n",ans);
        else
            printf("%d\n",ans/2);

    }
}
