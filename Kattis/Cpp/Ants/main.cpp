// https://open.kattis.com/problems/ants
#include <iostream>
#include <cstdint>
#include <limits>
#include <cmath>

int main(){
  std::uint32_t c, n, pos = 0;
  double l;

  std::cin >> c;
  while(c--){
    std::uint32_t left = 0, right = INT32_MAX, minLeft = INT32_MAX, maxRight=0;
    std::cin >> l >> n;
    float mid = l/2.0F;

    while(n--) {
      std::cin >> pos;
      if(pos - mid <= 0){
        if (pos > left) left = pos;
        if(pos < minLeft) minLeft = pos;
      }else{
        if (pos < right) right = pos;
        if(pos > maxRight) maxRight = pos;
      }
    }
    std::cout << std::fmax(left, l-right) << " " << std::fmax(l-minLeft, maxRight) << std::endl;
  }
}