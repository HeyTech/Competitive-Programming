#include <iostream>
#include <cassert>


class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;
        do {
            product *= n%10;
            sum += n%10;
        } while ((n /= 10) > 0);
        return product-sum;
    }
};

int main(){
    std::cout << "Subtract the Product and Sum of Digits of an Integer" << std::endl;

    Solution s;
    assert((static_cast<void>("Test 1"), s.subtractProductAndSum(234) == 15));
    assert((static_cast<void>("Test 2"), s.subtractProductAndSum(4421) == 21));
    assert((static_cast<void>("Test 3"), s.subtractProductAndSum(1) == 0));
    assert((static_cast<void>("Test 3"), s.subtractProductAndSum(705) == -12));
}

