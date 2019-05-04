// https://open.kattis.com/problems/howmanydigits
#include <iostream>
#include <cmath>

#define E 2.7182818284590452353602874713
#define PI 3.141592653589793238462643383

int main() {
  int n, x;
  while (std::cin >> n) {
    x = (int) std::ceil(n* log10(( n/ E)) + log10(2*PI*n)/2 );
    std::cout << ((n <= 1) ? 1 : x) << std::endl;
  }
}