#include "aoc/aoc.h"
#include "days/day1.h"
#include "days/day2.h"
#include "days/day3.h"
#include "days/day4.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie();

  std::string line;
  std::vector<std::string> inputs;

  while (std::getline(std::cin, line)) {
    inputs.push_back(line);
  }

  Day4<std::string> day(inputs);
  day.task1();
  day.task2();

  return 0;
}
