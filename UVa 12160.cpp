#include<bits/stdc++.h>
using namespace std;
int visited[10009];
vector<int>keys;
void clean(){
    memset(visited,-1,sizeof visited);
    keys.clear();
}
void bfs(int a,int b){
    queue<int>q;
    q.push(a);
    visited[a]=0;
    while(q.size()){
        int t=q.front();
        q.pop();
        if(t==b)
            break;
        for(int i=0;i<keys.size();i++){
            int p=(t+keys[i])%(9999+1);
            if(visited[p]==-1){
                q.push(p);
                visited[p]=visited[t]+1;
            }
        }
    }
}
int main()
{
    int a,b,c,cas=1;
    while(scanf("%d %d %d",&a,&b,&c)==3 and a+b+c>0){
        int x;
        printf("Case %d: ",cas++);
        clean();
        for(int i=0;i<c;i++){
            scanf("%d",&x);
            keys.emplace_back(x);
        }
        bfs(a,b);
        if(visited[b]==-1)
            printf("Permanently Locked\n");
        else
            printf("%d\n",visited[b]);
    }
}
