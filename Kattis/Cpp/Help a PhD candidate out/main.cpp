#include <iostream>
#include <sstream>
#include <algorithm>

// Problem A: Help a PhD candidate out!
int main() {
  int N, a, b;
  std::cin >> N;
  std::string line;

  while (N--) {
    std::cin >> line;
    if (line.at(0) != 'P') {
      std::replace(line.begin(), line.end(), ':', ' ');
      std::stringstream ss(line);
      ss >> a >> b;
      printf("%d\n", a + b);
    } else {
      printf("%s\n", "skipped");

    }
  }

}

