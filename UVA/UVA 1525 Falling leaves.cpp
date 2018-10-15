
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define eps             1e-9
#define inf             0x3f3f3f3f
#define INF             2e18
#define PI              acos(-1.0)
#define ff              first
#define ss              second
#define all(v)          v.begin(),v.end()
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(min(a,b),min(c,d))
#define max4(a,b,c,d)   max(max(a,b),max(c,d))
#define max5(a,b,c,d,e) max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e) min(min3(a,b,c),min(d,e))
#define Iterator(a)     __typeof__(a.begin())
#define read            freopen("in.txt","r",stdin);
#define write           freopen("out.txt","w",stdout);
#define TEST            int test;scanf("%d",&test);for(int T=1;T<=test;T++)
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define reunique(v)     v.resize(std::unique(all(v)) - v.begin())
#define MP              make_pair
#define PB              push_back
#define EB              emplace_back
#define segtree         int mid=(st+en)/2,lt=node*2,rg=node*2+1
#define MERGE(v1,v2,v)  merge(all(v1),all(v2),back_inserter(v))
#define loop(a)         for(__typeof__(a.begin())itr=a.begin();itr!=a.end();itr++)
#define log2_(x)        __builtin_clz(1) - __builtin_clz(x);

//n! ~ sqrt(2*pi*n)*n^n*e^-n

class data
{
public:

    char key;
    data *left,*right;
    data()
    {
        left=right=NULL;
        key=0;
    }
};
void del(data *cur)
{
    if(cur!=NULL)
    {
        if(cur->left!=NULL)
            del(cur->left);
        if(cur->right!=NULL)
            del(cur->right);
        delete cur;
        cur=NULL;
    }
}
data* insert_(data *cur,char x)
{
    if(cur==NULL)
    {
        cur=new data();
        cur->key=x;
        return cur;
    }
    if(cur->key>x)
        cur->left=insert_(cur->left,x);
    else
        cur->right=insert_(cur->right,x);
    return cur;
}
void show(data *cur)
{
    printf("%c",cur->key);
    if(cur->left!=NULL)show(cur->left);
    if(cur->right!=NULL)show(cur->right);
}
int main()
{
    vector<string>v;
    string s;
    bool f=0;
    while(1)
    {
        if(f)break;
        v.clear();
        cin>>s;
        if(s[0]=='$'|| s[0]=='*')
            break;
        else
        {
            data *root=NULL;
            v.PB(s);
            while(1)
            {
                cin>>s;
                if(s[0]=='*')
                    break;
                if(s[0]=='$'){
                    f=1;
                    break;
                }
                v.PB(s);
            }
            int sz=v.size();
            for(int i=sz-1; i>=0; i--)
            {
                for(int j=0; j<v[i].size(); j++)
                {
                    if(i==sz-1 and j==0)root=insert_(root,v[i][j]);
                    else
                        insert_(root,v[i][j]);
                }
            }
            show(root);
            puts("");
            del(root);
            if(f)break;
        }
    }
}
