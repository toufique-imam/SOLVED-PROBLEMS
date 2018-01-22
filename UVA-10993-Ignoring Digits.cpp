/*
ID:sabertooth
TASK:MULTII
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool v[20];
bool dicv[100009];
string path[100009];
queue< pair<int,string> >q;

void rset()
{
    for(int i=0; i<1009; i++)
        path[i].clear();
    memset(dicv,0,sizeof(dicv));
    memset(v,0,sizeof(v));
    while(q.empty()==0)
        q.pop();
}

void init(int N)
{
    int d,r;
    for(int i=1; i<10; i++)
    {
        if(v[i])
        {
            d=i/N;
            r=i%N;
            if(dicv[r]==0)
            {
                dicv[r]=1;
                if(d)
                    path[r].push_back(d+'0');
                q.push(make_pair(r,path[r]));
            }
        }
    }
}

bool bfs(int N)
{
    init(N);
    pair<int,string>p;
    int t;
    string t_str;
    while(!q.empty())
    {
        p=q.front();
        q.pop();

        t=p.first;
        t_str=p.second;

        for(int i=0; i<10; i++)
        {
            if(v[i])
            {
                int x=t*10+i;
                string temp(t_str);

                int r=x%N;
                int d=x/N;

                if(dicv[r]==0)
                {
                    dicv[r]=1;
                    if(!(temp.size()==0 && d==0))
                        temp.push_back(d+'0');
                    path[r]=temp;
                    q.push(make_pair(r,path[r]));
                }
            }
        }
        if(dicv[0])
            return 1;
    }
    return 0;
}

string mul(string s,int n)
{
    int sum,carry=0;
    string ans;
    int i,l=s.length();
    for(i=l-1; i>-1; i--)
    {
        sum=(s[i]-'0')*n+carry;
        ans+=(sum%10 + '0');
        carry=sum/10;
    }
    while(carry)
    {
        ans+=(carry%10 + '0');
        carry/=10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


int main ()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    string m;
    while(cin>>m>>n && n && m[0]!='0')
    {
        rset();
        int i,x;
        for(i=0; i<m.length(); i++)
        {
            v[m[i]-'0']=1;
        }
        if(bfs(n))
        {
            cout<<mul(path[0],n);
        }
        else
            printf("impossible");
        printf("\n");
    }
    return 0;
}
