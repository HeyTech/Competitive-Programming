#pragma once
#include "../aoc/aoc.h"
#include <map>
#include <queue>
#include <regex>
#include <string>

namespace {
struct Bag {
  std::string name{};
  int num{};
};

struct ParentBag {
  std::string name;
  std::size_t n{0};
  std::vector<Bag> carry;
};
} // namespace

template <typename T> class Day7 {
public:
  explicit Day7(std::vector<T> const &inputs) : in_{inputs} {
    pre_processing();
  };

  auto pre_processing() -> void {
    for (auto &line : in_) {
      ParentBag pb;
      std::smatch m;
      std::regex_search(line, m, re_bag_);
      pb.name = m[0];

      // fix name and number for each
      while (std::regex_search(line, m, re_carry_)) {
        std::string bag_name{m[0].str().substr(2)};
        int num{std::stoi(m[0].str().substr(0, 1))};
        Bag b{bag_name, num};
        pb.carry.emplace_back(b);
        line = m.suffix().str();
      }

      if (pb.carry.empty()) {
        Bag b{"no other", 0};
        pb.carry.emplace_back(b);
      }

      // Add parent bah to the queue.. and to the map...
      q_.push(pb);
      bags_.insert(bags_.begin(),
                   std::pair<std::string, ParentBag>(pb.name, pb));
    }
    // std::bad_alloc otherwise :)
    bags_.insert(bags_.begin(), std::pair<std::string, ParentBag>(
                                    "no other", {"no other", {}}));
  }

  auto task1() -> void {
    FUNCTIONCALL
    std::string const wante_bag{"shiny gold"};
    std::size_t ans{0};

    while (!q_.empty()) {
      ParentBag pb = q_.front();
      q_.pop();

      std::queue<Bag> que;
      std::for_each(pb.carry.begin(), pb.carry.end(),
                    [&que](Bag &q_bag) { que.push(q_bag); });

      while (!que.empty()) {
        Bag bag{que.front()};
        que.pop();

        if (bag.name == wante_bag) {
          ans++;
          break;
        } else {
          std::vector<Bag> carry{bags_.find(bag.name)->second.carry};
          std::for_each(carry.begin(), carry.end(), [&que](Bag &q_bag) {
            if (q_bag.name != "no other") {
              que.push(q_bag);
            }
          });
        }
      }
    }

    ANSWER1(ans)
  }

  auto task2() -> void {
    FUNCTIONCALL
//    std::size_t ans{};
//    std::queue<ParentBag> que;
//    bags_.find("shiny gold")->second.n = 1;
//    que.push(bags_.find("shiny gold")->second);
//
//    while (!que.empty()) {
//      ParentBag pb{que.front()};
//      que.pop();
//
//      std::cout << pb.name << " -- ";
//      std::for_each(pb.carry.begin(), pb.carry.end(),
//                    [&que, this, &ans, &pb](Bag &bag) {
//                      std::cout << bag.name;
//                      if (bag.name != "no other") {
//                        bags_.find(bag.name)->second.n += pb.n * bag.num;
//                        que.push(bags_.find(bag.name)->second);
//                      } else {
//                        ans += pb.n;
//                      }
//                    });
//      std::cout << std::endl;
//    }
//    ANSWER2(ans)
  }

private:
  std::vector<T> in_;
  std::map<std::string, ParentBag> bags_;
  std::queue<ParentBag> q_;

  std::regex const re_bag_{"(^[^\\s]+\\s+[^\\s]+)", std::regex::icase};
  std::regex const re_carry_{"(\\d\\s[^\\s]+\\s[^\\s]+)", std::regex::icase};
};
