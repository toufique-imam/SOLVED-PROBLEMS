#include <bits/stdc++.h>
using namespace std;
#define QUERY int test;scanf("%d", &test);for (int _T = 1; _T <= test; _T++)
const double pi = acos (-1.0);
const double eps = 1e-8;
typedef double T;
struct pt {
    T x, y;
    pt () {}
    pt (T _x, T _y) : x(_x), y(_y) {}
    pt operator + (const pt& p) const {
        return pt (x + p.x, y + p.y);
    }
    pt operator - (const pt& p) const {
        return pt (x - p.x, y - p.y);
    }
    pt operator * (const T& d) const {
        return pt (x * d, y * d);
    }
    pt operator / (const T& d) const {
        return pt (x / d, y / d);
    }
    bool operator == (const pt& p) const {
        return (x == p.x and y == p.y);
    }
    bool operator != (const pt& p) const {
        return !(x == p.x and y == p.y);
    }
    bool operator < (const pt& p) const {
        if (x != p.x)
            return x < p.x;
        return y < p.y;
    }
    int input() {
        return scanf("%lf %lf",&x,&y);
    }
};

T dot (pt v, pt w) {
    return v.x * w.x + v.y * w.y;
}
T cross (pt v, pt w) {
    return v.x * w.y - v.y * w.x;
}

T orient (pt a, pt b, pt c) {
    return cross (b - a, c - a);
}

//Segment
bool inDisk (pt a, pt b, pt p) {
    return dot (a - p, b - p) <= 0;
}

bool onSegment (pt a, pt b, pt p) {
    return orient (a, b, p) == 0 and inDisk (a, b, p);
}

bool properInter (pt a, pt b, pt c, pt d, pt& i) {
    double oa = orient (c, d, a),
           ob = orient (c, d, b),
           oc = orient (a, b, c),
           od = orient (a, b, d);

    //Proper intersection exists iff opposite signs
    if (oa * ob < 0 and oc * od < 0) {
        i = (a * ob - b * oa) / (ob - oa);
        return true;
    }
    return false;
}

bool inters (pt a, pt b, pt c, pt d) {
    pt out;
    //vector<pt>ans;
    if (properInter (a, b, c, d, out))
        return true;
    if (onSegment (c, d, a))
        return true;
    //ans.push_back(a);
    if (onSegment (c, d, b))
        return true;
    //ans.push_back(b);
    if (onSegment (a, b, c))
        return true;
    //ans.push_back(c);
    if (onSegment (a, b, d))
        return true;
    //ans.push_back(d);
    return false;
}
const int N=1009;
int par[N];
int hight[N];
int find_(int x) {
    while(x!=par[x]) {
        par[x]=par[par[x]];
        x=par[x];
    }
    return x;
}
void UNION(int x,int y) {
    x=find_(x);
    y=find_(y);
    if(x!=y) {
        if(hight[x]<hight[y])
            swap(x,y);
        par[y]=x;
        hight[x]+=hight[y];
    }
}
void reset(int n) {
    for(int i=0; i<=n; i++) {
        par[i]=i;
        hight[i]=1;
    }
}
pair<pt,pt>ara[N];
int main() {
    QUERY{
        int n,m;
        scanf("%d %d",&n,&m);
        reset(n);
        for(int i=0; i<n; i++) {
            ara[i].first.input();
            ara[i].second.input();
        }
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(inters(ara[i].first,ara[i].second,ara[j].first,ara[j].second))
                    UNION(i,j);
            }
        }
        int x,y;
        while(m--) {
            scanf("%d %d",&x,&y);
            x--;
            y--;
            x=find_(x);
            y=find_(y);
            if(x==y)
                puts("YES");
            else
                puts("NO");
        }
    }
}

