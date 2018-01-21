/*
ID:sabertooth9
TASK:SPOJ-INVESORT
LANG: C++14
*/
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
#define write freopen("output.txt","w",stdout)
 
string prim="abcdefghij";
unordered_map<string,int>mp;
 
void bfs()
{
    queue<string>q;
    mp[prim]=0;
    q.push(prim);
    string temp,curr;
    int i,j,d;
    while(!q.empty())
    {
        temp=q.front();
        curr=temp;
        d=mp[curr];
        q.pop();
        for(i=0; i<10; i++)
        {
            temp=curr;
            for(j=i+1; j<10; j++)
            {
                temp=curr;
                reverse(temp.begin()+i,temp.begin()+j+1);
                if(mp[temp]==0 && temp!=prim)
                {
                    mp[temp]=d+1;
                    q.push(temp);
                }
            }
        }
    }
}
 
int main ()
{
    bfs();
    char s1[20],s2[20];
    while(scanf("%s %s",&s1,&s2)==2)
    {
        if(s1[0]=='*')
            break;
        char s[11];
        char dd='a';
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(s1[i]==s2[j])
                {
                    s[j]=dd++;
                }
            }
        }
        s[10]='\0';
        printf("%d\n",mp[s]);
    }
}
