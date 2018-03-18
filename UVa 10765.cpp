#include<bits/stdc++.h>
using namespace std;


bool cmp(const pair<int, int> A, const pair<int, int> B) {
	if(A.second > B.second)
		return true;
	if(A.second == B.second && A.first < B.first)
		return true;
	return false;
}
vector<int>v[10001];
int child[10001];
int dis[10001];
int low[10001];
int tim;
void clean()
{
    for(int i=0; i<10001; i++)
    {
        v[i].clear();
    }
    memset(dis,0,sizeof dis);
    memset(low,0,sizeof low);
    tim=0;
}

void dfs(int x,int pa)
{
    dis[x]=low[x]=++tim;
    child[x]=1;
    for(int i=0; i<v[x].size(); i++)
    {
        int y=v[x][i];
        if(y==pa)continue;
        if(dis[y])
            low[x]=min(low[x],dis[y]);
        else
        {
            dfs(y,x);
            low[x]=min(low[x],low[y]);
            if(low[y]>=dis[x])
                child[x]++;
        }
    }
}

void solve(int n,int k)
{
    dfs(0,0);
    child[0]--;
    vector< pair<int,int> >ans;
    ans.clear();
    for(int i=0; i<n; i++)
        ans.push_back(make_pair(i,child[i]));
    sort(ans.begin(),ans.end(),cmp);
    for(int i=0; i<k; i++)
        printf("%d %d\n",ans[i].first,ans[i].second);
    printf("\n");
}

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)==2 and (n or m))
    {
        int a,b;
        clean();
        while(scanf("%d %d",&a,&b)==2 and (a!=-1 and b!=-1))
        {
            v[a].push_back(b);
            v[b].push_back(a);
        }
        solve(n,m);
    }
}
