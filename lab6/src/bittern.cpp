#include "../include/bittern.h"

Bittern::Bittern(std::string name, int x, int y) : NPC(BitternType, name, x, y) {}

Bittern::Bittern(std::istream& is) : NPC(BitternType, is) {}

bool Bittern::accept(NPC &visitor) 
{
    return visitor.visit(*this);
}
