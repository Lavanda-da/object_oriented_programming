#include "../include/muskrat.h"

Muskrat::Muskrat(std::string name, int x, int y) : NPC(MuskratType, name, x, y) {}

Muskrat::Muskrat(std::istream& is) : NPC(MuskratType, is) {}

bool Muskrat::accept(NPC &visitor) 
{
    return visitor.visit(*this);
}

bool Muskrat::visit(Bear &monster)
{
    notify(*this, monster);
    return true;
}
