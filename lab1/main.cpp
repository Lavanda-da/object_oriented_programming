#include <iostream>
#include <string>
#include "convert.h"

int main() {
    int n;
    std::cin >> n;
    std::string s = convert(n);
    std::cout << s << std::endl;
    return 0;
}
