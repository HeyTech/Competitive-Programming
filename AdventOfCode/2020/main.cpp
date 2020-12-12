#include "aoc/aoc.h"
#include "aoc/read_input.h"
#include <string>
#include <vector>

#include "days/day1.h"
#include "days/day2.h"
#include "days/day3.h"
#include "days/day4.h"
#include "days/day5.h"
#include "days/day6.h"
#include "days/day7.h"

#include "days/day11.h"

int main() {

    std::vector<std::string> inputs;
    aoc::read_input::each_line(inputs);
//  std::vector<std::string> inputs{
//      "L.LL.LL.LL",
//      "LLLLLLL.LL",
//      "L.L.L..L..",
//      "LLLL.LL.LL",
//      "L.LL.LL.LL",
//      "L.LLLLL.LL",
//      "..L.L.....",
//      "LLLLLLLLLL",
//      "L.LLLLLL.L",
//      "L.LLLLL.LL",
//  };
  Day11<std::string> day(inputs);
  day.task1();
  day.task2();

  return 0;
}
