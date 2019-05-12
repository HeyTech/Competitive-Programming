// https://open.kattis.com/problems/listgame

#include <iostream>
#include <cmath>
typedef std::uint32_t uint32;
int main() {
  uint32 X = 0, k = 0, divide = 2;
  std::cin >> X;

  while (X > 1) {
    // std::cout << (!(X % divide)) << " (" << X <<" )- " << divide << " " <<  std::ceil(std::sqrt(X))<< " " << (divide > std::sqrt(X)) << std::endl;
    if (divide > std::sqrt(X)) {
      break;
    } else if (!(X % divide)) { // (X%divide) == 0
      k++;
      X /= divide;
      divide = 2;
    } else {
      divide++;
    }
  }
  std::cout << ++k << std::endl;
}