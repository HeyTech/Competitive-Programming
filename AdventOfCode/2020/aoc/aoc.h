#pragma once

#include <algorithm>
#include <cstdint>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

namespace aoc {
namespace macro {
// clang-format off
// define logging and commands
#define FUNCTIONCALL std::cout << __PRETTY_FUNCTION__ << std::endl;
#define ANSWER1(msg) std::cout << "[Task 1]: The Answer is: " << msg << std::endl;
#define ANSWER2(msg) std::cout << "[Task 2]:The Answer is: " << msg << std::endl;

#define NOANSWERFOUND std::cout << "No Answer has been found!" << std::endl;
// clang-format on
} // namespace macro

auto inline repeat_string(std::string const &input, std::string &output,
                          std::size_t num) {
  for (int i = 0; i < num; ++i) {
    output.append(input);
  }
}
} // namespace aoc
