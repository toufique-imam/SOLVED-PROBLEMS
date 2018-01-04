#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define read(s)     freopen(#s,"r",stdin)
#define write(s)    freopen(#s,"w",stdout)
#define N           1000

ll knight[10][10];
ll m1[]= {1,-1,-2,-2,-1,1,2,2};
ll m2[]= {-2,-2,-1,1,2,2,1,-1};

bool check(ll a,ll b,ll r,ll c)
{
    if(a>0 && a<r && b>0 && b<c && knight[a][b]==0)
        return 1;
    return 0;
}

ll bfs(ll r1,ll c1,ll r2,ll c2,ll r,ll c)
{
    queue<ll>q;
    ll t1,t2,x,i,j,k,y;
    q.push(r1);
    q.push(c1);
    while(q.empty()==0)
    {
        t1=q.front();
        q.pop();
        t2=q.front();
        q.pop();
        if(t1==r2 && t2==c2)
            return knight[t1][t2];
        for(i=0; i<8; i++)
        {
            x=t1+m1[i];
            y=t2+m2[i];
            if(check(x,y,r,c))
            {
                q.push(x);
                q.push(y);
                knight[x][y]=knight[t1][t2]+1;
            }
        }
    }
}

int main()
{
    string a1,b;
    while(cin>>a1>>b)
    {
        memset(knight,0,sizeof(knight));
        ll r1=a1[0]-'a'+1,c1=a1[1]-'0';
        ll r2=b[0]-'a'+1,c2=b[1]-'0';
        cout<<"To get from "<<a1<<" to "<<b<<" takes "<<bfs(r1,c1,r2,c2,9,9)<<" knight moves."<<endl;
    }
}
