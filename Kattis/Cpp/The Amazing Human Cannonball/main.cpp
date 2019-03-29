#include <iostream>
#include <cmath>

int main() {
    float n, v0, x0, th, h1, h2;
    float t, y;
    const double g = 0.5 * 9.81;
    const double radToDeg = 3.14/180;

    std::cin >> n;
    while ((n--) > 0) {
        std::cin >> v0 >> th >> x0 >> h1 >> h2;
            t = x0 / (v0 * cos(th * radToDeg));
            y = (v0 * t * sin(th* radToDeg)) - (pow(t, 2) * g);
        if ( y+1 <= h2 && y-1 >= h1){
            std::cout << "Safe" << std::endl;
        } else {
            std::cout << "Not Safe" << std::endl;
        }
    }
}
