#include <bits/stdc++.h>
using namespace std;
int N, M;
set<int> cowlist;
vector<vector<int>> connection;
vector<bool> visited;

void dfs(int index)
{
    cowlist.insert(index);
    visited[index] = true;
    if (connection[index].empty())
        return;

    for (int next : connection[index])
    {
        if (!visited[next])
            dfs(next);
    }
}

int main()
{
    freopen("daisy.in", "r", stdin);
    freopen("daisy.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    connection.resize(N + 10);
    visited.resize(N + 10, false);
    int a, b;
    for (int i = 1; i <= M; i++)
    {
        cin >> a >> b;
        connection[a].push_back(b);
    }
    dfs(1);
    for (int i = 1; i <= N; i++)
    {
        if (cowlist.count(i) == 0)
        {
            cout << i << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}