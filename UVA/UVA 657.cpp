#include<bits/stdc++.h>
using namespace std;

vector<string>data;
int ax[]= {1,-1,0,0};
int ay[]= {0,0,1,-1};
int visited[60][60];

bool valid(int x,int y,int n,int m)
{
    return (x>-1 && y>-1 && x<n && y<m);
}

void dfs(int x,int y,int n,int m,char main,char change)
{
    if(visited[x][y] || data[x][y]!=main)
        return;
    data[x][y]=change;
    for(int i=0; i<4; i++)
        if(valid(x+ax[i],y+ay[i],n,m))
            dfs(ax[i]+x,ay[i]+y,n,m,main,change);
    return;
}

int bfs(int x,int y,int n,int m)
{
    queue<int>q;
    q.push(x);
    q.push(y);
    visited[x][y]=1;
    int cnt=0;
    while(q.size())
    {
        int tx=q.front();
        q.pop();
        int ty=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int px=tx+ax[i];
            int py=ty+ay[i];
            if(valid(px,py,n,m) && visited[px][py]==0 && data[px][py]!='.')
            {
                if(data[px][py]=='*')
                {
                    visited[px][py]=1;
                    q.push(px);
                    q.push(py);
                }
                else if(data[px][py]=='X')
                {
                    dfs(px,py,n,m,'X','*');
                    cnt++;
                    q.push(px);
                    q.push(py);
                    visited[px][py]=1;
                }
            }
        }
    }
    return cnt;
}

int main()
{
    int n,m,cas=1;
    while(cin>>n>>m && n && m)
    {
        memset(visited,0,sizeof(visited));
        data.clear();
        string s;
        for(int i=0; i<m; i++)
        {
            cin>>s;
            data.push_back(s);
        }
        vector<int>ans;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(data[i][j]=='*' && visited[i][j]==0)
                {
                    int x=bfs(i,j,m,n);
                    if(x)
                        ans.push_back(x);
                }
            }
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(data[i][j]=='X' && visited[i][j]==0)
                {
                    dfs(i,j,m,n,'X','*');
                    ans.push_back(1);
                }
            }
        sort(ans.begin(),ans.end());
        printf("Throw %d\n",cas++);
        for(int i=0; i<ans.size(); i++)
        {
            printf("%d",ans[i]);
            if(i!=ans.size()-1)
                printf(" ");
        }
        printf("\n\n");
    }
}
