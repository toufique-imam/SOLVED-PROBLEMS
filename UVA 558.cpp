#include<bits/stdc++.h>
using namespace std;
#define     pii     pair<int,int>
#define     pll     pair<long long,long long>
#define     ff      first
#define     sc      second
const long long arrsize=1000;

class edge
{
public:

    long long att;
    long long weight;
    edge(long long a,long long b)
    {
        att=a;
        weight=b;
    }
    edge() {};
};
int visited[arrsize+9];
long long dist[arrsize+9];
vector<edge>roads[arrsize+9];
long long path[arrsize+9];

void clean()
{
    memset(visited,0,sizeof(visited));
    fill(dist,dist+arrsize+9,1e14);
    for(long long i=0; i<=arrsize; i++)
        roads[i].clear();
    memset(path,-1,sizeof(path));
}

int main()
{
    int test;
    scanf("%d",&test);
    for(int t=1; t<=test; t++)
    {
        clean();
        int n,m,a,b,c;
        scanf("%d %d",&n,&m);
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            roads[a].push_back(edge(b,c));
        }
        bool f=0;
        dist[0]=0;
        for(int i=0; i<n-1; i++)
            for(int j=0; j<n; j++)
                for(int k=0; k<roads[j].size(); k++)
                {
                    edge x=roads[j][k];
                    if(dist[x.att]>dist[j]+x.weight)
                    {
                        dist[x.att]=dist[j]+x.weight;
                    }
                }
        //long long start=-1,endd=-1;
        for(int i=0; i<n ; i++)
        {
            for(int j=0; j<roads[i].size(); j++)
            {
                edge x=roads[i][j];
                if(dist[x.att]>dist[i]+x.weight)
                {
                    f=1;
                    break;
                }
            }
        }
        if(f)
            printf("possible\n");
        else
            printf("not possible\n");
    }
}
