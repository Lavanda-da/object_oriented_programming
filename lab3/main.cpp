#include <iostream>
#include "figure.h"
#include "rectangle.h"
#include "rhomb.h"
#include "trapezium.h"

int main() {
    try {
        // Rectangle r{2, 0, 4, 2, 3, 3, 1, 1};
        // Rectangle r2 = r;
        Trapezium tr{1, 0, 5, 0, 4, 2, 2, 2};
        // Trapezium tr2(tr);
        // std::cout << (tr == r) << '\n';
        // std::cout << r2;
        // std::cout << (r == r2) << '\n';
    }
    catch (const exeptionFailCreateFigure &ex) {
        std::cout << "ex1\n";
    }
    // std::cout << 1;
}