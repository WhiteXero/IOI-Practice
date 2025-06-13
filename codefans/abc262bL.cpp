#include <bits/stdc++.h>
using namespace std;
int N, M, ans = 0;
int matrix[105][105];

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    memset(matrix, 0, sizeof(matrix));
    cin >> N >> M;
    int i, j;
    for (int x = 1; x <= N; x++)
    {
        matrix[x][x] = 0;
    }
    for (int x = 1; x <= M; x++)
    {
        cin >> i >> j;
        matrix[i][j] = 1;
        matrix[j][i] = 1;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            for (int k = j + 1; k <= N; k++)
            {
                if (matrix[i][j] && matrix[j][k] && matrix[k][i])
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}