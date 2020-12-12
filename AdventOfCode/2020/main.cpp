#include <string>
#include <vector>

#include "aoc/read_input.h"
#include "days/day12.h"

int main() {
  //  std::vector<std::string> inputs{
  //      "F10", "N3", "F7", "R90", "F11",
  //  };

  std::vector<std::string> inputs;
  aoc::read_input::each_line(inputs);
  Day12<std::string> day(inputs);
  day.task1();
  day.task2();

  return 0;
}
