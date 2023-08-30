#include <bits/stdc++.h>

using namespace std;

int _ = [] {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  return 0;
}();

class Solution {
public:
  int romanToInt(string s) {
    std::unordered_map<char, int> ht;
    ht['I'] = 1;
    ht['V'] = 5;
    ht['X'] = 10;
    ht['L'] = 50;
    ht['C'] = 100;
    ht['D'] = 500;
    ht['M'] = 1000;

    int ans = 0;
    for (size_t i = 1; i < s.size(); i++) {
      if (ht[s[i]] > ht[s[i - 1]]) {
        ans -= ht[s[i - 1]];
      } else {
        ans += ht[s[i - 1]];
      }

      // std::cerr << ans << std::endl;
    }

    ans += ht[s.back()];
    return ans;
  }
};

#ifdef Reoden
int main() {
  // std::vector a = {2, 1, 2};
  std::string a = "MCMXCIV";
  std::cout << Solution{}.romanToInt(a) << "\n";
  return 0;
}
#endif