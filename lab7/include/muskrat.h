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

        int getDistMove() override;
        int getDistFight() override;

        bool accept(std::shared_ptr<NPC> visitor) override;
        bool visit(std::shared_ptr<Bear> monster) override;        

    protected:
        int dist_move = 5;
        int dist_fight = 20;
};

#endif