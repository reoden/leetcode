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
  int numberOfBeautifulIntegers(int low, int high, int k) {
    int a[50]{}, dp[50][50][20][20]{};
    int N = 0;
    
    std::function<int(int, int, int, int, int, int)> dfs = [&] (int pos, int lead, int md, int odd, int even, int limit) -> int {
      if (!pos) return !md && odd == even;
      if (!limit && !lead && ~dp[pos][md][odd][even]) return dp[pos][md][odd][even];
      int res = 0, up = limit ? a[pos] : 9;
      for (int i = 0; i <= up; i++) {
        if (lead && !i) res += dfs(pos - 1, lead && !i, md, odd, even, limit && i == up);
        else res += dfs(pos - 1, lead && !i, (md * 10 + i) % k, odd + (i % 2), even + (i % 2 == 0), limit && i == up);
      }
      return limit ? res : dp[pos][md][odd][even] = res;
    };
    
    auto calc = [&](int x) -> int {
      int len = 0;  
      memset(dp, -1, sizeof dp);
      while(x) a[++len] = x % 10, x /= 10;
      N = len;
      return dfs(len, 1, 0, 0, 0, 1);
    };

    return calc(high) - calc(low - 1);
  }
};

#ifdef Reoden
int main() {
  int low = 349863935, high = 772153463, k = 11;
  std::cout << Solution{}.numberOfBeautifulIntegers(low, high, k) << "\n";
  std::cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
  return 0;
}
#endif