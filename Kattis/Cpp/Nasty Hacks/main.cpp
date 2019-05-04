#include <iostream>

//Problem D Nasty Hacks
int main(){
  unsigned int n, c;
  signed int r, e, diff;

  std::cin >> n;
  while (n-- > 0){
    std::cin >> r >> e >> c;
    diff = (e-c);
    (diff>r) ? printf("advertise\n") : (diff==r) ? printf("does not matter\n") : printf("do not advertise\n");
  }
}


