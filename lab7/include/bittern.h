#pragma once

#include "npc.h"
#include "bear.h"
#include "muskrat.h"

class Bittern : public NPC
{
    public:
        Bittern(std::string name, int x, int y);
        Bittern(std::istream& is);
        virtual ~Bittern() = default;

        int getDistMove() override;
        int getDistFight() override;

        bool accept(std::shared_ptr<NPC> visitor) override;

    protected:
        int dist_move = 50;
        int dist_fight = 10;
};
