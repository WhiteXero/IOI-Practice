#include <bits/stdc++.h>
using namespace std;
vector<string> num;
vector<long long> comp;

long long search(int u, int v, int w)
{
  for (string s : num)
  {
    if (s.length() >= u && s[s.length() - u] - '0' == v)
    {
      comp.push_back(stoll(s));
    }
  }
  sort(comp.begin(), comp.end());
  int size = comp.size();
  if (size < w)
  {
    return -1;
  }
  else
    return comp[w - 1];
}

int main()
{
  freopen("factor.in", "r", stdin);
  freopen("factor.out", "w", stdout);
  string t;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> t;
    num.push_back(t);
  }
  cin >> n;
  int u, v, w;
  for (int i = 0; i < n; i++)
  {
    cin >> u >> v >> w;
    cout << search(u, v, w) << endl;
    comp.clear();
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}