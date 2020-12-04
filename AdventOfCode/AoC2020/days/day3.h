#pragma once
#include "../aoc/aoc.h"
#include <cmath>

template <typename T> class Day3 {
public:
  explicit Day3(std::vector<T> const &inputs)
      : in_{inputs}, width_{in_[0].size()}, height_{in_.size()} {};

  auto tree_encounter(std::size_t right, std::size_t down) -> std::size_t {

    std::size_t trees{0};
    // calculate all the cordinates
    for (std::size_t y = down; y < height_; y += down) {
      double x{std::floor((y) / ((double)down / right))};
      std::size_t rep_times{static_cast<std::size_t>(std::floor(x / width_))};
      { // to release all stored strings...
        std::string new_width{in_[y]};
        aoc::repeat_string(in_[y], new_width, rep_times);

        if (new_width.at(x) == '#') {
          trees++;
        }
      }
    }
    return trees;
  }

  auto task1() -> void { ANSWER1(tree_encounter(3, 1)) }

  auto task2() -> void {
    std::size_t const t1{tree_encounter(1, 1)};
    std::size_t const t2{tree_encounter(3, 1)};
    std::size_t const t3{tree_encounter(5, 1)};
    std::size_t const t4{tree_encounter(7, 1)};
    std::size_t const t5{tree_encounter(1, 2)};

    std::cout << t1 << " " << t2 << " " << t3 << " " << t4 << " " << t5
              << std::endl;
    ANSWER2(t1 * t2 * t3 * t4 * t5)
  }

private:
  std::vector<T> in_;
  std::size_t width_{0};
  std::size_t height_{0};
};