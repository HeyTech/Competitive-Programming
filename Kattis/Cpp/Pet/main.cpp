// https://open.kattis.com/problems/pet
#include <iostream>
#include <cstdint>

static std::uint32_t sum;
static std::uint32_t value;

int main() {
  std::pair<std::uint8_t, std::uint8_t> correct (0, 0);

  for (int i = 1; i <= 5; ++i) {
    sum = 0; value = 0;
    for (int j = 0; j < 4; ++j) {
      std::cin >> std::hex >> value;
      sum += value;
    }

    if (correct.second < sum){
      correct = std::make_pair(i, sum);
    }
  }
  printf("%d %d", correct.first, correct.second);
}