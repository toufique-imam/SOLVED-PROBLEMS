#include<bits/stdc++.h>
using namespace std;
#define  pii    pair<int,int>
#define  ff     first
#define  sc     second

struct node
{
    pii a;
    pii b;
    pii c;
};

int visited[12][12][12][12][12][12];
int level[12][12][12][12][12][12];

int grid[12][12];
map<pii,int>mp;
node p;

int ax[] = {1, -1, 0, 0};
int ay[] = {0, 0, 1, -1};

bool valid(int x, int y, int n, int m) {
    return (x > -1 && y > -1 && x < n && y < m && grid[x][y]!=1);
}

void clean()
{
    mp.clear();
    memset(visited,-1,sizeof(visited));
    memset(level,0,sizeof(level));
    memset(grid,0,sizeof(grid));
}
void process(string s,int col)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='#')
            grid[col][i]=1;
        if(s[i]=='X')
            mp[make_pair(col,i)]=1;
        if(s[i]=='A')
            p.a=(make_pair(col,i));
        if(s[i]=='B')
            p.b=(make_pair(col,i));
        if(s[i]=='C')
            p.c=(make_pair(col,i));
    }
}

int bfs(int n,int m)
{
    queue<pii>q;
    q.push(p.a);
    q.push(p.b);
    q.push(p.c);
    visited[p.a.ff][p.a.sc][p.b.ff][p.b.sc][p.c.ff][p.c.sc]=1;
    level[p.a.ff][p.a.sc][p.b.ff][p.b.sc][p.c.ff][p.c.sc]=0;
    while(q.size())
    {
        node x,temp;
        x.a=q.front();
        q.pop();
        x.b=q.front();
        q.pop();
        x.c=q.front();
        q.pop();
        if(mp[x.a] && mp[x.b] && mp[x.c] && x.a!=x.b && x.a!=x.b && x.c!=x.a && x.b!=x.c)
        {
            return  level[x.a.ff][x.a.sc][x.b.ff][x.b.sc][x.c.ff][x.c.sc];
        }
        for(int i=0;i<4;i++)
        {
            temp.a={x.a.ff+ax[i],x.a.sc+ay[i]};
            temp.b={x.b.ff+ax[i],x.b.sc+ay[i]};
            temp.c={x.c.ff+ax[i],x.c.sc+ay[i]};
            if(!valid(temp.a.ff,temp.a.sc,n,m))
            {
                temp.a=x.a;
            }
            if(!valid(temp.b.ff,temp.b.sc,n,m))
            {
                temp.b=x.b;
            }
            if(!valid(temp.c.ff,temp.c.sc,n,m))
            {
                temp.c=x.c;
            }
            if(temp.a==temp.b)
            {
                if(temp.c==temp.b)
                {
                    temp.c=x.c;
                }
                temp.a=x.a;
                temp.b=x.b;
            }
            if(temp.b==temp.c)
            {
                if(temp.a==temp.c)
                    temp.a=x.a;
                temp.b=x.b;
                temp.c=x.c;
            }
            if(temp.a==temp.c)
            {
                temp.a=x.a;
                temp.c=x.c;
            }
            if(visited[temp.a.ff][temp.a.sc][temp.b.ff][temp.b.sc][temp.c.ff][temp.c.sc]==-1)
            {
                visited[temp.a.ff][temp.a.sc][temp.b.ff][temp.b.sc][temp.c.ff][temp.c.sc]=1;
                level[temp.a.ff][temp.a.sc][temp.b.ff][temp.b.sc][temp.c.ff][temp.c.sc]=level[x.a.ff][x.a.sc][x.b.ff][x.b.sc][x.c.ff][x.c.sc]+1;
                q.push(temp.a);
                q.push(temp.b);
                q.push(temp.c);
            }
        }
    }
    return -1;
}


int main()
{
    int test;
    scanf("%d",&test);
    getchar();
    for(int t=1;t<=test;t++)
    {
        clean();
        int n;
        scanf("%d",&n);
        getchar();
        string s;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            process(s,i);
        }
        int ans=bfs(n,n);
        printf("Case %d: ",t);
        if(ans==-1)
        {
            printf("trapped\n");
        }
        else
        {
            printf("%d\n",ans);
        }
    }
}
