#include <iostream>
#include "three.h"


int main(){

    try {
        Three t1 {'2', '1', '1'};
        Three t2 {'0'};
        Three t3 {'2', '0'};

        std::string s;
        t1.convertToString(s);
        t1.print(std::cout) << std::endl;
        std::cout << s << std::endl;

        t1.sum(t2).print(std::cout) << std::endl;

        t1.subtraction(t3).print(std::cout) << std::endl;

    } catch(std::exception &ex){
        std::cerr << "exception: " << ex.what() << std::endl;
    }

    return 1;
}
