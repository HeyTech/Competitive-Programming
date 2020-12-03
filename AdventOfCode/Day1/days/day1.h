#include <iostream>
#include <vector>
#include <algorithm>


class Day1 {
 public:
  void task1();
};

void Day1::task1(){
  std::cout << "welcome to day 1 task 1" << std::endl;
  std::ios_base::sync_with_stdio(false);
  std::cin.tie();

  std::uint32_t ints = 0;
  std::vector<std::uint32_t> inputs;

  while(std::cin >> ints){
    inputs.push_back(static_cast<size_t>(ints));
  }
  std::sort(inputs.begin(), inputs.end());
  for (auto i: inputs)
    std::cout << i << std::endl;


  for( auto i : inputs) {
    for (auto j : inputs) {
      for (auto k: inputs) {
        std::size_t const sum{i +j +k};
        if (sum == 2020) {
          std::cout << "yeaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaooooooooooooooooooooooo " << i*j*k << "  " << sum
                    << std::endl;
        }
      }
    }
  }

}


