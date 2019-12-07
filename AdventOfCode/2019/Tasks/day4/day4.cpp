#include "day4.h"
#include <iostream>
#include <vector>
#include <algorithm>

day4::day4(){
  from_count = 156218 - 1;
  to_count = 652527;
}

void day4::task1(){
  std::cout << "Welcome to " << __PRETTY_FUNCTION__ << std::endl;

  uint32_t dig1, dig2, dig3, dig4, dig5, dig6, tmp = from_count, count = 0;

  while(tmp++ <= to_count){
      dig6 = (tmp) % 10;
      dig5 = (tmp/10) % 10;
      if(dig6 < dig5) continue;
      dig4 = (tmp/100) % 10;
      if(dig5 < dig4) continue;
      dig3 = (tmp/1000) % 10;
      if(dig4 < dig3) continue;
      dig2 = (tmp/10000) % 10;
      if(dig3 < dig2) continue;
      dig1 = (tmp/100000) % 10;
      if(dig2 < dig1) continue;

      if(dig1 == dig2 | dig2 == dig3 | dig3 == dig4 | dig4 == dig5 | dig5 == dig6){
          count++;
        }
      continue;
    }
  std::cout << count << std::endl;
}




std::vector<uint32_t> get_vector_from_int(uint32_t& from_count){
  std::vector<uint32_t> int2vec;
  int2vec.push_back((from_count/100000) % 10);
  int2vec.push_back((from_count/10000) % 10);
  int2vec.push_back((from_count/1000) % 10);
  int2vec.push_back((from_count/100) % 10);
  int2vec.push_back((from_count/10) % 10);
  int2vec.push_back((from_count) % 10);
  return int2vec;
}

void day4::task1_algorithms(){
  std::cout << "Welcome to " << __PRETTY_FUNCTION__ << std::endl;

  uint32_t count = 0;
  while(from_count++ <= to_count){
      std::vector<uint32_t> int2vec = get_vector_from_int(from_count);
      if(std::is_sorted(std::cbegin(int2vec), std::cend(int2vec)) && std::adjacent_find(std::cbegin(int2vec), std::cend(int2vec)) != std::end(int2vec)) {
          count++;
        }
    }
  std::cout << count << std::endl;
}





void day4::task2(){
  std::cout << "Welcome to " << __PRETTY_FUNCTION__ << std::endl;

  uint32_t count = 0;
  while(from_count++ <= to_count){
      std::vector<uint32_t> int2vec = get_vector_from_int(from_count);
      if(std::is_sorted(std::cbegin(int2vec), std::cend(int2vec))){
          [&]{
            for(const auto ele : int2vec){
                std::uint32_t freq = std::count(int2vec.begin(), int2vec.end(), ele);
                if(freq == 2){count++; return;}
              }
          }();
        }
    }
  std::cout << count << std::endl;
}
