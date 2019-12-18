#include "day14.h"
#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <cstdlib>


day14::day14(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie();

  std::string line, eng, quantity, item_name;
  while (std::getline(std::cin, line) && !line.empty()) {
      line = std::regex_replace(line, std::regex(","), "");
      std::istringstream ss (line);
      while (ss >> quantity) {
          reaction rec;
          if(quantity == "=>"){
              ss >> quantity >> item_name;
              //              std::cout << "-> quantity: '" << quantity << "' item: '" << item_name  << "'"<< std::endl;
              rec.quantity = std::stof(quantity, 0);
              reactions[item_name] = rec;
            }
          else{
              ss >> item_name;
              //              std::cout << "quantity: '" << quantity << "' item: '" << item_name  << "'"<< std::endl;
              rec.recipe.emplace_back(item_name, std::stof(quantity, 0));
            }
        }
//      std::cout << std::endl;
    }
}



void day14::task1(){
  std::cout << "Welcome to " << __PRETTY_FUNCTION__ << std::endl;
}
