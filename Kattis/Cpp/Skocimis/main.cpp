// https://open.kattis.com/problems/skocimis
#include <iostream>
#include <cstdint>

int main(){
  std::uint32_t A, B, C;
  std::cin >> A >> B >> C;
  std::printf("%d", std::max(B-A, C-B)-1);
}