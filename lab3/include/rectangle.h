#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"
#include "rhomb.h"

class Rectangle : public Figure
{
public:
    Rectangle() = default;
    Rectangle(const std::initializer_list<double> &coords);
    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other);
    Rectangle(const Figure& other);
    Rectangle(Figure&& other);
    virtual ~Rectangle() = default;
    
public:
    virtual operator double() const override;
    bool operator==(const Rectangle& other) const;
    void operator=(const Rectangle& other);
    void operator=(Rectangle&& other);

	
private:
    double getWidth() const;
    double getHeight() const;
    bool check(point p1, point p2, point p3, point p4);
    virtual void update() override;

private : 
    std::string typeOfFigure = "rect";
    double width = getWidth();
    double height = getHeight();

};

#endif
