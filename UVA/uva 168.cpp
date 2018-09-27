#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int>edges[300];
int step;
bool light[300];

void clean()
{
    for(int i=0; i<300; i++)
        edges[i].clear();
    step=0;
    memset(light,0,sizeof(light));
}

int dfs(int child,int par,int k)
{
    light[child]=!(++step%k);
    bool f=0;
    for(int i=0; i<edges[child].size(); i++)
    {
        int x=edges[child][i];
        if(light[x]==0 && x!=par)
        {
            if(light[child])
                printf("%c ",char(child));
            return dfs(x,child,k);
        }
    }
    printf("/%c\n",char(child));
}

int main()
{
    string s;
    while(getline(cin,s))
    {
        clean();
        if(s=="#")
            break;
        int i,j,source;
        int x,y,z;
        bool f=0;
        for(i=0; i<s.length(); i++)
        {
            if(s[i]=='.')
                break;
            if(s[i]==';')
            {
                f=0;
                continue;
            }
            if(s[i]==':')
                continue;
            if(f==0)
            {
                source=s[i];
                f=1;
                continue;
            }
            if(f)
            {
                edges[source].push_back(s[i]);
            }
        }
        i++;
        while(s[i]==' ') i++;
        x=s[i++];
        while(s[i]==' ') i++;
        y=s[i++];
        while(s[i]==' ') i++;
        z=0;
        while(i<s.size())
            z=z*10+(s[i++]-'0');
        dfs(x,y,z);
    }
}
