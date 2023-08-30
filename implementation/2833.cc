#include <bits/stdc++.h>

using namespace std;

int _ = [] {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  return 0;
}();

class Solution {
public:
  int furthestDistanceFromOrigin(string moves) {
    int A = std::count(moves.begin(), moves.end(), 'L');
    int B = std::count(moves.begin(), moves.end(), 'R');
    int C = std::count(moves.begin(), moves.end(), '_');
    return std::max(A, B) + C - std::min(A, B);
  }
};

#ifdef Reoden
int main() {
  // std::vector a = {2, 1, 2};
  std::string moves = "_R__LL_";
  std::cout << Solution{}.furthestDistanceFromOrigin(moves) << "\n";
  return 0;
}
#endif