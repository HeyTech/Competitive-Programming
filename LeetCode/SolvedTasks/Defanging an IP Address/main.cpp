#include <iostream>
#include <cassert>
#include <regex>

class Solution {
public:
    std::string defangIPaddr(std::string address) {
        return std::regex_replace(address, std::regex("[.]"), "[$&]");
    }
};



int main(){
    std::cout << "Defanging an ip Address" << std::endl;

    Solution s;
    assert((static_cast<void>("Test 1"), s.defangIPaddr("1.1.1.1") == "1[.]1[.]1[.]1"));
    assert((static_cast<void>("Test 2"), s.defangIPaddr("255.100.50.0") == "255[.]100[.]50[.]0"));
}
