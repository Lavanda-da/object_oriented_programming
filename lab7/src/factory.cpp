#include "../include/factory.h"

std::shared_ptr<NPC> factory(NpcType type, std::string name, int x, int y)
{
    switch (type)
    {
        case BearType :
            return std::make_shared<Bear>(name, x, y);
            break;
        case BitternType :
            return std::make_shared<Bittern>(name, x, y);
            break;
        case MuskratType :
            return std::make_shared<Muskrat>(name, x, y);
            break;
        default:
            std::cout << "unexpected type : " << type << std::endl;
            break;
    }
    return nullptr;
}

std::shared_ptr<NPC> factory(std::istream &is)
{
    int type;
    is >> type;
    switch (type)
    {
        case BearType :
            return std::make_shared<Bear>(is);
            break;
        case BitternType :
            return std::make_shared<Bittern>(is);
            break;
        case MuskratType :
            return std::make_shared<Muskrat>(is);
            break;
        default:
            std::cout << "unexpected type : " << type << std::endl;
            break;
    }
    return nullptr;
}