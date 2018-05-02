/*
ID: sabertooth9
LANG: C++11
TASK: milk3
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool visited[22][22][22];
int ara[3];
void dfs(int state[])
{
    int newstate[4];
    visited[state[0]][state[1]][state[2]]=1;
    for(int i=0;i<3;i++)
    {
        int pos0=i;
        int pos1=(i+1)%3;
        int pos2=(i+2)%3;
        if(state[pos0])
        {
            int need1=ara[pos1]-state[pos1];
            int need2=ara[pos2]-state[pos2];
            if(state[pos0]>=need1)
            {
                newstate[pos0]=state[pos0]-need1;
                newstate[pos1]=ara[pos1];
                newstate[pos2]=state[pos2];
                if(!visited[newstate[0]][newstate[1]][newstate[2]])dfs(newstate);
            }
            else
            {
                newstate[pos0]=0;
                newstate[pos1]=state[pos1]+state[pos0];
                newstate[pos2]=state[pos2];
                if(!visited[newstate[0]][newstate[1]][newstate[2]])dfs(newstate);
            }
            if(state[i]>=need2)
            {
                newstate[pos2]=ara[pos2];
                newstate[pos1]=state[pos1];
                newstate[pos0]=state[pos0]-need2;
                if(!visited[newstate[0]][newstate[1]][newstate[2]])dfs(newstate);
            }
            else
            {
                newstate[pos0]=0;
                newstate[pos1]=state[pos1];
                newstate[pos2]=state[pos2]+state[pos0];
                if(!visited[newstate[0]][newstate[1]][newstate[2]])dfs(newstate);
            }
        }
    }
}
int main()
{
    freopen("milk3.in","r",stdin);
    freopen("milk3.out","w",stdout);
    for(int i=0;i<3;i++)scanf("%d",ara+i);
    int state[4]={0,0,ara[2]};
    dfs(state);
    bool f=0;
    for(int i=0;i<=ara[2];i++)
        for(int j=0;j<=ara[1];j++)
            if(visited[0][j][i])
            {
                if(f)printf(" ");
                printf("%d",i);
                f=1;
            }
    printf("\n");
}
