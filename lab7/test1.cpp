#include <gtest/gtest.h>
#include "include/declaration.h"
#include "include/npc.h"
#include "include/bear.h"
#include "include/bittern.h"
#include "include/muskrat.h"
#include "include/factory.h"
#include "include/observerConsole.h"
#include "include/observerFile.h"

TEST(Test_Bear, Constr)
{
    std::string name = "asd";
    Bear bear{name, 1, 1};
    EXPECT_TRUE(bear.getName() == name && bear.getType() == "BearType");
}

TEST(Test_Bear, FightBear)
{
    std::string name = "asd";
    std::shared_ptr<Bear> bear1 = std::make_shared<Bear>(name, 1, 1);
    std::shared_ptr<Bear> bear2 = std::make_shared<Bear>(name, 1, 2);
    EXPECT_TRUE(bear1->accept(bear2) == false && bear2->accept(bear1) == false);
}

TEST(Test_Bear, FightBittern)
{
    std::string name = "asd";
    std::shared_ptr<Bear> bear = std::make_shared<Bear>(name, 1, 1);
    std::shared_ptr<Bittern> bittern = std::make_shared<Bittern>(name, 1, 2);
    EXPECT_TRUE(bittern->accept(bear) == true);
}

TEST(Test_Bear, FightMuskrat)
{
    std::string name = "asd";
    std::shared_ptr<Bear> bear = std::make_shared<Bear>(name, 1, 1);
    std::shared_ptr<Muskrat> muskrat = std::make_shared<Muskrat>(name, 1, 2);
    EXPECT_TRUE(muskrat->accept(bear) == true);
}

TEST(Test_Bittern, Constr)
{
    std::string name = "asd";
    std::shared_ptr<Bittern> bittern = std::make_shared<Bittern>(name, 1, 2);
    EXPECT_TRUE(bittern->getName() == name && bittern->getType() == "BitternType");
}

TEST(Test_Bittern, FightBittern)
{
    std::string name = "asd";
    std::shared_ptr<Bittern> bittern1 = std::make_shared<Bittern>(name, 1, 1);
    std::shared_ptr<Bittern> bittern2 = std::make_shared<Bittern>(name, 1, 2);
    EXPECT_TRUE(bittern1->accept(bittern2) == false && bittern2->accept(bittern1) == false);
}

TEST(Test_Bittern, FightBear)
{
    std::string name = "asd";
    std::shared_ptr<Bittern> bittern = std::make_shared<Bittern>(name, 1, 1);
    std::shared_ptr<Bear> bear = std::make_shared<Bear>(name, 1, 2);
    EXPECT_TRUE(bear->accept(bittern) == false);
}

TEST(Test_Bittern, FightMuskrat)
{
    std::string name = "asd";
    std::shared_ptr<Bittern> bittern = std::make_shared<Bittern>(name, 1, 1);
    std::shared_ptr<Muskrat> muskrat = std::make_shared<Muskrat>(name, 1, 2);
    EXPECT_TRUE(muskrat->accept(bittern) == false);
}

TEST(Test_Muskrat, Constr)
{
    std::string name = "asd";
    std::shared_ptr<Muskrat> muskrat = std::make_shared<Muskrat>(name, 1, 1);
    EXPECT_TRUE(muskrat->getName() == name && muskrat->getType() == "MuskratType");
}

TEST(Test_Muskrat, FightMuskrat)
{
    std::string name = "asd";
    std::shared_ptr<Muskrat> muskrat1 = std::make_shared<Muskrat>(name, 1, 1);
    std::shared_ptr<Muskrat> muskrat2 = std::make_shared<Muskrat>(name, 1, 2);
    EXPECT_TRUE(muskrat1->accept(muskrat2) == false && muskrat2->accept(muskrat1) == false);
}

TEST(Test_Muskrat, FightBear)
{
    std::string name = "asd";
    std::shared_ptr<Muskrat> muskrat = std::make_shared<Muskrat>(name, 1, 1);
    std::shared_ptr<Bear> bear = std::make_shared<Bear>(name, 1, 2);
    EXPECT_TRUE(bear->accept(muskrat) == true);
}

TEST(Test_Muskrat, FightBittern)
{
    std::string name = "asd";
    std::shared_ptr<Muskrat> muskrat = std::make_shared<Muskrat>(name, 1, 1);
    std::shared_ptr<Bittern> bittern = std::make_shared<Bittern>(name, 1, 2);
    EXPECT_TRUE(bittern->accept(muskrat) == false);
}

TEST(Test_NPC, Distance)
{
    std::string name = "asd";
    std::shared_ptr<Muskrat> muskrat1 = std::make_shared<Muskrat>(name, 1, 1);
    std::shared_ptr<Muskrat> muskrat2 = std::make_shared<Muskrat>(name, 4, 5);
    float distance = 5.0;
    EXPECT_TRUE(muskrat1->distance(muskrat2) == distance);
}

TEST(Test_NPC, Alive)
{
    std::string name = "asd";
    std::shared_ptr<Muskrat> muskrat = std::make_shared<Muskrat>(name, 1, 1);
    EXPECT_TRUE(muskrat->isAlive() == true);
    muskrat->must_die();
    EXPECT_TRUE(muskrat->isAlive() == false);
}

TEST(Test_NPC, InsertObservers)
{
    std::string name = "asd";
    Muskrat muskrat{name, 1, 1};
    ObserverConsole observer;
    muskrat.subscribe(std::make_shared<ObserverConsole>(observer));
    EXPECT_TRUE(muskrat.countObservers() == 1);
}

TEST(Test_NPC, EraseObservers)
{
    std::string name = "asd";
    Muskrat muskrat{name, 1, 1};
    ObserverFile observer;
    std::shared_ptr observer1 = std::make_shared<ObserverFile>(observer);
    muskrat.subscribe(observer1);
    muskrat.unsubscribe(observer1);
    EXPECT_TRUE(muskrat.countObservers() == 0);
}

TEST(Test_NPC, Print)
{
    std::string name = "asd";
    Muskrat muskrat{name, 1, 1};

    std::ostringstream coutstream;
    std::streambuf *coutbuf = std::cout.rdbuf(coutstream.rdbuf());

    std::cout << muskrat;

    std::cout.rdbuf(coutbuf);

    std::string s = "Type : MuskratType, name : asd, x : 1, y : 1\n";

    EXPECT_TRUE(s == coutstream.str());
}

TEST(Test_Factory, CreateNPC)
{
    std::string name = "asd";
    std::shared_ptr<NPC> obj = factory(NpcType(1), name, 1, 1);
    EXPECT_TRUE(obj->getName() == name && obj->getType() == "BearType");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}