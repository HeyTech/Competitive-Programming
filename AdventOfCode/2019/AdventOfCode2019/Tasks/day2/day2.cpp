#include <iostream>
#include "day2.h"
#include "intcode.h"

day2::day2(){
  input_org = {1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,13,1,19,1,10,19,23,1,23,9,27,1,5,27,31,2,31,13,35,1,35,5,39,1,39,5,43,2,13,43,47,2,47,10,51,1,51,6,55,2,55,9,59,1,59,5,63,1,63,13,67,2,67,6,71,1,71,5,75,1,75,5,79,1,79,9,83,1,10,83,87,1,87,10,91,1,91,9,95,1,10,95,99,1,10,99,103,2,103,10,107,1,107,9,111,2,6,111,115,1,5,115,119,2,119,13,123,1,6,123,127,2,9,127,131,1,131,5,135,1,135,13,139,1,139,10,143,1,2,143,147,1,147,10,0,99,2,0,14,0};
  input_org[1] = 12;
  input_org[2] = 2;
}

static std::uint32_t perform_calculation(std::uint32_t a, std::uint32_t b, bool add_){
  return (add_) ? a+b : a*b;

}

std::uint32_t day2::task1(){
  //  std::cout << "welcome to day 2 task 1: " << input.size()<< std::endl;
  std::vector<uint32_t> input;
  copy(input_org.begin(), input_org.end(), back_inserter(input));

  for (std::uint32_t i{0}; input[i] != 99; i+=4){
      std::uint32_t p1 = input[i+1];
      std::uint32_t p2 = input[i+2];
      std::uint32_t loc = input[i+3];

      switch (static_cast<opcode>(input[i])) {
        case opcode::ADD : {
            input[loc] = perform_calculation(input[p1], input[p2], true);
            continue;
          }
        case opcode::MUL : {
            input[loc] = perform_calculation(input[p1], input[p2], false);
            continue;
          }
        case opcode::HALT : {
            break;
          }
        }
    }
  std::cout << input[0] << std::endl;
  return input[0];
}


void day2::task2(){
  std::cout << "welcome to day 2 task 2" << std::endl;
  [&]{
    for(std::uint32_t noun{0}; noun <= 99; noun++){
        for(std::uint32_t verb{0}; verb <= 99; verb++){
            input_org[1] = noun;
            input_org[2] = verb;
            if (task1() == 19690720){
                std::uint32_t val = (100 * noun + verb);
                std::cout <<"TASK 2: " << val << std::endl;
                return;
              }
          }
      }
  }();
}

