#include<bits/stdc++.h>

using namespace std;
struct node
{
    int v,w;
    node() {};
    node(int a,int b)
    {
        v=a;
        w=b;
    }
    bool operator < (const node &y) const
    {
        return this->w > y.w;
    }
};
vector<node>v[109];
int source,tim;
int visited[109];
void clean()
{
    memset(visited,63,sizeof visited);
    for(int i=0; i<109; i++)
    {
        v[i].clear();
    }
}
int dijkastra()
{
    int cnt=0;
    visited[source]=0;
    priority_queue<node>pq;
    pq.push(node(source,0));
    while(!pq.empty())
    {
        node t=pq.top();
        pq.pop();
        for(int i=0; i<v[t.v].size(); i++)
        {
            node p=v[t.v][i];
            if(visited[p.v]>visited[t.v]+p.w)
            {
                visited[p.v]=visited[t.v]+p.w;
                pq.push(node(p.v,visited[p.v]));
                if(visited[p.v]<=tim)
                    cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    int test;
    scanf("%d",&test);
    bool f=0;
    while(test--)
    {
        if(f)
            printf("\n");
        clean();
        int n;
        scanf("%d %d %d",&n,&source,&tim);
        int m;
        scanf("%d",&m);
        for(int i=0; i<m; i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            v[b].push_back(node(a,c));
        }
        printf("%d\n",dijkastra()+1);
        f=1;
    }
}

