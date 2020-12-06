#include "aoc/aoc.h"
#include "aoc/read_input.h"

#include "days/day1.h"
#include "days/day2.h"
#include "days/day3.h"
#include "days/day4.h"

int main() {
  std::vector<std::string> inputs;

  aoc::read_input::line_delimiter(inputs, "", " ");
  Day4<std::string> day(inputs);
  day.task1();
  day.task2();

  return 0;
}
