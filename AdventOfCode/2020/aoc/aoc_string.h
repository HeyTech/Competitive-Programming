#pragma once
#include <string>

namespace aoc::string {

/*!
 * \brief                       This function repeat the string num times.
 * \param input[in]             String to copy from
 * \param output[in, out]       String to append to
 * \param num                   Number of times to repeat input into output.
 */
auto inline repeat_string(std::string const &input, std::string &output,
                          std::size_t num) {
  for (int i = 0; i < num; ++i) {
    output.append(input);
  }
}

/*!
 * \brief                       This function repeat the string num times.
 * \param output[in, out]       String to append to
 * \param num                   Number of times to repeat output input itself.
 */
auto inline repeat_string(std::string &output, std::size_t num) -> void {
  std::string const input{output};
  aoc::string::repeat_string(input, output, num);
}
} // namespace aoc::string