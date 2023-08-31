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
  int longestEqualSubarray(vector<int>& nums, int k) {
    int N = nums.size();
    std::vector<std::vector<int>> pos(N + 1);
    for (int i = 0; i < N; i++) {
      pos[nums[i]].emplace_back(i);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
      if (pos[i].empty()) {
        continue;
      }

      int l = 0, r = 0;
      for (; r < pos[i].size(); r++) {
        while (pos[i][r] - pos[i][l] - (r - l) > k) {
          l++;
        }
        ans = std::max(ans, r - l + 1);
      }
    }
    return ans;
  }
};

#ifdef Reoden
int main() {
  std::vector a = {1, 1, 2, 2, 1, 1};
  int k = 2;
  std::cout << Solution{}.longestEqualSubarray(a, k) << "\n";
  return 0;
}
#endif