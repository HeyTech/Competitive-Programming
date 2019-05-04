#include <iostream>

// Heart Rate
int main() {
  int N, b;
  double p, pulse, abpm;
  std::cin >> N;
  while (N--) {
    std::cin >> b >> p;
    pulse = ((60.0* b) / p);
    abpm = 60.0 / p;
    printf("%0.4f %0.4f %0.4f\n", pulse-abpm, pulse , pulse + abpm);

  }

}

