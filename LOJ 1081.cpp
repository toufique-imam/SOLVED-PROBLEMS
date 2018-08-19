/*
ID: sabertooth
LANG: C++11
TASK:
*/
#include<bits/stdc++.h>
//#include <unordered_map>
//#include <unordered_set>
using namespace std;
typedef long long ll;

#define ff first
#define ss second
#define gcd(x,y) abs(__gcd(x,y))
#define all(v) v.begin(),v.end()
#define read freopen("in.txt","r",stdin);
#define write freopen("out.txt","w",stdout);
#define TEST int test;scanf("%d",&test);for(int T=1;T<=test;T++)
//2D RMQ
//sparse_table N*logN*M*logM
const int N=503;
unsigned int table[N][N][10];
int n,m;
void create_sparse()
{
    for(int k=1; (1<<k)<=m; k++)
        for(int i=0; i+(1<<k)-1<n; i++)
            for(int j=0; j+(1<<k)-1<m; j++)
            {
                table[i][j][k]=max(table[i][j][k-1],max(table[i][j+(1<<(k-1))][k-1],max(table[i+(1<<(k-1))][j][k-1],table[i+(1<<(k-1))][j+(1<<(k-1))][k-1])));
            }
}
unsigned int query(int i,int j,int S)
{
    int p=log2(S);
    assert((j+S-(1<<p))>-1 and (j+S-(1<<p))<n);
    assert((i+S-(1<<p))>-1 and (i+S-(1<<p))<n);
    return max(table[i][j][p],max(table[i][j+S-(1<<p)][p],max(table[i+S-(1<<p)][j][p],table[i+S-(1<<p)][j+S-(1<<p)][p])));
}
int main()
{
    TEST
    {
        memset(table,0,sizeof table);
        int q;
        int pos;
        scanf("%d %d",&n,&q);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%u",&table[i][j][0]);
            }
        }
        m=n;
        create_sparse();
        printf("Case %d:\n",T);
        int I,J,S,p;
        while(q--)
        {
            scanf("%d %d %d",&I,&J,&S);
            I--;
            J--;
            printf("%u\n",query(I,J,S));
        }
    }
}
