#include<bits/stdc++.h>
using namespace std;
#define  pii    pair<int,int>
#define  ff     first
#define  sc     second
const long long arrsize=10000;
vector< pair<long long,long long> >nor[arrsize+9];
vector< pair<long long,long long> >rev[arrsize+9];
vector<long long>dist1(arrsize+9,1e9);
vector<long long>dist2(arrsize+9,1e9);
vector< pair<long long,pair<long long,long long> > >v;


void clean()
{
    for(int i=0;i<=arrsize;i++)
    {
        nor[i].clear();
        rev[i].clear();
        dist1[i]=1e9;
        dist2[i]=1e9;
    }
    v.clear();
}
void DijkstraA(long long source,long long limit)
{
    priority_queue<long long>pq;
    pq.push(-1*source);
    dist1[source]=0;
    while(pq.size())
    {
        long long t=pq.top();
        pq.pop();
        t*=-1;
        for(int i=0; i<nor[t].size(); i++)
        {
            int x=nor[t][i].ff;
            if(dist1[x]>dist1[t]+nor[t][i].sc && dist1[t]+nor[t][i].sc<=limit)
            {
                dist1[x]=dist1[t]+nor[t][i].sc;
                pq.push(-1*x);
            }
        }
    }
}

void DijkstraB(long long source,long long limit)
{
    priority_queue<long long>pq;
    pq.push(-1*source);
    dist2[source]=0;
    while(pq.size())
    {
        long long t=pq.top();
        pq.pop();
        t*=-1;
        for(int i=0; i<rev[t].size(); i++)
        {
            int x=rev[t][i].ff;
            if(dist2[x]>dist2[t]+rev[t][i].sc && dist2[t]+rev[t][i].sc<=limit)
            {
                dist2[x]=dist2[t]+rev[t][i].sc;
                pq.push(-1*x);
            }
        }
    }
}

int main()
{
    int test;
    scanf("%d",&test);
    for(int t=1; t<=test; t++)
    {
        clean();
        long long n,m,s,T,limit,a,b,c;
        scanf("%lld %lld %lld %lld %lld",&n,&m,&s,&T,&limit);
        for(int i=0; i<m; i++)
        {
            scanf("%lld %lld %lld",&a,&b,&c);
            nor[a].push_back(make_pair(b,c));
            rev[b].push_back(make_pair(a,c));
            v.push_back( make_pair(a,make_pair(b,c)));
        }
        DijkstraA(s,limit);
        DijkstraB(T,limit);
        long long ans=-1;
        for(int i=0;i<v.size();i++)
        {
            if(dist1[v[i].ff]+dist2[v[i].sc.ff]+v[i].sc.sc<=limit)
                ans=max(ans,v[i].sc.sc);
        }
        printf("Case %d: %lld\n",t,ans);
    }
}
