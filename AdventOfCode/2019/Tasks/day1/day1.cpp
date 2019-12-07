#include "day1.h"
#include <cstdint>
#include <iostream>
#include <cmath>

day1::day1(){

}

void day1::task1(){
  std::cout << "welcome to day 1 task 1" << std::endl;

  std::uint64_t sum = 0;
  std::int32_t tmp = 0;

  while(std::cin >> tmp){
      sum += static_cast<uint64_t>(std::floor(tmp/3)- 2);
    }
  std::cout << sum << std::endl;
}


void day1::task2(){
  std::cout << "welcome to day 1 task 2" << std::endl;
  std::ios_base::sync_with_stdio(false);
  std::cin.tie();

  std::uint64_t tot_sum = 0, tot_fuel = 0,  mass = 0;

  while(std::cin >> mass){
      tot_fuel = 0;
      do{
          mass = static_cast<uint64_t>((mass/3)- 2);
          tot_fuel += mass;
        }while(mass >= 6);
      tot_sum += tot_fuel;
    }
  std::cout << tot_sum << std::endl;
}
