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
  int countPairs(vector<int>& nums, int target) {
    int ans = 0;
    int N = nums.size();
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        ans += (nums[i] + nums[j] < target);
      }
    }

    return ans;
  }
};

#ifdef Reoden
int main() {
  std::vector a = {-1, 1, 2, 3, 1};
  int k = 2;
  std::cout << Solution{}.countPairs(a, k) << "\n";
  return 0;
}
#endif