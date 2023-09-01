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
  bool check(char a, char b) {
    a %= 26;
    b %= 26;
    return (a == b || (a + 1) % 26 == b);
  }

  bool canMakeSubsequence(string str1, string str2) {
    const int N = str1.size();
    const int M = str2.size();
    int now = 0;
    for (int i = 0; i < N && now < M; i++) {
      if (check(str1[i], str2[now])) {
        now++;
      }
    }

    return now == M;
  }
};

#ifdef Reoden
int main() {
  std::string str1 = "eh";
  std::string str2 = "e";
  std::cout << Solution{}.canMakeSubsequence(str1, str2) << "\n";
  return 0;
}
#endif