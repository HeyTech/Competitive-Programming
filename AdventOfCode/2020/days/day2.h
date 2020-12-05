#pragma once
#include "../aoc/aoc.h"
#include <ostream>
#include <regex>

namespace {
  struct Match {
    int lowest;
    int highest;
    std::string characher;
    std::string password;

    friend std::ostream &operator<<(std::ostream &s, const Match &match) {
      return s << match.lowest << " " << match.highest << " " << match.characher
               << " " << match.password;
    }
  };
};

template <typename T> class Day2 {
public:
  explicit Day2(std::vector<T> const inputs) : in_{inputs} {};

  auto task1() -> void {
    FUNCTIONCALL
    std::size_t counter{0};
    for (const std::string &pass : in_) {
      std::smatch m;
      std::regex_match(pass, m, re);
      Match match{std::stoi(m[0]), std::stoi(m[2]), m[3], m[4]};
      long const count{std::count(match.password.begin(), match.password.end(),
                                  match.characher.at(0))};
      if (match.lowest <= count && count <= match.highest) {
        counter++;
      }
    }
    ANSWER1(counter)
  }

  auto task2() -> void {
    FUNCTIONCALL
    std::size_t counter{0};
    for (const std::string &pass : in_) {
      std::smatch m;
      std::regex_match(pass, m, re);
      // Fixing the index
      Match match{std::stoi(m[0]) - 1, std::stoi(m[2]) - 1, m[3], m[4]};
      if ((match.password.size() > match.lowest) &&
          (match.password.size() > match.highest)) {
        char const char_lower{match.password.at(match.lowest)};
        char const char_higher{match.password.at(match.highest)};
        bool const cond_one{match.characher.at(0) == char_lower};
        bool const cond_two{match.characher.at(0) == char_higher};
        if ((cond_one | cond_two) && !(cond_one && cond_two)) {
          counter++;
        }
      }
    }
    ANSWER2(counter)
  }

private:
  std::vector<T> in_;
  std::regex const re{"^(\\d+)-(\\d+) ([a-z]): ([a-z]+)", std::regex::icase};
};
