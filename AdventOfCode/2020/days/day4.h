#pragma once
#include "../aoc/aoc.h"

template <typename T> class Day4 {
public:
  explicit Day4(std::vector<T> const &inputs) : passports_{inputs} {};

  auto task1() -> void {
    FUNCTIONCALL
    std::size_t valid_pass{0};
    for (auto const &p : passports_) {
      auto conf = std::count(p.begin(), p.end(), ':');
      if (conf == 8) {
        valid_pass++;

      } else if (conf == 7) {
        auto cid{p.find("cid:")};
        if (cid == std::string::npos) {
          valid_pass++;
        }
      }
    }
    ANSWER1(valid_pass)
  }

  auto task2() -> void {
    FUNCTIONCALL
    // TODO - alot of checks..
  }

private:
  std::vector<T> passports_; // String
};
