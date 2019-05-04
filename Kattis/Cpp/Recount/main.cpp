#include <iostream>
#include <map>

// Recount

int main() {
  bool runOff = false;
  std::pair<std::string, int> lead = {"", 0};
  std::string name;
  std::map<std::string, int> recount;
  while (getline(std::cin, name)) {
    if (name == "***") {
      break;
    }
    auto search = recount.find(name);

    if (search->first == name) {
      recount[name] += 1;
    } else {
      recount.insert({name, 1});
    }

    if (recount[name] > lead.second) {
      lead = {name, recount[name]};
      runOff = false;
    } else if (recount[name] == lead.second) {
      runOff = true;
    }
  }

  if (runOff) { printf("Runoff!"); }
  else printf("%s", lead.first.c_str());
}