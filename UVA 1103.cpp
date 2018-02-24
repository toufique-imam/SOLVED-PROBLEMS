#include<bits/stdc++.h>

using namespace std;

int ax[] = {1, -1, 0, 0};
int ay[] = {0, 0, 1, -1};
int grid[1009][1009];
int visited[1009][1009];

void clean()
{
    memset(visited,0,sizeof(visited));
    memset(grid,-1,sizeof(grid));
}

bool valid(int x, int y, int n, int m)
{
    return (x > -1 && y > -1 && x < n && y < m);
}

int hex_bin(int x,int row,int col)
{
    int start=col+3;
    while(start>=col)
    {
        grid[row][start]=x%2;
        x/=2;
        start--;
    }
    return col+4;
}
//49-54
void process(string s,int row)
{
    int col=0;
    for(int i=0; i<s.length(); i++)
    {
        int x=s[i]-'0';
        if(x>=0 && x<=9)
        {
            col=hex_bin(x,row,col);
        }
        else
        {
            x-=39;
            col=hex_bin(x,row,col);
        }
    }
    return;
}

void bfs__(int x, int y,int colour,int n,int m)
{
    visited[x][y]=1;
    queue<int>q;
    q.push(x);
    q.push(y);
    while(q.size())
    {
        int tx=q.front();
        q.pop();
        int ty=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int px=ax[i]+tx;
            int py=ay[i]+ty;
            if(valid(px,py,n,m) && visited[px][py]==0 && grid[px][py]==colour)
            {
                visited[px][py]=1;
                q.push(px);
                q.push(py);
            }
        }
    }
    return;
}

int bfs(int x,int y,int n,int m,int colour)
{
    queue<int>q;
    int cnt=0;
    q.push(x);
    q.push(y);
    visited[x][y]=1;
    while(q.size())
    {
        int tx=q.front();
        q.pop();
        int ty=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int px=ax[i]+tx;
            int py=ay[i]+ty;
            if(valid(px,py,n,m) && visited[px][py]==0)
            {
                if(grid[px][py]==colour)
                {
                    q.push(px);
                    q.push(py);
                    visited[px][py]=1;
                }
                else
                {
                    cnt++;
                    bfs__(px,py,grid[px][py],n,m);
                }
            }
        }
    }
    return cnt;
}

void show(int n,int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<4*m; j++)
            cout<<grid[i][j];
        cout<<endl;
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int cas=1,n,m;
    while(scanf("%d %d",&n,&m)==2 && n && m)
    {
        clean();
        getchar();
        string s;
        for(int i=0; i<n; i++)
        {
            cin>>s;
            //cout<<s<<endl;
            process(s,i);
        }
        //show(n,m);
        for(int i=0; i<n; i++)
        {
            if(grid[i][0]==0 && visited[i][0]==0)
            {
                bfs__(i,0,0,n,4*m);
            }
            if(grid[i][4*m-1]==0 && visited[i][4*m-1]==0)
            {
                bfs__(i,4*m-1,0,n,4*m);
            }
        }
        for(int i=0;i<4*m;i++)
        {
            if(grid[0][i]==0 && visited[0][i]==0)
            {
                bfs__(0,i,0,n,4*m);
            }
            if(grid[n-1][i]==0 && visited[n-1][i]==0)
            {
                bfs__(n-1,i,0,n,4*m);
            }
        }
        string ans;
        int temp;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<4*m; j++)
            {
                if(grid[i][j]==1 && visited[i][j]==0)
                {
                    temp=bfs(i,j,n,4*m,1);
                    if(temp==1)
                    {
                        ans.push_back('A');
                    }
                    else if(temp==2)
                    {
                        ans.push_back('K');
                    }
                    else if(temp==3)
                    {
                        ans.push_back('J');
                    }
                    else if(temp==4)
                    {
                        ans.push_back('S');
                    }
                    else if(temp==5)
                    {
                        ans.push_back('D');
                    }
                    else if(temp==0)
                    {
                        ans.push_back('W');
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        printf("Case %d: ",cas++);
        cout<<ans<<endl;
    }
}
