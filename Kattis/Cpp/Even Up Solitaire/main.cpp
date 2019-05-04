#include <iostream>
#include <vector>

// Problem G Even Up Solitaire
int main() {
  std::vector<int> vec;
  int n, p;
  std::cin >> n;
  std::cin >> p;
  vec.push_back(p);
  while (--n > 0) {
      std::cin >> p;
      int sum = vec.back() + p;
      if ((sum % 2) == 0 && vec.size() > 0) {
        vec.pop_back();
      } else {
        vec.push_back(p);
      }
    }
  printf("%lu", vec.size());

  return 0;
}
