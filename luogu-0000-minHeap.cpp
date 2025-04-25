#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
class MinHeap {
 private:
  vector<ll> minHeap;
  ll left(ll i) { return 2 * i + 1; }
  ll right(ll i) { return 2 * i + 2; }
  ll parent(ll i) { return (i - 1) / 2; }
  void heapify(ll i) {
    while (true) {
      ll p = parent(i);
      if (p < 0 || minHeap[i] >= minHeap[p]) break;
      swap(minHeap[i], minHeap[p]);
      i = p;
    }
  }
  void repair(ll i) {
    while (true) {
      ll l = left(i), r = right(i), m = i;
      if (l < minHeap.size() && minHeap[l] < minHeap[m]) m = l;
      if (r < minHeap.size() && minHeap[r] < minHeap[m]) m = r;
      if (m == i) break;
      swap(minHeap[m], minHeap[i]);
      i = m;
    }
  }

 public:
  MinHeap(vector<ll> nums) {
    minHeap = nums;
    for (ll i = parent(minHeap.size() - 1); i >= 0; i--) repair(i);
  }
  ll minimum() { return minHeap[0]; }
  bool isEmpty() { return minHeap.empty(); }
  void push(ll v) {
    minHeap.push_back(v);
    heapify(minHeap.size() - 1);
  }
  void pop() {
    swap(minHeap[0], minHeap[minHeap.size() - 1]);
    minHeap.pop_back();
    repair(0);
  }
  ll size() { return minHeap.size(); }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ll n, ans = 0, x, y;
  cin >> n;
  vector<ll> num(n);
  for (ll i = 0; i < n; i++) {
    cin >> num[i];
  }
  MinHeap minHeap(num);
  while (minHeap.size() > 1) {
    x = minHeap.minimum();
    minHeap.pop();
    y = minHeap.minimum();
    minHeap.pop();
    ans += x + y;
    minHeap.push(x + y);
  }
  cout << ans << endl;
  return 0;
}