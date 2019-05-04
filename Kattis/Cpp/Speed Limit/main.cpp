// https://open.kattis.com/problems/speedlimit
#include <iostream>

// Speed Limit
int main() {
  int n, t, s, t1, sum;
  while (std::cin >> n) {
    t1 = 0, sum = 0;
    if (n < 0) break;
    while (n-- > 0) {
      std::cin >> s >> t;
      sum += s * (t - t1);
      t1 = t;
    }
    printf("%d miles\n", sum);
  }

}
