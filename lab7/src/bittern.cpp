#include "../include/bittern.h"

Bittern::Bittern(std::string name, int x, int y) : NPC(BitternType, name, x, y) {}

Bittern::Bittern(std::istream& is) : NPC(BitternType, is) {}

int Bittern::getDistMove()
{
    return dist_move;
}

int Bittern::getDistFight()
{
    return dist_fight;
}

bool Bittern::accept(std::shared_ptr<NPC> visitor) 
{
    return visitor->visit(std::shared_ptr<Bittern>(this,[](Bittern*){}));
}