#include "../include/muskrat.h"

Muskrat::Muskrat(std::string name, int x, int y) : NPC(MuskratType, name, x, y) {}

Muskrat::Muskrat(std::istream& is) : NPC(MuskratType, is) {}

int Muskrat::getDistMove()
{
    return dist_move;
}

int Muskrat::getDistFight()
{
    return dist_fight;
}

bool Muskrat::accept(std::shared_ptr<NPC> visitor) 
{
    return visitor->visit(std::shared_ptr<Muskrat>(this,[](Muskrat*){}));
}

bool Muskrat::visit(std::shared_ptr<Bear> monster)
{
    if (win()) 
    {
        notify(std::shared_ptr<Muskrat>(this,[](Muskrat*){}), monster);
        return true;
    }
    return false;
}