#include <iostream>
#include <cassert>
#include <vector>
#include <numeric>
#include <iterator>
#include <regex>
#include <string>

class MyAssert{
public:
    template<typename CALL, typename EXPEXCTED>
    void my_assert(CALL call, EXPEXCTED expected, std::string msg=""){
        std::cout << "Test " << ++test_n
                  << ((msg.size() > 0) ? (" (" + msg + ")") : "")
                  << " \tOutput: " << ((call) ? "True" : "False")
                  << " \texpected: " << ((expected) ? "True" : "False")
                  << std::endl;
        assert(call == expected );
    }
    std::uint32_t test_n = 0;
};

using namespace std;
class Solution {
public:
    // O(N)
    bool isOneBitCharacter2(vector<int>& bits) {
        vector<int>::size_type i = 0, size = bits.size();
        for(; i < size; i++){
            if(bits[i]){
                i++;
                if(i >= size-1) return false;
                continue;
            }
        }
        return true;
    }


    // Regex
    bool isOneBitCharacter(std::vector<int>& bits) {
        std::vector<int>::size_type i = 0, size = bits.size();
        bool pp = true;
        while(i < size){
            switch (bits[i]) {
            case 1 : i++; pp = false; break;
            case 0 : pp = true; break;
            }
            i++;
        }
        return pp;
    }
};

int main(){
    std::cout << "1-bit and 2-bit Characters" << std::endl;

    Solution s;
    MyAssert ma;


    std::vector<int> odd1 {0, 0, 0};
    std::vector<int> odd2 {0, 1, 0};
    std::vector<int> odd3 {0, 1, 1};
    std::vector<int> odd4 {1, 0, 0};
    std::vector<int> odd5 {1, 1, 0};
    ma.my_assert(s.isOneBitCharacter(odd1), true, "odd1");
    ma.my_assert(s.isOneBitCharacter(odd2), false ,"odd2");
    ma.my_assert(s.isOneBitCharacter(odd3), false, "odd3");
    ma.my_assert(s.isOneBitCharacter(odd4), true, "odd4");
    ma.my_assert(s.isOneBitCharacter(odd5), true, "odd5");


    std::vector<int> arr6 {0};
    std::vector<int> arr8 {1, 1};
    std::vector<int> arr2 {0, 0};
    ma.my_assert(s.isOneBitCharacter(arr2), true);
    ma.my_assert(s.isOneBitCharacter(arr6), true);
    ma.my_assert(s.isOneBitCharacter(arr8), false);

    std::vector<int> even1 {0, 0, 0, 0};
    std::vector<int> even2 {0, 0, 1, 0};
    std::vector<int> even3 {0, 0, 1, 1};
    std::vector<int> even4 {0, 1, 0, 0};
    std::vector<int> even5 {0, 1, 1, 0};
    std::vector<int> even6 {0, 1, 1, 1}; // error
    std::vector<int> even7 {1, 0, 0, 0};
    std::vector<int> even8 {1, 0, 1, 0};
    std::vector<int> even9 {1, 0, 1, 1};
    std::vector<int> even10 {1, 1, 0, 0};
    std::vector<int> even11 {1, 1, 1, 0};
    std::vector<int> even12 {1, 1, 1, 1};


    ma.my_assert(s.isOneBitCharacter(even1), true, "even1");
    ma.my_assert(s.isOneBitCharacter(even2), false, "even2");
    ma.my_assert(s.isOneBitCharacter(even3), false, "even3");
    ma.my_assert(s.isOneBitCharacter(even4), true, "even4");
    ma.my_assert(s.isOneBitCharacter(even5), true, "even5");
    ma.my_assert(s.isOneBitCharacter(even6), false, "even6");
    ma.my_assert(s.isOneBitCharacter(even7), true, "even7");
    ma.my_assert(s.isOneBitCharacter(even8), false, "even8");
    ma.my_assert(s.isOneBitCharacter(even9), false, "even9");
    ma.my_assert(s.isOneBitCharacter(even10), true, "even10");
    ma.my_assert(s.isOneBitCharacter(even11), false, "even11");
    ma.my_assert(s.isOneBitCharacter(even12), false, "even12");

}


