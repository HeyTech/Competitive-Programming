// https://open.kattis.com/contests/nmaw85/problems/rijeci
#include <iostream>
#include <cstdint>
int main(){
  std::uint32_t k, A = 1, B = 0, oldA;
  std::cin >> k;
  while(k--){
    oldA = A;
    A = B;
    B += oldA;
  }
  std::cout << A << " " << B;
}