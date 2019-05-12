// https://open.kattis.com/problems/election2
#include <iostream>
#include <cstdint>
#include <map>
#include <string>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie();

  std::string name, party;
  std::uint16_t N;
  std::cin >> N;

  std::map<std::string, std::string> candidates;
  std::map<std::string, std::uint32_t> votes;

  while (N--) {
    std::getline(std::cin >> std::ws, name);
    std::getline(std::cin, party);
    candidates.emplace(name, party);
    votes.emplace(name, 0);
  }
  std::cin >> N;
  while (N--) {
    std::getline(std::cin >> std::ws, name);
    votes[name] += 1 ;
  }

  bool tie = false;
  N = 0; // used as max value
  for (auto it=votes.begin(); it!=votes.end(); ++it){
    if (N < it->second ){
      N = it->second;
      name = it->first;
      tie = false;
    }
    else if (N == it->second) {
      tie = true;
    }
  }
  printf("%s", (tie) ? "tie" : candidates[name].c_str());
}