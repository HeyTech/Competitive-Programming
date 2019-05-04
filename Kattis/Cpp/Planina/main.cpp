#include <iostream>

// Planina
int main() {
  int iter;
  std::cin >> iter;
  int tot = 2;
  while (iter--) {
    tot += tot - 1;
  }
  printf("%d", tot*tot);

}

