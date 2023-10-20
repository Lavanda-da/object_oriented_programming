#include "trapezium.h"

bool Trapezium::check(point coord1, point coord2, point coord3, point coord4) {
    if (coord1 == coord2 || coord1 == coord3 || coord1 == coord4 ||
        coord2 == coord3 || coord2 == coord4 || coord3 == coord4) {
            return false;
    }
    double _diag1 = sqrt(pow(coord1.x - coord3.x, 2) + pow(coord1.y - coord3.y, 2));
    double _diag2 = sqrt(pow(coord2.x - coord4.x, 2) + pow(coord2.y - coord4.y, 2));
    if (((abs((coord1.x - coord2.x) / (coord1.y - coord2.y) - (coord4.x - coord3.x) / (coord4.y - coord3.y)) < EPS &&
        sqrt(pow(coord2.x - coord3.x, 2) + pow(coord2.y - coord3.y, 2)) - sqrt(pow(coord1.x - coord4.x, 2) + pow(coord1.y - coord4.y, 2)) < EPS) || 
        (abs((coord2.x - coord3.x) / (coord2.y - coord3.y) - (coord1.x - coord4.x) / (coord1.y - coord4.y)) < EPS &&
        sqrt(pow(coord2.x - coord1.x, 2) + pow(coord2.y - coord1.y, 2)) - sqrt(pow(coord3.x - coord4.x, 2) + pow(coord3.y - coord4.y, 2)) < EPS)) &&
        _diag1 > sqrt(pow(coord1.x - coord4.x, 2) + pow(coord1.y - coord4.y, 2)) && 
        _diag1 > sqrt(pow(coord1.x - coord2.x, 2) + pow(coord1.y - coord2.y, 2))) {
            return true;
    }
    return false;
}

Trapezium::Trapezium(const std::initializer_list<double> &coords) : Figure(coords) {
    auto it = coords.begin();
    point coord1{*it, *(++it)}, coord2{*(++it), *(++it)}, coord3{*(++it), *(++it)}, coord4{*(++it), *(++it)};
    if (!check(coord1, coord2, coord3, coord4)) {
            throw exeptionFailCreateFigure();
    }
    update();
}

Trapezium::Trapezium(const Trapezium& other) : Figure(other) {
    update();
}

Trapezium::Trapezium(Trapezium&& other) : Figure(other) {
    update();
}

Trapezium::Trapezium(const Figure& other) : Figure(other) {
    if (typeOfFigure != "trap") {
        throw exeptionFailCreateFigure();
    }
    update();
}

Trapezium::Trapezium(Figure&& other) : Figure(other) {
    if (typeOfFigure != "trap") {
        throw exeptionFailCreateFigure();
    }
    update();
}

Trapezium::operator double() const {
    return ((a + b) / 2.0 * height);
}

bool Trapezium::operator==(const Trapezium& other) const {
    if ((abs(a - other.a) < EPS && abs(height - other.height) < EPS) && (abs(b - other.b) < EPS)) {
            return true;
    }
    return false;
}

void Trapezium::operator=(const Trapezium& other) {
    delete[] _array;
    _array = nullptr;
    _array = new point[4];
    for (int i = 0; i < 4; ++i) _array[i] = other._array[i];
    _array = other._array;
    update();
}

void Trapezium::operator=(Trapezium&& other) {
    delete[] _array;
    _array = nullptr;
    _array = new point[4];
    _array = other._array;
    other._array = nullptr;
    update();
}

void Trapezium::update() {
    typeOfFigure = "trap";
    if (_array != nullptr) {
        if (sqrt(pow(_array[0].x - _array[1].x, 2) + pow(_array[0].y - _array[1].y, 2)) - sqrt(pow(_array[2].x - _array[3].x, 2) + pow(_array[2].y - _array[3].y, 2)) < EPS) {
            a = sqrt(pow(_array[2].x - _array[1].x, 2) + pow(_array[2].y - _array[1].y, 2));
            b = sqrt(pow(_array[0].x - _array[3].x, 2) + pow(_array[0].y - _array[3].y, 2));
            height = sqrt(pow(_array[0].x - _array[1].x, 2) + pow(_array[0].y - _array[1].y, 2) - pow((b - a) / 2.0, 2));
        } else {
            a = sqrt(pow(_array[0].x - _array[1].x, 2) + pow(_array[0].y - _array[1].y, 2));
            b = sqrt(pow(_array[2].x - _array[3].x, 2) + pow(_array[2].y - _array[3].y, 2));
            height = sqrt(pow(_array[2].x - _array[1].x, 2) + pow(_array[2].y - _array[1].y, 2) - pow((b - a) / 2.0, 2));
        }
    }
}

