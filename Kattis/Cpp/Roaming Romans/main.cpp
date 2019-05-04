// https://open.kattis.com/problems/romans
#include <iostream>
#include <cmath>
static constexpr float term =  1000*(5280.0/4854);

int main() {
  float result;
  std::cin >> result;
    std::cout << (int) std::round(result * term) << std::endl;