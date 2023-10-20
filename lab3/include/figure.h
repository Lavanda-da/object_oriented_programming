#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <string>
#include <cmath>

#define EPS 0.001

struct point{
    double x;
    double y;
    bool operator==(point right) {
        if (x == right.x && y == right.y) {
            return true;
        }
        return false;
    }
};

struct exeptionFailCreateFigure {};

class Figure
{
protected :
    Figure() = default;
    Figure(const std::initializer_list<double> &coords);
    Figure(const Figure& other);
    Figure(Figure&& other);
    virtual void update() = 0;

public :
    virtual ~Figure() = default;
    point center() const;
    virtual operator double() const = 0;
    // void operator=(const Figure& other);
    // void operator=(Figure&& other);
    friend std::ostream& operator<<(std::ostream&, const Figure&);
    friend std::istream& operator>>(std::istream&, Figure&);
    bool operator==(const Figure& other) const;
    // virtual bool check(point p1, point p2, point p3, point p4) const = 0;

protected :
    std::string typeOfFigure = "none";
    point *_array = nullptr;
};

#endif