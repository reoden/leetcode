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

void debug(const std::map<int, int> &mp, const std::array<int, 32> &tar, const int &cur) {
  for (auto &[k, v] : mp) {
    DEBUG << KV(k) << " " << KV(v);
  }

  std::cout << std::endl;
  for (int i = 0; i < cur; i++) {
    DEBUG << KV(i) << " " << KV(tar[i]);
  }
}

class Solution {
public:
  int minOperations(vector<int>& nums, int target) {
    if (std::accumulate(nums.begin(), nums.end(), 0LL) < target) {
      return -1;
    }
    std::map<int, int> base;
    std::array<int, 32> tar{};
    for (auto &x : nums) {
      base[std::__lg(x)]++;
    }

    int now = target;
    int cur = 0;
    while (now) {
      tar[cur] = now & 1;
      now >>= 1;
      cur++;
    }

    // for (auto &mp : base) {
    //   std::cout << mp.first << " " << mp.second << "\n";
    // }

    // cout << "\n";
    // for (int i = 0; i <= 31; i++) {
    //   cout << i << " " << tar[i] << "\n";
    // }
    int ans = 0;
    int last = -1;
    for (int i = 0; i <= 31; i++) {
      if (last == -1 && i >= cur) {
        break;
      }
      // DEBUG << KV(i) << " " << KV(last);
      // debug(base, tar, cur);
      if (last != -1) {
        if (base.count(i) != 0U) {
          ans += i - last;
          last = -1;
          base[i]--;
          if (base[i] == 0) {
            base.erase(i);
          }
        } 
      }

      if (last == -1) {
        if (tar[i]) {
          if (base.count(i) != 0U) {
            base[i]--;
            if (base[i] == 0) {
              base.erase(i);
            }
          } else {
            last = i;
          }
        }
      }

      if (base.count(i) != 0U && base[i] >= 2) {
        int x = base[i] / 2;
        base[i] -= 2 * x;
        base[i + 1] += x;
        if (base[i] == 0) {
          base.erase(i);
        }
      }
    }

    return ans;
  }
};

#ifdef Reoden
int main() {
  std::vector a = {1,1,1,1,128,1,64,8};
  // std::string moves = "_R__LL_";
  int target = 7;
  std::cout << Solution{}.minOperations(a, target) << "\n";
  return 0;
}
#endif