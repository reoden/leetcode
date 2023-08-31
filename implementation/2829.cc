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
  int minimumSum(int n, int k) {
    int sum = 0;
    int cnt = 0;
    // DEBUG << KV(k / 2);
    for (int i = 1; i <= k / 2; i++, cnt++) {
      // DEBUG << KV(cnt) << " " << KV(sum) << " " << KV(i);
      if (cnt == n) {
        break;
      }
      sum += i;
    }

    for (int i = k; i < k + n - cnt; i++) {
      sum += i;
    }

    return sum;
  }
};

#ifdef Reoden
int main() {
  int n = 2;
  int k = 6;
  std::cout << Solution{}.minimumSum(n, k) << "\n";
  return 0;
}
#endif