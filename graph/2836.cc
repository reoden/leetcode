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
  long long getMaxFunctionValue(vector<int>& receiver, long long k) {
    int N = static_cast<int>(receiver.size());
    int M = 64 - __builtin_clzll(k);

    std::vector<std::vector<std::pair<int, long long>>> f(M + 1, std::vector<std::pair<int, long long>>(N));
    for (int i = 0; i < N; i++) {
      f[0][i] = std::make_pair(receiver[i], receiver[i]);
    }

    for (int i = 0; i < M - 1; i++) {
      for (int j = 0; j < N; j++) {
        f[i + 1][j] = std::make_pair(f[i][f[i][j].first].first, f[i][j].second + f[i][f[i][j].first].second);
      }
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
      long long sum = i;
      int cur = i;
      for (long long K = k; K; K -= K & -K) {
        sum += f[__builtin_ctzll(K)][cur].second;
        cur = f[__builtin_ctzll(K)][cur].first;
      }

      ans = std::max(ans, sum);
    }

    return ans;
  }
};

#ifdef Reoden
int main() {
  std::vector a = {2, 0, 1};
  long long k = 4;
  std::cout << Solution{}.getMaxFunctionValue(a, k) << "\n";
  return 0;
}
#endif