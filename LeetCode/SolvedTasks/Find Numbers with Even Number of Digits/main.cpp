#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <cassert>
#include <numeric>


class Solution {
public:
    int findNumbers2(std::vector<int>& nums) {
        int counter = 0;
        std::for_each(std::cbegin(nums), std::cend(nums), [&counter](int num){
            if(std::to_string(num).size() % 2 == 0) {counter++; }
        });
        return counter;
    }

    int findNumbers(std::vector<int>& nums) {
        int counter = 0;
        counter = std::accumulate(std::cbegin(nums), std::cend(nums), 0,
                                  [](int & counter, int num){
            return counter + (std::to_string(num).size() % 2 == 0);
        });
        return counter;
    }
};

int main(){
    std::cout << "Find Numbers with Even Number of Digits" << std::endl;

    std::vector<int> vec1{12,345,2,6,7896};
    std::vector<int> vec2{555,901,482,1771};
    std::vector<int> vec3{1771, 2222, 3333, 333333};
    std::vector<int> vec4;
    Solution s;
    assert((static_cast<void>("Test 1"), s.findNumbers(vec1) == 2));
    assert((static_cast<void>("Test 2"), s.findNumbers(vec2) == 1));
    assert((static_cast<void>("Test 3"), s.findNumbers(vec3) == 4));
    assert((static_cast<void>("Test 4"), s.findNumbers(vec4) == 0));
}

