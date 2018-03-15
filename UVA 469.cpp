#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string>v;
int row,col;
int a[2];
int ax[]= {0,1,1,1,0,-1,-1,-1};
int ay[]= {1,1,0,-1,-1,-1,0,1};
bool cango(int x,int y)
{
    return x>-1 and y>-1 and x<row and y<col;
}

bool visited[1000][1000];
int solve()
{
    memset(visited,0,sizeof visited);
    int cnt=1;
    queue<int>q;
    q.push(a[0]-1);
    q.push(a[1]-1);
    visited[a[0]-1][a[1]-1]=1;
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
            if(cango(px,py) and !visited[px][py] and v[px][py]=='W')
            {
                visited[px][py]=1;
                q.push(px);
                q.push(py);
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int test;
    scanf("%d",&test);
    getchar();
    getchar();
    string s;
    for(int i=0; i<test; i++)
    {
        row=0;
        v.clear();
        while(getline(cin,s))
        {
            if(s[0]=='\0')
            {
                cout<<endl;
                break;
            }
            if(isdigit(s[0]))
            {
                int x=0;
                stringstream ss(s);
                while(ss>>a[x++]) {}
                cout<<solve()<<endl;
            }
            else
            {
                row++;
                col=s.size();
                v.push_back(s);
            }
        }
    }
}
