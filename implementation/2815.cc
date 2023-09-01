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
  bool check(int x, int y) {
    std::string a = std::to_string(x);
    std::string b = std::to_string(y);
    return *max_element(a.begin(), a.end()) == *max_element(b.begin(), b.end());
  }

  int maxSum(vector<int>& nums) {
    int ans = -1;
    int N = nums.size();
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        if (check(nums[i], nums[j])) {
          ans = std::max(ans, nums[i] + nums[j]);
        }
      }
    }
    return ans;
  }
};

#ifdef Reoden
int main() {
  std::vector a = {1, 2, 3, 4};
  std::cout << Solution{}.maxSum(a) << "\n";
  std::cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
  return 0;
}
#endif