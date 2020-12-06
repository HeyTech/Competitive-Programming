#pragma once
#include "aoc.h"

namespace aoc::read_input {

/*!
 * \brief                   This function read inputs from cin,
 *                          read each line and insert it into a given vector.
 * \param inputs[in, out]   vector to insert the cin into...
 */
auto each_line(std::vector<std::string> &inputs) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie();
  std::string line;

  while (std::getline(std::cin, line)) {
    inputs.push_back(line);
  }
}

/*!
 * \brief                   Read each line and wait until a delimiter show up
 * and break the cin. \param inputs[in,out]    Vector to insert the cin into
 * \param delimter[in]      Delimiter to break the cin and start a new input,
 * (empty line?) \param separator[in]     Separator to separate between combined
 * lines
 */
auto line_delimiter(std::vector<std::string> &inputs,
                    std::string const delimter, std::string const separator) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie();

  std::string line, line_cin;
  while (std::getline(std::cin, line_cin)) {
    if (line_cin != delimter) { // empty line, new pass will soon come..
      line.append(line_cin);
      line.append(separator);
    } else {
      inputs.push_back(line);
      line = "";
    }
  }
  inputs.push_back(line);
}
} // namespace aoc::read_input
