#include "common/common.h"
#include "days/day1.h"
#include "days/day2.h"

// template <typename T>
// auto task_runner(namespace cc)> task,
//                 std::vector<T> inputs) -> void {
//  task(inputs);
//};


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie();

  std::string line;
  std::vector<std::string> inputs;

  while (std::cin >> line) {
    inputs.push_back(line);
  }

  Day2<std::string> day(inputs);
  day.task1();
  day.task2();

  return 0;
}
