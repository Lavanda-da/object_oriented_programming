#ifndef RHOMB_H
#define RHOMB_H

#include "figure.h"

class Rhomb : public Figure
{
public:
    Rhomb() = default;
    Rhomb(const std::initializer_list<double> &coords);
    Rhomb(const Rhomb& other);
    Rhomb(Rhomb&& other);
    Rhomb(const Figure& other);
    Rhomb(Figure&& other);
    virtual ~Rhomb() = default;
    
public:
    virtual operator double() const override;
    bool operator==(const Rhomb& other) const;
    void operator=(const Rhomb& other);
    void operator=(Rhomb&& other);
    // virtual void operator=(const Figure& other) override;
    // virtual void operator=(Figure&& other) override;

	
private:
    double getDiag1() const;
    double getDiag2() const;
    double getSide() const;
    bool check(point p1, point p2, point p3, point p4);
    virtual void update() override;

private : 
    std::string typeOfFigure = "rhomb";
    double diag1 = getDiag1();
    double diag2 = getDiag2();
    double side = getSide();

};

#endif
