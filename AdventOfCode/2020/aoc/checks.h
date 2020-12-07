#pragma once
#include "aoc.h"

#include <algorithm>
namespace aoc::checks {

//template <typename T, std::enable_if_t<std::is_arithmetic<T>::value>>
template <typename T>
auto inline digit_between_values(T lowest, T highest, T value) -> bool {
  return (lowest <= value && value <= highest);
}

auto inline is_digits(const std::string &str) -> bool{
  return std::all_of(str.begin(), str.end(), ::isdigit);
}

} // namespace aoc::checks
