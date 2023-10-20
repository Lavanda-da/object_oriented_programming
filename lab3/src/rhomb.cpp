#include "rhomb.h"

bool Rhomb::check(point coord1, point coord2, point coord3, point coord4) {
    if (coord1 == coord2 || coord1 == coord3 || coord1 == coord4 ||
        coord2 == coord3 || coord2 == coord4 || coord3 == coord4) {
            return false;
    }
    double _diag1 = sqrt(pow(coord1.x - coord3.x, 2) + pow(coord1.y - coord3.y, 2));
    double _diag2 = sqrt(pow(coord2.x - coord4.x, 2) + pow(coord2.y - coord4.y, 2));
    double side1 = sqrt(pow(coord1.x - coord2.x, 2) + pow(coord1.y - coord2.y, 2));
    double side2 = sqrt(pow(coord2.x - coord3.x, 2) + pow(coord2.y - coord3.y, 2));
    double side3 = sqrt(pow(coord4.x - coord3.x, 2) + pow(coord4.y - coord3.y, 2));
    double side4 = sqrt(pow(coord1.x - coord4.x, 2) + pow(coord1.y - coord4.y, 2));
    if (abs(side1 - side2) < EPS && abs(side3 - side2) < EPS &&
        abs(side3 - side4) < EPS && abs(side1 - side4) < EPS && 
        _diag1 > sqrt(pow(coord1.x - coord4.x, 2) + pow(coord1.y - coord4.y, 2)) && 
        _diag1 > sqrt(pow(coord1.x - coord2.x, 2) + pow(coord1.y - coord2.y, 2))) {
            return true;
    }
    return false;
}

Rhomb::Rhomb(const std::initializer_list<double> &coords) : Figure(coords) {
    auto it = coords.begin();
    point coord1{*it, *(++it)}, coord2{*(++it), *(++it)}, coord3{*(++it), *(++it)}, coord4{*(++it), *(++it)};
    if (!check(coord1, coord2, coord3, coord4)) {
            throw exeptionFailCreateFigure();
    }
}

Rhomb::Rhomb(const Rhomb& other) : Figure(other) {}

Rhomb::Rhomb(Rhomb&& other) : Figure(other) {}

Rhomb::Rhomb(const Figure& other) : Figure(other) {
    if (typeOfFigure != "rhomb") {
        throw exeptionFailCreateFigure();
    }
}

Rhomb::Rhomb(Figure&& other) : Figure(other) {
    if (typeOfFigure != "rhomb") {
        throw exeptionFailCreateFigure();
    }
}

Rhomb::operator double() const {
    return (diag1 * diag2 / 2.0);
}

bool Rhomb::operator==(const Rhomb& other) const {
    if (abs(side - other.side) < EPS) {
            return true;
    }
    return false;
}

void Rhomb::operator=(const Rhomb& other) {
    delete[] _array;
    _array = nullptr;
    _array = new point[4];
    for (int i = 0; i < 4; ++i) _array[i] = other._array[i];
    _array = other._array;
    update();
}

void Rhomb::operator=(Rhomb&& other) {
    delete[] _array;
    _array = nullptr;
    _array = new point[4];
    _array = other._array;
    other._array = nullptr;
    update();
}

double Rhomb::getDiag1() const {
    if (_array != nullptr) {
        double deltaX = _array[0].x - _array[2].x;
        double deltaY = _array[0].y - _array[2].y;
        double diag1 = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
        return diag1;
    }
    return 0;
}

double Rhomb::getDiag2() const {
    if (_array != nullptr) {
        double deltaX = _array[3].x - _array[1].x;
        double deltaY = _array[3].y - _array[1].y;
        double height = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
        return diag2;
    }
    return 0;
}

double Rhomb::getSide() const {
    if (_array != nullptr) {
        return sqrt(pow(_array[0].x - _array[1].x, 2) + pow(_array[0].y - _array[1].y, 2));
    }
    return 0;
}

void Rhomb::update() {
    typeOfFigure = "rhomb";
    diag1 = getDiag1();
    diag2 = getDiag2();
    side = getSide();
}
