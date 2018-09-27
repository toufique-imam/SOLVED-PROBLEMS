#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int grid[109][109];
int GiveDirection(char prev,char now,char &ans)
{
    if(now=='F')
    {
        ans=prev;
        if(prev=='N')
        {
            return -1;
        }
        else if(prev=='S')
        {
            return 1;
        }
        else if(prev=='E')
        {
            return 2;
        }
        else if(prev=='W')
        {
            return -2;
        }
    }
    else
    {
        if(prev=='N')
        {
            if(now=='L')
                ans='W';
            else
                ans='E';
        }
        else if(prev=='S')
        {
            if(now=='L')
                ans='E';
            else
                ans='W';
        }
        else if(prev=='E')
        {
            if(now=='L')
                ans='N';
            else
                ans='S';
        }
        else
        {
            if(now=='L')
                ans='S';
            else
                ans='N';
        }
        return 0;
    }
}

bool valid(int x,int y,int n,int m)
{
    if(x>-1 && x<=n && y>-1 && y<=m)
        return 1;
    return 0;
}

int main()
{
    memset(grid,0,sizeof(grid));
    int n,m;
    cin>>n>>m;
    int x1,x2,px1,px2;
    char now;
    string s;
    while(cin>>x1>>x2>>now>>s)
    {
        int x;
        bool f=0;
        for(int i=0; i<s.length(); i++)
        {
            x=GiveDirection(now,s[i],now);
            if(x!=0)
            {
                if(x==2)
                {
                    if(valid(x1+1,x2,n,m))
                        x1+=1;
                    else if(grid[x1][x2]==0)
                    {
                        grid[x1][x2]=1;
                        f=1;
                        break;
                    }
                }
                else if(x==-2)
                {
                    if(valid(x1-1,x2,n,m))
                        x1-=1;
                    else if(grid[x1][x2]==0)
                    {
                        grid[x1][x2]=1;
                        f=1;
                        break;
                    }
                }
                else if(x==1)
                {
                    if(valid(x1,x2-1,n,m))
                        x2-=1;
                    else if(grid[x1][x2]==0)
                    {
                        grid[x1][x2]=1;
                        f=1;
                        break;
                    }
                }
                else
                {
                    if(valid(x1,x2+1,n,m))
                        x2+=1;
                    else if(grid[x1][x2]==0)
                    {
                        grid[x1][x2]=1;
                        f=1;
                        break;
                    }
                }
            }
        }
        cout<<x1<<" "<<x2<<" "<<now<<( f ? " LOST" :"")<<endl;
    }
}
