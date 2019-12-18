#ifndef DAY14_H
#define DAY14_H

#include <string>
#include <vector>
#include <unordered_map>


struct reaction_item {
  reaction_item(std::string name, float qy): item_name{name}, quantity{qy} {}
  std::string item_name = "";
  float quantity = 0.0;
};


struct reaction {
  float quantity = 0.0;
  float ore_value = 0.0;
  bool in_ore = false;
  std::vector<reaction_item> recipe;
};



class day14{
public:
  day14();

  void task1();

  std::unordered_map<std::string,  reaction> reactions;
};

#endif // DAY14_H
