#ifndef MUSKRAT_H
#define MUSKRAT_H

#include "npc.h"
#include "bear.h"
#include "bittern.h"

class Muskrat : public NPC
{
    public:
        Muskrat(std::string name, int x, int y);
        Muskrat(std::istream& is);
        virtual ~Muskrat() = default;

        bool accept(NPC &visitor) override;
        bool visit(Bear &monster) override;
};

#endif