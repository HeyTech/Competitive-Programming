// https://open.kattis.com/problems/detaileddifferences
#include <iostream>

//Detailed Differences
int main() {
  std::string line1, line2;
  int n;
  std::cin >> n;
  while (n--) {
    std::cin >> line1 >> line2;
    printf("%s \n%s\n", line1.c_str(), line2.c_str());
    for (int i = 0; i < line1.length(); ++i) {
      printf("%c", (line1[i] == line2[i] ? '.' : '*'));
    }
    printf("\n");
  }
}
