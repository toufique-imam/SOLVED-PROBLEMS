#include<bits/stdc++.h>
using namespace std;

int par[10009];
int low[10009];
int dis[10009];
vector<int>v[10009];
vector< pair<int,int> >dfstree;
int tim;
int child;
void dfs(int pa,int x,int root)
{
    dis[x]=low[x]=++tim;
    par[x]=pa;
    for(int i=0; i<v[x].size(); i++)
    {
        int p=v[x][i];
        if(par[p]==-1)
        {
            dfstree.push_back(make_pair(x,p));
            dfs(x,p,root);
            if(x==root)
                child++;
            low[x]=min(low[x],low[p]);
        }
        else if(par[p]!=-1 and p!=par[x])
            low[x]=min(low[x],dis[p]);
    }
}

void clean()
{
    for(int i=0; i<10009; i++)
        v[i].clear();
    memset(par,-1,sizeof par);
    memset(low, -1, sizeof low);
    memset(dis,-1,sizeof dis);
    dfstree.clear();
}
bool comp(pair<int,int>p1,pair<int,int>p2)
{
    if(p1.first<p2.first)
        return 1;
    else if(p1.first==p2.first and p1.second < p2.second)
        return 1;
    return 0;
}
int main()
{
   // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    for(int _t=1; _t<=test; _t++)
    {
        int n;
        cin>>n;
        clean();
        string s;
        for(int i=0; i<n; i++)
        {
            int a;
            cin>>a>>s;
            int s1=0;
            for(int j=1; j<s.length()-1; j++)
                s1=s1*10+s[j]-'0';
            for(int k=0; k<s1; k++)
            {
                int b;
                cin>>b;
                v[a].push_back(b);
                v[b].push_back(a);
            }
        }
        tim=0;
        child=0;
        for(int i=0; i<n; i++)
        {
            if(par[i]==-1)
            {
                dfs(i,i,i);
            }
        }
        int cnt=0;
        vector< pair<int,int> >ans;
        for(int i=0; i<dfstree.size(); i++)
        {
            if(dis[dfstree[i].first] < low[dfstree[i].second])
            {
                ans.push_back(make_pair(min(dfstree[i].first,dfstree[i].second),max(dfstree[i].first,dfstree[i].second)));
                cnt++;
            }
        }
        cout<<"Case "<<_t<<":"<<endl;
        sort(ans.begin(),ans.end(),comp);
        if(cnt)
        {
            cout<<cnt<<" critical links"<<endl;
            for(int i=0; i<ans.size(); i++)
                cout<<ans[i].first<<" - "<<ans[i].second<<endl;
        }
        else
            cout<<cnt<<" critical links"<<endl;
        //cout<<endl;
    }
}
