#include <bits/stdc++.h>
#define MAXN 10000
using namespace std;
stack<int> ans;
int minM = 0x3f3f3f3f;
int maxM = 0;
int deg[MAXN] = {0};
int G[MAXN][MAXN] = {0};
void Hierholzer(int start)
{
    for (int step = minM; step <= maxM; step++)
    {
        if (G[start][step])
        {
            G[start][step]--;
            G[step][start]--;
            Hierholzer(step);
        }
    }
    ans.push(start);
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int m, u, v;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        minM = min(min(u, v), minM);
        maxM = max(max(u, v), maxM);
        G[u][v]++;
        G[v][u]++;
        deg[v]++;
        deg[u]++;
    }
    int start = minM;
    for (int i = minM; i <= maxM; i++)
    {
        if (deg[i] % 2 == 1)
        {
            start = i;
            break;
        }
    }
    Hierholzer(start);
    while (!ans.empty())
    {
        cout << ans.top() << endl;
        ans.pop();
    }
    return 0;
}