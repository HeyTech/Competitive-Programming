// https://open.kattis.com/problems/reversebinary
#include <iostream>
#include <cstdint>

std::uint32_t temp, res = 0;

int main(){
  std::cin >> temp;
  while(temp > 0){
    res |= temp&1u;
    res <<= 1u;
    temp >>= 1u;
  }
  std::cout << (res>>1u);
}
