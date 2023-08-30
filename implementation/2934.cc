#include <bits/stdc++.h>

using namespace std;

int _ = [] {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  return 0;
}();

class Solution {
public:
  long long minimumPossibleSum(int n, int target) {
    // std::vector<int> nums;

    long long ans = 0;
    int index = 0;
    for (int i = 1; i <= target / 2; i++, index++) {
      if (index == n) {
        break;
      }
      ans += i;
      // nums.emplace_back(i);
    }
    int M = n - index;
    // cout << M << "\n";
    for (int i = target; i < target + M; i++) {
      ans += i;
      // nums.emplace_back(i);
    }


    // for (auto &x : nums) {
    //   std::cout << x << " \n"[x == nums.back()];
    // }
    return ans;
  }
};

#ifdef Reoden
int main() {
  // std::vector a = {2, 1, 2};
  // std::string moves = "_R__LL_";
  int n = 13, target = 50;
  std::cout << Solution{}.minimumPossibleSum(n, target) << "\n";
  return 0;
}
#endif