#include <bits/stdc++.h>
using namespace std;

struct UnionFind
{
    vector<int> parent;
    vector<int> rank;

    UnionFind(int size)
    {
        parent.resize(size + 1);
        rank.resize(size + 1, 0);
        for (int i = 0; i <= size; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (rank[x] < rank[y])
        {
            parent[x] = y;
        }
        else
        {
            parent[y] = x;
            if (rank[x] == rank[y])
            {
                rank[x]++;
            }
        }
    }
};

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    UnionFind uf(2 * N);

    for (int i = 0; i < M; ++i)
    {
        char type;
        int p, q;
        cin >> type >> p >> q;
        if (type == 'F')
        {
            uf.unite(p, q);
            uf.unite(p + N, q + N);
        }
        else if (type == 'E')
        {
            uf.unite(p, q + N);
            uf.unite(q, p + N);
        }
    }

    unordered_set<int> groups;
    for (int i = 1; i <= N; ++i)
    {
        groups.insert(uf.find(i));
    }

    cout << groups.size() << endl;

    return 0;
}