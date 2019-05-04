#include <iostream>
#include <set>
// I've Been Everywhere, Man
int main() {
  int N, T;

  std::set<std::string> travel;
  std::string city;
  std::cin >> T;

  while (T-- > 0) {
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
      std::cin >> city;
      travel.insert(city);
    }
    printf("%lu\n", travel.size());
    travel.clear();
  }

  return 0;
}
