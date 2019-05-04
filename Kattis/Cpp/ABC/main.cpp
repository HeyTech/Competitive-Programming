// https://open.kattis.com/problems/abc

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  std::vector<int> vec;
  int x;
  int k = 3;

  while (k-- > 0) {
    std::cin >> x;
    vec.push_back(x);
  }
  std::string des;
  std::cin >> des;

  std::sort(vec.begin(), vec.end());
  printf("%d %d %d", vec[des[0] - 'A'], vec[des[1] - 'A'], vec[des[2] - 'A']);





}