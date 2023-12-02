#pragma once

#include "npc.h"
#include "bittern.h"
#include "muskrat.h"

class Bear : public NPC 
{
    public:
        Bear(std::string name, int x, int y);
        Bear(std::istream& is);
        virtual ~Bear() = default;

        bool accept(NPC &visitor) override;
        bool visit(Bittern &monster) override;
        bool visit(Muskrat &monster) override;
};
