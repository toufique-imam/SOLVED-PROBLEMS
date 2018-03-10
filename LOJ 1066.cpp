#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//vector<string>v;
class edge
{
public:
    int x,y;
    edge(int a,int b)
    {
        x=a;
        y=b;
    }
    edge(){};
};
int ax[]= {0,0,-1,1};
int ay[]= {1,-1,0,0};
edge IsHere[30];
int level[30][30];
int grid[30][30];
int n;

int bfs(edge t1,edge t2,int endd)
{
    memset(level,-1,sizeof(level));
    queue<int>q;
    q.push(t1.x);
    q.push(t1.y);
    level[t1.x][t1.y]=0;
    while(q.size())
    {
        int tx=q.front();
        q.pop();
        int ty=q.front();
        q.pop();
        if(tx==t2.x and ty==t2.y){
            grid[t1.x][t1.y]=-1;
            grid[t2.x][t2.y]=-1;
            return level[tx][ty];
        }
        for(int i=0; i<4; i++)
        {
            int px=tx+ax[i];
            int py=ty+ay[i];
            if(px<n && py<n && px>-1 && py>-1 && (grid[px][py]==-1 or grid[px][py]==endd) and level[px][py]==-1)
            {
                level[px][py]=level[tx][ty]+1;
                q.push(px);
                q.push(py);
            }
        }
    }
    return -1;
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    for(int _t=1; _t<=test; _t++)
    {
        memset(grid,-1,sizeof grid);
        //memset(IsHere,0,sizeof IsHere);
        cin>>n;
        string s;
        int k=0;
        for(int i=0; i<n; i++)
        {
            cin>>s;
            for(int j=0; j<n; j++)
            {
                if(isalpha(s[j]))
                {
                    IsHere[s[j]-'A']={i,j};
                    grid[i][j]=s[j]-'A'+1;
                    k++;
                }
                else if(s[j]=='#')
                {
                    grid[i][j]=0;
                }
            }
        }
        int cnt=0;
        bool f=1;
        for(int i=0; i<k-1; i++)
        {
            int x=bfs(IsHere[i],IsHere[i+1],grid[IsHere[i+1].x][IsHere[i+1].y]);
            if(x==-1)
            {
                f=0;
                break;
            }
            else
            {
                cnt+=x;
            }
        }
        cout<<"Case "<<_t<<": ";
        if(f)
            cout<<cnt<<endl;
        else
            cout<<"Impossible"<<endl;
    }
}

