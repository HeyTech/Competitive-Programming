// https://open.kattis.com/problems/pripreme
#include <iostream>
#include <cstdint>

int main() {
std::ios_base::sync_with_stdio(false);

  std::uint32_t ele, MAX = 0;
  std::uint64_t SUM = 0;
  std::cin >> ele;

  while (std::cin >> ele) {
    SUM += ele;
    if (MAX < ele) MAX = ele;
  }
  printf("%llu", MAX > (SUM - MAX) ? MAX<<1 : SUM);
}