#pragma once
#include "../aoc/aoc.h"
#include "../aoc/checks.h"

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
        passport_.push_back(p);
      } else if (conf == 7) {
        auto cid{p.find("cid:")};
        if (cid == std::string::npos) {
          valid_pass++;
          passport_.push_back(p);
        }
      }
    }
    ANSWER1(valid_pass)
  }

  auto task2() -> void {
    FUNCTIONCALL

    bool valid;
    std::string buf;
    std::size_t valid_passports{0};
    for (auto const &p : passport_) {
      std::cout << "------------------------------------------------------"
                << std::endl;
      std::cout << p << std::endl;
      valid = true;
      std::stringstream ss{p};
      // iterate thought passport configurations, full loop..
      while (ss >> buf) {
        std::string const key{buf.substr(0, colon_)};
        std::string const value{buf.substr(colon_ + 1, buf.size())};

        if (key == "byr") {
          int year{std::stoi(value)};
          if (!aoc::checks::digit_between_values<int>(1920, 2002, year)) {
            std::cout << "byr: invalid" << std::endl;
            valid = false;
          }
        } else if (key == "iyr") {
          int year{std::stoi(value)};
          if (!aoc::checks::digit_between_values<int>(2010, 2020, year)) {
            std::cout << "iyr: invalid" << std::endl;
            valid = false;
          }
        } else if (key == "eyr") {
          int year{std::stoi(value)};
          if (!aoc::checks::digit_between_values<int>(2020, 2030, year)) {
            std::cout << "eyr: invalid" << std::endl;
            valid = false;
          }
        } else if (key == "hgt") {
          auto const cm{value.find('c')};
          auto const in{value.find('i')};

          if (cm != std::string::npos) {
            int const hgt{std::stoi(value.substr(0, cm))};
            if (!aoc::checks::digit_between_values<int>(150, 193, hgt)) {
              std::cout << "hgt(cm): invalid" << std::endl;
              valid = false;
            }
            //            std::cout << value << " cm " << hgt << std::endl;
          } else if (in != std::string::npos) {
            int const hgt{std::stoi(value.substr(0, in))};
            if (!aoc::checks::digit_between_values<int>(59, 76, hgt)) {
              std::cout << "hgt(in): invalid" << std::endl;
              valid = false;
            }
            //            std::cout << value << " in " << hgt << std::endl;
          } else {
            valid = false;
          }
        } else if (key == "hcl") {
          if (value.at(0) != '#') {
            std::cout << "hcl #: invalid" << std::endl;
            valid = false;
          } else if (value.length() != 7) {
            std::cout << "hcl 7: invalid" << std::endl;
            valid = false;
          } // not done
          std::string const color{value.substr(1, value.size())};
          if (color.find_first_not_of("0123456789abcdef") !=
              std::string::npos) {
            std::cout << "hcl a-f: invalid " << color << std::endl;
            valid = false;
          }
        } else if (key == "ecl") {
          bool const valid_eye_color{value == "amb" || value == "blu" ||
                                     value == "brn" || value == "gry" ||
                                     value == "grn" || value == "hzl" ||
                                     value == "oth"};
          if (!valid_eye_color) {
            std::cout << "ecl: invalid" << std::endl;
            valid = false;
          }
        } else if (key == "pid") {
          if (value.size() != 9) {
            std::cout << "pid 9: invalid" << std::endl;
            valid = false;
          } else if (!aoc::checks::is_digits(value.substr(1, value.size()))) {
            std::cout << "pid digits: invalid" << std::endl;
            valid = false;
          }
        }
      }
      if (valid) {
        std::cout << "********************** Valid ************************"
                  << std::endl;
        valid_passports++;
      }
    }
    ANSWER2(valid_passports)
  }

private:
  std::vector<T> passports_; // String
  std::vector<T> passport_;  // String

  int const colon_{3};
};
