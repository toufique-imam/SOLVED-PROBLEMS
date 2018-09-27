#include<bits/stdc++.h>

using namespace std;
int visited[3000];
vector<int> v[3000];
int cnt[3000];
void clean() {
    for (int i = 0; i < 3000; i++) {
        v[i].clear();
    }
}

int nx, mx;

void bfs(int source) {
    memset(visited, -1, sizeof visited);
    memset(cnt,0,sizeof cnt);
    queue<int> q;
    q.push(source);
    visited[source] = 0;
    while (!q.empty()) {
        //int cnt = 0;
        int t = q.front();
        q.pop();
        for (int i = 0; i < v[t].size(); i++) {
            int p = v[t][i];
            if (visited[p] == -1) {
                visited[p] = visited[t] + 1;
                q.push(p);
                cnt[visited[t]]++;
            }
        }
        if(nx<cnt[visited[t]]){
            nx=cnt[visited[t]];
            mx=visited[t];
        }
    }
}

int main() {
    int n;
    while (scanf("%d", &n) == 1 and n) {
        clean();
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            for (int j = 0; j < x; j++) {
                int a;
                scanf("%d", &a);
                //a--;
                v[i].emplace_back(a);
                //v[a].emplace_back(i);
            }
        }
        int q;
        scanf("%d", &q);
        for (int i = 0; i < q; i++) {
            int a;
            scanf("%d", &a);
            //a--;
            nx = mx = -1e9;
            bfs(a);
            if(nx==mx and mx==0)
                printf("0\n");
            else
                printf("%d %d\n", nx, mx+1);
        }
    }
}
