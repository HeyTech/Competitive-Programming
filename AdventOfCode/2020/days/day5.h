#pragma once
#include "../aoc/aoc.h"
#include <set>

template <typename T> class Day5 {
public:
  explicit Day5(std::vector<T> const &inputs) : in_{inputs} {};

  auto task1() -> void {
    for (auto &seat : in_) {
      //      std::cout << seat << "  -  ";
      std::replace(std::begin(seat), std::end(seat), 'F', '0');
      std::replace(std::begin(seat), std::end(seat), 'L', '0');
      std::replace(std::begin(seat), std::end(seat), 'B', '1');
      std::replace(std::begin(seat), std::end(seat), 'R', '1');
      //      std::cout << seat << std::endl;
      seats_.insert(std::stoi(seat, nullptr, 2));
    }
    ANSWER1(*--seats_.end())
  }

  auto task2() -> void {
    FUNCTIONCALL
    for (auto i = ++seats_.cbegin(); i != seats_.cend(); ++i) {
      if (*std::prev(i) + 1 != *i) {
        //        std::cout << (*std::prev(i)) << " - " << *i << std::endl;
        ANSWER2(*std::prev(i) + 1)
        break;
      }
    }
  }

private:
  std::vector<T> in_;
  std::set<std::size_t> seats_;
};
