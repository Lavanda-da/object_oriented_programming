#include "figure.h"

Figure::Figure(const std::initializer_list<double> &coords) {
    _array = new point[4];
    int n = coords.size();
    if (n != 8) {
        throw exeptionFailCreateFigure();
    }
    _array = new point[n / 2];
    int i = 0;
    for (double elem : coords) {
        if (i % 2 == 0) _array[i / 2].x = elem;
        else _array[i / 2].y = elem;
        ++i;
    }
}

Figure::Figure(const Figure& other) {
    _array = new point[4];
    for (int i = 0; i < 4; ++i) _array[i] = other._array[i];
    _array = other._array;
}

Figure::Figure(Figure&& other) {
    _array = new point[4];
    _array = other._array;
    other._array = nullptr;
}

point Figure::center() const {
    double sumX = 0, sumY = 0;
    for (int i = 0; i < 4; ++i) {
        sumX += _array[i].x;
        sumY += _array[i].y;
    }
    return (point{sumX / 4.0, sumY / 4.0});
}

// void Figure::operator=(const Figure& other) {
//     delete[] _array;
//     _array = nullptr;
//     _array = new point[4];
//     for (int i = 0; i < 4; ++i) _array[i] = other._array[i];
//     _array = other._array;
//     update();
// }

// void Figure::operator=(Figure&& other) {
//     delete[] _array;
//     _array = nullptr;
//     _array = new point[4];
//     _array = other._array;
//     other._array = nullptr;
//     update();
// }

std::ostream& operator<<(std::ostream& out, const Figure& other) {
    for (int i = 0; i < 4; ++i) {
        out << other._array[i].x << ' ' << other._array[i].y << '\n';
    }
    return out;
}

std::istream& operator>>(std::istream& in, Figure& other) {
    if (other._array != nullptr) {
        throw exeptionFailCreateFigure();
    }
    other._array = new point[4];
    for (int i = 0; i < 4; ++i) {
        in >> other._array[i].x >> other._array[i].y;
    }
    return in;
}

bool Figure::operator==(const Figure& other) const {
    return false;
}