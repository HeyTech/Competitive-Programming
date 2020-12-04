#pragma once

#include "../common/common.h"
#include <algorithm>
#include <vector>

template <typename T> class Day1 {
public:
  explicit Day1(std::vector<T> const inputs) : in_{inputs} {};

  void task1() {
    FUNCTIONCALL
    for (std::size_t i = 0; i < in_.size(); ++i) {
      for (std::size_t k = i + 1; k < in_.size(); ++k) {
        std::size_t const sum{in_[i] + in_[k]};
        if (sum == 2020) {
          std::size_t const prod{in_[i] * in_[k]};
          ANSWER1(prod)
          break;
        }
      }
    }
  }

  void task2() {
    FUNCTIONCALL
    // Could be optimized
    for (std::size_t i = 0; i < in_.size(); ++i) {
      for (std::size_t j = i + 1; j < in_.size(); ++j) {
        for (std::size_t k = j + 1; k < in_.size(); ++k) {
          std::size_t const sum{in_[i] + in_[j] + in_[k]};
          if (sum == 2020) {
            std::size_t const prod{in_[i] * in_[j] * in_[k]};
            ANSWER2(prod)
            break;
          }
        }
      }
    }
    NOANSWERFOUND
  }

private:
  std::vector<T> in_;
};
