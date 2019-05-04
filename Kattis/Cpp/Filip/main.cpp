#include <iostream>
#include <vector>

// Filip
int main() {
  int A, B;
  int a = 0, b = 0;

  std::cin >> A >> B;
  for (int i = 0; i < 3; ++i) {
    a = a * 10 + A % 10;
    b = b * 10 + B % 10;
    A /= 10;
    B /= 10;
  }
  printf("%d", (a>b) ? a : b);

  return 0;
}
