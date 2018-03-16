#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<string,int>intmap;
vector<int>v[109];
int indegree[109];
int outdegree[109];
map<int,string>stringmap;
bool visited[109];
vector<int>ans;
void clean(){
    for(int i=0;i<109;i++){
        v[i].clear();
    }
    intmap.clear();
    stringmap.clear();
    memset(indegree,0,sizeof indegree);
    memset(outdegree,0 ,sizeof outdegree);
    memset(visited,0,sizeof visited);
    ans.clear();
}

void topsort(int n){
    priority_queue<int, vector<int>, greater<int> > q;
    for(int i=1;i<n;i++){
        if(indegree[i]==0){
           visited[i]=1;
           q.push(i);
        }
    }
    while(q.size()){
        int t=q.top();
        q.pop();
        ans.push_back(t);
        for(auto i=0;i<v[t].size();i++){
            if(visited[v[t][i]]==0){
                indegree[v[t][i]]--;
                if(indegree[v[t][i]]==0){
                    q.push(v[t][i]);
                    visited[v[t][i]]=1;
                }
            }
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    int _t=1;
    //freopen("output.txt","w",stdout);
    while(cin>>n and n){
        clean();
        string s,s1;
        int val=1;
        for(int i=0;i<n;i++){
            cin>>s;
            if(intmap[s]==0){
                intmap[s]=val;
                stringmap[val]=s;
                val++;
            }
        }
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>s>>s1;
            v[intmap[s]].push_back(intmap[s1]);
            indegree[intmap[s1]]++;
            outdegree[intmap[s]]++;
        }
        topsort(val);
        cout<<"Case #"<<_t<<": Dilbert should drink beverages in this order: ";
        for(auto i=0;i<ans.size();i++){
            cout<<stringmap[ans[i]];
            if(i!=ans.size()-1)
                cout<<" ";
            else
                cout<<".";
        }
        cout<<endl<<endl;
        _t++;
    }

}
