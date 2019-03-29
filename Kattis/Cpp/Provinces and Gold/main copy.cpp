#include <iostream>
#include <cmath>
#include <vector>

int main() {
    int g, s, c;
    std::cin >> g >> s >> c;
    int buyPower = ((g * 3) + (s * 2) + (c * 1));


    if(8 <= buyPower) {
        std::cout << "Province or Gold" << std::endl;
    }else if(6 <= buyPower){
        std::cout << "Duchy or Gold" << std::endl;
    }else if(5 <= buyPower){
        std::cout << "Duchy or Silver" << std::endl;
    }else if(3 <= buyPower){
        std::cout << "Estate or Silver" << std::endl;
    }else if(2 <= buyPower){
        std::cout << "Estate or Copper" << std::endl;
    }else{
        std::cout << "Copper" << std::endl;
    }


    /* // Version 1
    std::string output = "";
    if(8 <= buyPower) {
        output = "Province";
    }else if(5 <= buyPower){
        output = "Duchy";
    }else if(2 <= buyPower){
        output = "Estate";
    }

    if (output.length() > 1) output+= " or ";

    if(6 <= buyPower) {
        output += "Gold";
    }else if(3 <= buyPower){
        output += "Silver";
    }else if(0 <= buyPower){
        output += "Copper";
    }
    std::cout << output << std::endl;
     */
}
