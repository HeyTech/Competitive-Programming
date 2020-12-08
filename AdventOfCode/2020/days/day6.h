#pragma once
#include "../aoc/aoc.h"

template <typename T> class Day6 {
public:
  explicit Day6(std::vector<T> const &inputs) : in_{inputs} {};

  // Invoke with aoc::read_input::line_delimiter(inputs, "", "");
  auto task1() -> void {
    FUNCTIONCALL
    std::size_t yes_answers{0};
    for (auto const &group : in_) {
      std::set<char> unique;
      std::copy(group.begin(), group.end(),
                std::inserter(unique, unique.begin()));
      yes_answers += unique.size();
    }
    ANSWER1(yes_answers)
  }

  // aoc::read_input::each_line(inputs);
  auto task2() -> void {
    FUNCTIONCALL
    std::size_t combined{0};
    std::vector<char> common;
    common.reserve(30);
    bool new_round{true};

    for (auto const &line : in_) {
      // New group about to come.. reset the stuff..
      if (line == "") {
        combined += common.size();
        common.clear();
        new_round = true;
        continue;
      }

      // Insert the first answers to the vector.
      if (new_round) {
        new_round = false;
        std::copy(line.begin(), line.end(), std::back_inserter(common));
      } else {
        for (auto it = 0; it < common.size(); it++) {
          char code{common[it]};
          if (line.find(code) == std::string::npos) { // not found
            common.erase(common.begin() + it);
            it--;
          }
        }
      }
    }
    ANSWER2(combined)
  }

private:
  std::vector<T> in_;
};
