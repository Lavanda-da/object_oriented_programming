#include <gtest/gtest.h>
#include "include/declaration.h"
#include "include/npc.h"
#include "include/bear.h"
#include "include/bittern.h"
#include "include/muskrat.h"
#include "include/factory.h"
#include "include/observerConsole.h"
#include "include/observerFile.h"

// TEST(Test_Bear, Constr)
// {
//     std::string name = "asd";
//     Bear bear{name, 1, 1};
//     EXPECT_TRUE(bear.getName() == name && bear.getType() == "BearType");
// }

// TEST(Test_Bear, FightBear)
// {
//     std::string name = "asd";
//     Bear bear1(name, 1, 1);
//     Bear bear2(name, 1, 2);
//     EXPECT_TRUE(bear1.accept(bear2) == false && bear2.accept(bear1) == false);
// }

// TEST(Test_Bear, FightBittern)
// {
//     std::string name = "asd";
//     Bear bear{name, 1, 1};
//     Bittern bittern{name, 1, 2};
//     EXPECT_TRUE(bittern.accept(bear) == true);
// }

// TEST(Test_Bear, FightMuskrat)
// {
//     std::string name = "asd";
//     Bear bear{name, 1, 1};
//     Muskrat muskrat{name, 1, 2};
//     EXPECT_TRUE(muskrat.accept(bear) == true);
// }

// TEST(Test_Bittern, Constr)
// {
//     std::string name = "asd";
//     Bittern bittern{name, 1, 1};
//     EXPECT_TRUE(bittern.getName() == name && bittern.getType() == "BitternType");
// }

// TEST(Test_Bittern, FightBittern)
// {
//     std::string name = "asd";
//     Bittern bittern1{name, 1, 1};
//     Bittern bittern2{name, 1, 2};
//     EXPECT_TRUE(bittern1.accept(bittern2) == false && bittern2.accept(bittern1) == false);
// }

// TEST(Test_Bittern, FightBear)
// {
//     std::string name = "asd";
//     Bittern bittern{name, 1, 1};
//     Bear bear{name, 1, 2};
//     EXPECT_TRUE(bear.accept(bittern) == false);
// }

// TEST(Test_Bittern, FightMuskrat)
// {
//     std::string name = "asd";
//     Bittern bittern{name, 1, 1};
//     Muskrat muskrat{name, 1, 2};
//     EXPECT_TRUE(muskrat.accept(bittern) == false);
// }

// TEST(Test_Muskrat, Constr)
// {
//     std::string name = "asd";
//     Muskrat muskrat{name, 1, 1};
//     EXPECT_TRUE(muskrat.getName() == name && muskrat.getType() == "MuskratType");
// }

// TEST(Test_Muskrat, FightMuskrat)
// {
//     std::string name = "asd";
//     Muskrat muskrat1{name, 1, 1};
//     Muskrat muskrat2{name, 1, 2};
//     EXPECT_TRUE(muskrat1.accept(muskrat2) == false && muskrat2.accept(muskrat1) == false);
// }

// TEST(Test_Muskrat, FightBear)
// {
//     std::string name = "asd";
//     Muskrat muskrat{name, 1, 1};
//     Bear bear{name, 1, 2};
//     EXPECT_TRUE(bear.accept(muskrat) == true);
// }

// TEST(Test_Muskrat, FightBittern)
// {
//     std::string name = "asd";
//     Muskrat muskrat{name, 1, 1};
//     Bittern bittern{name, 1, 2};
//     EXPECT_TRUE(bittern.accept(muskrat) == false);
// }

// TEST(Test_NPC, Distance)
// {
//     std::string name = "asd";
//     Muskrat muskrat1{name, 1, 1};
//     Muskrat muskrat2{name, 4, 5};
//     float distance = 5.0;
//     EXPECT_TRUE(muskrat1.distance(muskrat2) == distance);
// }

// TEST(Test_NPC, InsertObservers)
// {
//     std::string name = "asd";
//     Muskrat muskrat{name, 1, 1};
//     ObserverConsole observer;
//     muskrat.subscribe(std::make_shared<ObserverConsole>(observer));
//     EXPECT_TRUE(muskrat.countObservers() == 1);
// }

// TEST(Test_NPC, EraseObservers)
// {
//     std::string name = "asd";
//     Muskrat muskrat{name, 1, 1};
//     ObserverFile observer;
//     std::shared_ptr observer1 = std::make_shared<ObserverFile>(observer);
//     muskrat.subscribe(observer1);
//     muskrat.unsubscribe(observer1);
//     EXPECT_TRUE(muskrat.countObservers() == 0);
// }

// TEST(Test_NPC, Print)
// {
//     std::string name = "asd";
//     Muskrat muskrat{name, 1, 1};

//     std::ostringstream coutstream;
//     std::streambuf *coutbuf = std::cout.rdbuf(coutstream.rdbuf());

//     std::cout << muskrat;

//     std::cout.rdbuf(coutbuf);

//     std::string s = "Type : MuskratType, name : asd, x : 1, y : 1\n";

//     EXPECT_TRUE(s == coutstream.str());
// }

// TEST(Test_NPC, Notify)
// {
//     std::string name = "asd";
//     Bear bear{name, 1, 1};
//     Bittern bittern{name, 1, 1};
//     ObserverConsole observer;
//     bear.subscribe(std::make_shared<ObserverConsole>(observer));
//     bittern.subscribe(std::make_shared<ObserverConsole>(observer));
//     std::ostringstream coutstream;
//     std::streambuf *coutbuf = std::cout.rdbuf(coutstream.rdbuf());

//     bittern.accept(bear);

//     std::cout.rdbuf(coutbuf);

//     std::string s = "BearType asd убил BitternType asd\n";
//     std::cout << coutstream.str();
//     EXPECT_TRUE(s == coutstream.str());
// }

// TEST(Test_Factory, CreateNPC)
// {
//     std::string name = "asd";
//     std::shared_ptr<NPC> obj = factory(NpcType(1), name, 1, 1);
//     EXPECT_TRUE(obj->getName() == name && obj->getType() == "BearType");
// }

// TEST(Test_Fight, FightBearWithMuskrat)
// {
//     std::string name = "asd";
//     Bear bear{name, 1, 2};
//     Muskrat muskrat{name, 1, 1};
//     std::set<std::shared_ptr<NPC>> monsters {std::make_shared<Bear>(bear), 
//                                              std::make_shared<Muskrat>(muskrat)};
//     std::set<std::shared_ptr<NPC>> deadMonsters = fight(monsters, 10);
//     EXPECT_TRUE(monsters == deadMonsters);
// }

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}