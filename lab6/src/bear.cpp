#include "../include/bear.h"

Bear::Bear(std::string name, int x, int y) : NPC(BearType, name, x, y) {}

Bear::Bear(std::istream &is) : NPC(BearType, is) {}

bool Bear::accept(NPC &visitor) 
{
    return visitor.visit(*this);
}

bool Bear::visit(Bittern &monster) 
{
    notify(*this, monster);
    return true;
}

bool Bear::visit(Muskrat &monster) 
{
    notify(*this, monster);
    return true;
}
