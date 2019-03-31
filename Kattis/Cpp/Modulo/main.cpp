#include <iostream>
#include <bitset>
// #include <set>



int main(){
  std::bitset<42> uni;
  int A;
  int N = 10;
  while (N-- > 0){
    std::cin >> A;
    uni.set(A%42);
  }
  std::cout << uni.count();
  return 0;
}


// Problem B: Modulo
/* int version1(){
  std::set<int> uni;

  int A;
  int N = 10;
  while (N-- > 0){
    std::cin >> A;
    uni.insert(A%42);
  }
  std::cout << uni.size();
}
*/

