#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<vector<int>> city;

int main()
{
    freopen("list.in", "r", stdin);
    freopen("list.out", "w", stdout);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    city.resize(N + 1);
    int a, b;
    for (int i = 1; i <= M; i++)
    {
        cin >> a >> b;
        city[a].push_back(b);
        city[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
    {
        sort(city[i].begin(), city[i].end());
    }
    for (int i = 1; i <= N; i++)
    {
        cout << city[i].size() << " ";
        for (int j = 0; j < city[i].size(); j++)
        {
            cout << city[i][j] << " ";
        }
        cout << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}