#pragma once
#include "../aoc/aoc.h"
#include <algorithm>
#include <ostream>
#include <vector>

namespace {
struct ColRow {
  int x{}, y{};

  friend std::ostream &operator<<(std::ostream &s, ColRow cr) {
    return s << "(" << cr.x << ", " << cr.y << ")";
  }
};
} // namespace

template <typename T> class Day11 {
public:
  explicit Day11(std::vector<T> const &inputs)
      : in_{inputs}, clean_{inputs}, ySize_{in_.size()}, xSize_{in_[0].size()} {

    for (int yy = 0; yy < ySize_; ++yy) {
      std::string &line{in_[yy]};
      for (int xx = 0; xx < xSize_; ++xx) {
        if (line.at(xx) == 'L') {
          seats_.push_back({xx, yy});
        }
      }
    }
  };

  auto inline change_seat(ColRow const &cr) const -> std::size_t {
    int const x[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int const y[] = {1, 1, 0, -1, -1, -1, 0, 1};
    std::size_t occupied{0};
    for (int i = 0; i < 8; ++i) {
      ColRow tmp{cr.x + x[i], cr.y + y[i]};
      bool const bound_y{tmp.y >= 0 && tmp.y < ySize_};
      bool const bound_x{tmp.x >= 0 && tmp.x < xSize_};
      if (bound_x && bound_y) {
        if (in_[tmp.y].at(tmp.x) == '#') {
          occupied++;
        }
      }
    }
    return occupied;
  }

  auto inline change_seat_extended(ColRow const &cr) const -> std::size_t {
    int const x[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int const y[] = {1, 1, 0, -1, -1, -1, 0, 1};
    std::size_t occupied{0};
    std::size_t factor{std::max(xSize_, ySize_)};
    for (int i = 0; i < 8; ++i) {
      for (int ftr = 1; ftr <= factor; ++ftr) {
        ColRow tmp{cr.x + x[i] * ftr, cr.y + y[i] * ftr};

        bool const bound_y{tmp.y >= 0 && tmp.y < ySize_};
        bool const bound_x{tmp.x >= 0 && tmp.x < xSize_};
        if (bound_x && bound_y) {

          //          std::cout << tmp << std::endl;
          if (in_[tmp.y].at(tmp.x) == '#') {
            occupied++;
            break;
          } else if (in_[tmp.y].at(tmp.x) == 'L') {
            break;
          }
        }
      }
    }
    return occupied;
  }

  [[nodiscard]] auto inline count_occupied_seats() const noexcept
      -> std::size_t {
    std::size_t ans{};
    std::for_each(in_.begin(), in_.end(), [&ans](auto const &line) {
      for (auto const &chr : line) {
        if (chr == '#') {
          ans++;
        }
      }
    });
    return ans;
  }

  auto inline print_map(std::size_t num) const noexcept -> void {
    std::cout << "********** " << num << " *********" << std::endl;
    for (auto const &lines : in_) {
      for (auto const &chars : lines) {
        std::cout << chars << " ";
      }
      std::cout << std::endl;
    }
  }

  auto task1() -> void {
    FUNCTIONCALL
    std::size_t num{}, ans{};
    bool still_changing_{true};

    while (still_changing_) {
      still_changing_ = false;
      std::vector<std::string> input{in_};
      for (auto &seat : seats_) {
        std::size_t cc{change_seat(seat)};
        if (in_[seat.y].at(seat.x) == 'L' && cc == 0) { // rule one
          input[seat.y].at(seat.x) = '#';
          still_changing_ = true;
        } else if (in_[seat.y].at(seat.x) == '#' && cc > 3) { // rule #2
          input[seat.y].at(seat.x) = 'L';
          still_changing_ = true;
        }
      }
      in_ = input;
      // print_map(++num);
    }
    ANSWER1(count_occupied_seats())
  }

  auto task2() -> void {
    FUNCTIONCALL
    in_ = clean_;
    std::size_t num{}, ans{};
    bool still_changing_{true};

    while (still_changing_) {
      still_changing_ = false;
      std::vector<std::string> input{in_};
      for (auto &seat : seats_) {
        std::size_t cc{change_seat_extended(seat)};
        if (in_[seat.y].at(seat.x) == 'L' && cc == 0) { // rule one
          input[seat.y].at(seat.x) = '#';
          still_changing_ = true;
        } else if (in_[seat.y].at(seat.x) == '#' && cc > 4) { // rule #2
          input[seat.y].at(seat.x) = 'L';
          still_changing_ = true;
        }
      }
      in_ = input;
      //      print_map(++num);
    }
    ANSWER2(count_occupied_seats())
  }

private:
  std::vector<ColRow> seats_;
  std::vector<T> in_;
  std::vector<T> clean_;
  std::size_t const ySize_;
  std::size_t const xSize_;
};
