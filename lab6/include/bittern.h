#ifndef BITTERN_H
#define BITTERN_H

#include "npc.h"
#include "bear.h"
#include "muskrat.h"

class Bittern : public NPC
{
    public:
        Bittern(std::string name, int x, int y);
        Bittern(std::istream& is);
        virtual ~Bittern() = default;

        bool accept(NPC &visitor) override;
};

#endif