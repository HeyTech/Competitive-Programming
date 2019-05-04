#include <iostream>

int calculateBits() {
  unsigned long int Y, X;
  int max = 0;
  int count;
  std::cin >> Y;

  while((X = Y) > 0) {
    count = 0;
    while (X > 0) {
      if (X & 1) count++;
      X >>= 1;
    }
    if (count > max) max = count;
    Y/=10;
  }
  return max;
}

// Problem F Bits
int main() {
  int T;
  std::cin >> T;
  while (T-- > 0) {
    printf("%d\n", calculateBits());
  }
  return 0;
}
