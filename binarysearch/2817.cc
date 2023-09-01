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
  int minAbsoluteDifference(vector<int>& nums, int x) {
    int N = nums.size();
    int ans = 1e9 + 10;
    std::set<int> s;

    for (int i = x; i < N; i++) {
      s.insert(nums[i - x]);
      auto it = s.lower_bound(nums[i]);
      if (it != s.end()) {
        ans = std::min(*it - nums[i], ans);
      }
      if (it != s.begin()) {
        ans = std::min(ans, nums[i] - *std::prev(it));
      }
    }
    return ans;
  }
};

#ifdef Reoden
int main() {
  std::vector a = {1, 2, 3, 4};
  int x = 3;
  std::cout << Solution{}.minAbsoluteDifference(a, x) << "\n";
  std::cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
  return 0;
}
#endif