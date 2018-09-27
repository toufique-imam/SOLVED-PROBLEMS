#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<string>v;
int ax[]= {1,1,2,2,-1,-1,-2,-2};
int ay[]= {2,-2,1,-1,2,-2,1,-1};
int grid[109][11][11];
bool cango(int x,int y)
{
    return x<n and y<m and x>-1 and y>-1;
}
void bfs(int no,int x,int y)
{
    queue<int>q;
    q.push(x);
    q.push(y);
    grid[no][x][y]=0;
    while(q.size())
    {
        int tx=q.front();
        q.pop();
        int ty=q.front();
        q.pop();
        for(int i=0; i<8; i++)
        {
            int px=tx+ax[i];
            int py=ty+ay[i];
            if(cango(px,py) and grid[no][px][py]==-1)
            {
                q.push(px);
                q.push(py);
                grid[no][px][py]=grid[no][tx][ty]+1;
            }
        }
    }
    return;
}

void process_power(int no,int power)
{
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(grid[no][i][j]!=-1)
                grid[no][i][j]=ceil(grid[no][i][j]*1.0/power*1.0);
    return;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    for(int _t=1;_t<=test;_t++)
    {
        memset(grid,-1,sizeof grid);
        v.clear();
        cin>>n>>m;
        string s;
        for(int i=0; i<n; i++)
        {
            cin>>s;
            v.push_back(s);
        }
        int no=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(v[i][j]>='0' and v[i][j]<='9')
                {
                    bfs(no,i,j);
                    process_power(no,v[i][j]-'0');
                    no++;
                }
            }
        bool f=0,f1;
        int temp,ans=1000000000;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                f1=1;
                temp=0;
                for(int k=0; k<no; k++)
                {
                    if(grid[k][i][j]==-1)
                    {
                        f1=0;
                        break;
                    }
                    temp+=grid[k][i][j];
                }
                if(f1)
                {
                    ans=min(ans,temp);
                    f=1;
                }
            }
        }
        cout<<"Case "<<_t<<": ";
        if(f)
            cout<<ans<<endl;
        else
            cout<<"-1"<<endl;
    }
}

