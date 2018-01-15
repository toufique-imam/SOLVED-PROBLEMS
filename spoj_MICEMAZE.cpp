#include<bits/stdc++.h>
using namespace std;
#define ll              long long
#define pb              push_back
#define read()         freopen("input.txt","r",stdin)
#define write()        freopen("output.txt","w",stdout)
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define mod             1000000007
#define all(v)          v.begin(),v.end()


vector< vector<pair<int,int>> >v;


int main ()
{
    int n,s,t,m,a,b,d;
    scanf("%d %d %d %d",&n,&s,&t,&m);
    int i,j;
    v=vector< vector<pair<int,int>> >(n+9);
    for(i=0; i<m; i++)
    {
        scanf("%d %d %d",&a,&b,&d);
        v[b].push_back(make_pair(a,d));
    }
    //which distance to s ==t will survive
    //which distance to s>t will not survive;
    priority_queue<int>pq;
    vector<int>dis(n+3,1000000);
    dis[s]=0;
    pq.push(s);
    while(pq.empty()==0)
    {
        int t1=pq.top();
        pq.pop();
        for(i=0; i<v[t1].size(); i++)
        {
            if(dis[t1]+v[t1][i].second<dis[v[t1][i].first])
            {
                dis[v[t1][i].first]=dis[t1]+v[t1][i].second;
                pq.push(v[t1][i].first);
            }
        }
    }
    int cnt=0;
    for(i=1; i<=n; i++)
    {
        //printf("%d %d\n",i,dis[i]);
        if(dis[i]<=t)
            cnt++;
    }
    printf("%d\n",cnt);

}
