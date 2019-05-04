#include <iostream>

// Last Factorial Digit
int main() {
  int T, A;
  std::cin >> T;

  while (T-- > 0) {
    std::cin >> A;
    int B = 1;
    for (int i = 1; i <= A; i++) {
      B *= i;
    }
    printf("%d\n", B % 10);
  }

  return 0;
}
