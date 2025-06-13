#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> city[5005];
bool vis[5005];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;i++) {
        cin>>u>>v;
        city[u].push_back(v);
        city[v].push_back(u);
    }
    for(int i=1;i<=n;i++) {
        sort(city[i].begin(),city[i].end());
    }
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty()) {
        const int now = q.front();
        q.pop();
        cout<<now<<" ";
        for(int i : city[now]) {
            if(!vis[i]) {
                q.push(i);
                vis[i] = true;
            }
        }
    }
    return 0;
}