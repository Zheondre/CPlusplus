//  Copyright 2015 Zheondre Calcano
//  PS6
#include <map>
#include <exception>
#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "MarkovModel.hpp"

int main(int argc, char *argv[]) {
std::string a;
std::cin >> a;
MarkovModel temp(a, 2);
temp.gen("ag", 10);
std::cout << temp << std::endl;
}
