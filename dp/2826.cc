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
  int minimumOperations(vector<int>& nums) {
    std::vector<int> store;
    for (auto &x : nums) {
      auto it = std::upper_bound(store.begin(), store.end(), x);
      if (it == store.end()) {
        store.push_back(x);
      } else {
        *it = x;
      }
    }
    return nums.size() - store.size();
  }
};

#ifdef Reoden
int main() {
  std::vector a = {2, 1, 3, 2, 1};
  std::cout << Solution{}.minimumOperations(a) << "\n";
  return 0;
}
#endif