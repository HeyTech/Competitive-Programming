// https://open.kattis.com/problems/trik

#include <iostream>
#include <algorithm>

int main() {
  std::string line;
  std::cin >> line;
  int a = 1, b = 0, c = 0;

  for (char ch: line) {
    switch (ch) {
      case 'A': {
        std::swap(a, b);
        break;
      }
      case 'B': {
        std::swap(b, c);
        break;
      }
      case 'C': {
        std::swap(a, c);
        break;
      }

    }
  }

  if (a == 1) { printf("1"); }
  else if (b == 1) { printf("2"); }
  else { printf("3"); }

}