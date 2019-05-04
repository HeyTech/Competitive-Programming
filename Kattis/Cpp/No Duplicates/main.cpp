// https://open.kattis.com/problems/nodup
#include <iostream>
#include <set>
#define Log(str){printf("%s\n", str);}

int main() {
  std::string temp;
  std::set<std::string> set;
  while (std::cin >> temp){
    auto ret = set.insert(temp);
    if(!ret.second){ // Duplicate exist
      Log("no")
      return 0;
    }
  }
  Log("yes")
}