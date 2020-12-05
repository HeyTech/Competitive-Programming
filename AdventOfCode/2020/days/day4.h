#pragma once
#include "../aoc/aoc.h"

template <typename T> class Day4 {
public:
  explicit Day4(std::vector<T> const &inputs) : in_{inputs} {
    std::string pass{};
    for (auto const &line : in_) {
      if (line != "") { // empty line, new pass will soon come..
        pass.append(line + " ");
      } else {
        passports_.push_back(pass);
        pass = "";
      }
    }
  };

  auto task1() -> void {
    FUNCTIONCALL
    for (auto const &p : passports_) {
      std::cout << p << std::endl;
      auto var = std::find(p.begin(), p.end(), ' ');
      if ()

    }
  }

  auto task2() -> void { FUNCTIONCALL }

private:
  std::vector<T> in_; // String
  std::vector<T> passports_;
};
