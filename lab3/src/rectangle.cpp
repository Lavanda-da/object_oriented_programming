#include "rectangle.h"

bool Rectangle::check(point coord1, point coord2, point coord3, point coord4) {
    if (coord1 == coord2 || coord1 == coord3 || coord1 == coord4 ||
        coord2 == coord3 || coord2 == coord4 || coord3 == coord4) {
            return false;
    }
    double diag1 = sqrt(pow(coord1.x - coord3.x, 2) + pow(coord1.y - coord3.y, 2));
    double diag2 = sqrt(pow(coord2.x - coord4.x, 2) + pow(coord2.y - coord4.y, 2));
    if (abs((coord1.x - coord2.x)-(coord4.x - coord3.x)) < EPS && 
        abs((coord1.y - coord2.y)-(coord4.y - coord3.y)) < EPS &&
        abs(diag1 - diag2) < EPS &&
        diag1 > sqrt(pow(coord1.x - coord4.x, 2) + pow(coord1.y - coord4.y, 2)) && 
        diag1 > sqrt(pow(coord1.x - coord2.x, 2) + pow(coord1.y - coord2.y, 2))) {
            return true;
    }
    return false;
}

Rectangle::Rectangle(const std::initializer_list<double> &coords) : Figure(coords) {
    auto it = coords.begin();
    point coord1{*it, *(++it)}, coord2{*(++it), *(++it)}, coord3{*(++it), *(++it)}, coord4{*(++it), *(++it)};
    if (!check(coord1, coord2, coord3, coord4)) {
            throw exeptionFailCreateFigure();
    }
}

Rectangle::Rectangle(const Rectangle& other) : Figure(other) {}

Rectangle::Rectangle(Rectangle&& other) : Figure(other) {}

Rectangle::Rectangle(const Figure& other) : Figure(other) {
    // if (typeOfFigure != "rect") {
    //     throw exeptionFailCreateFigure();
    // }
}

Rectangle::Rectangle(Figure&& other) : Figure(other) {
    // if (typeOfFigure != "rect") {
    //     throw exeptionFailCreateFigure();
    // }
}

Rectangle::operator double() const {
    return (double(width * height));
}

bool Rectangle::operator==(const Rectangle& other) const {
    if ((abs(width - other.width) < EPS && abs(height - other.height) < EPS) ||
        (abs(width - other.height) < EPS && abs(height - other.width) < EPS)) {
            return true;
    }
    return false;
}

void Rectangle::operator=(const Rectangle& other) {
    delete[] _array;
    _array = nullptr;
    _array = new point[4];
    for (int i = 0; i < 4; ++i) _array[i] = other._array[i];
    _array = other._array;
    update();
}

void Rectangle::operator=(Rectangle&& other) {
    delete[] _array;
    _array = nullptr;
    _array = new point[4];
    _array = other._array;
    other._array = nullptr;
    update();
}

double Rectangle::getWidth() const {
    if (_array != nullptr) {
        double deltaX = _array[0].x - _array[1].x;
        double deltaY = _array[0].y - _array[1].y;
        double width = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
        return width;
    }
    return 0;
}

double Rectangle::getHeight() const {
    if (_array != nullptr) {
        double deltaX = _array[2].x - _array[1].x;
        double deltaY = _array[2].y - _array[1].y;
        double height = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
        return height;
    }
    return 0;
}

void Rectangle::update() {
    typeOfFigure = "rect";
    width = getWidth();
    height = getHeight();
}
