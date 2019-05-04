#include <iostream>
#include <map>
#include <set>

// Problem E Not Amused
int main() {
  std::map<std::string, unsigned long> park;
  std::string action, name;
  unsigned long time;
  unsigned int count = 0;
  while (!std::cin.eof()) {
    std::cin >> action; // START
    if (action == "ENTER") {
      std::cin >> name >> time;
      auto search = park.find(name);
      if(search->first == name){
        park[name] = (time - search->second);
      }else{
      park.insert({name, time});
      }

    } else if (action == "EXIT") {
      std::cin >> name >> time;
      auto search = park.find(name);
      park[name] = (time - search->second);   // 710 - (700-15) make it negative
      //park.erase(name);
    } else if (action == "CLOSE") {
      for(const auto &[k, v] : park){
        printf("%s $%0.2f\n", k.c_str(), v * 0.1);
      }

      park.clear();
    } else {
      if(count > 0){ printf("\n"); }
      printf("Day %d\n", ++count);
    }
  }
  return 0;
}
