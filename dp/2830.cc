#include <bits/stdc++.h>

using namespace std;

int _ = [] {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  return 0;
}();

struct DebugLine {
  explicit DebugLine(int lineno) { std::cerr << lineno << "L "; }
 
  ~DebugLine() { std::cerr << std::endl; }
 
  template <typename T> DebugLine &operator<<(T &&v) {
    std::cerr << std::forward<T>(v);
    return *this;
  }
};

#define KV(x) #x << " = " << x << ";"
#define DEBUG DebugLine(__LINE__)

class Solution {
public:
  int maximizeTheProfit(int n, vector<vector<int>>& offers) {
    std::vector<int> dp(n + 1);
    std::vector<std::vector<std::array<int, 2>>> segs(n);
    for (auto &seg : offers) {
      int be = seg[0], ed = seg[1], cost = seg[2];
      segs[ed].push_back({be, cost});
    }

    for (int i = 0; i < n; i++) {
      dp[i + 1] = dp[i];
      if (segs[i].empty()) {
        continue;
      }

      for (auto &x : segs[i]) {
        dp[i + 1] = std::max(dp[i + 1], dp[x[0]] + x[1]);
      }
    }

    return dp[n];
  }
};

#ifdef Reoden
int main() {
  int n = 5;
  std::vector<std::vector<int>> a = {{0, 0, 1}, {0, 2, 10}, {1, 3, 2}};
  std::cout << Solution{}.maximizeTheProfit(n, a) << "\n";
  return 0;
}
#endif