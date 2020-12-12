#pragma once
#include <unordered_map>
#include <vector>

#include "../aoc/aoc.h"

template <typename T> class Day12 {
public:
  explicit Day12(std::vector<T> const &inputs) : in_{inputs} {};

  auto inline get_new_direction(char& cdir, char& dir, int degree) const -> void {
    std::string dirs{""};
    if (dir == 'R') {
      dirs = "ESWN";
    } else{
      dirs = "ENWS";
    }

    std::cout << "* beg: " << dir << " : " << cdir;

    int pos{static_cast<int>(dirs.find(cdir))};
    cdir = dirs.at((degree / 90 + pos) % 4);
    std::cout << " - " << pos << " * " << cdir << std::endl;
  }

  auto task1() -> void {
    FUNCTIONCALL
    char cdir = 'E';
    std::unordered_map<char, int> direction{
        {'N', 0}, {'E', 0}, {'S', 0}, {'W', 0}};
    for (auto const &line : in_) {
      char dir{line.at(0)};
      int val{std::stoi(line.substr(1))};

      std::cout << "********************" << std::endl;
      std::cout << dir << " " << val  <<  "    -   " << cdir << std::endl;

      if(dir == 'F'){
        dir = cdir;
      }

      switch (dir) {
      case 'R':
      case 'L': {
        get_new_direction(cdir, dir, val);
        val = 0;
        continue;
      }
      case 'W':
      case 'S': {
        val *= -1;
        break;
      }
      }
      direction[dir] += val;


      for (const auto &n : direction) {
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
      }
    }

    ANSWER1(std::abs(direction['W']+direction['E']) +std::abs(direction['N']+direction['S']) )
  }

  auto task2() -> void { FUNCTIONCALL }

private:
  std::vector<T> in_;
};
