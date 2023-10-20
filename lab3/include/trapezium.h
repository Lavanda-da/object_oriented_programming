#ifndef TRAPEZIUM_H
#define TRAPEZIUM_H

#include "figure.h"

class Trapezium : public Figure
{
public:
    Trapezium() = default;
    Trapezium(const std::initializer_list<double> &coords);
    Trapezium(const Trapezium& other);
    Trapezium(Trapezium&& other);
    Trapezium(const Figure& other);
    Trapezium(Figure&& other);
    virtual ~Trapezium() = default;
    
public:
    virtual operator double() const override;
    bool operator==(const Trapezium& other) const;
    void operator=(const Trapezium& other);
    void operator=(Trapezium&& other);
    // virtual void operator=(const Figure& other) override;
    // virtual void operator=(Figure&& other) override;

	
private:
    bool check(point p1, point p2, point p3, point p4);
    virtual void update() override;

private : 
    std::string typeOfFigure = "trap";
    double a;
    double b;
    double height;

};

#endif
