#include "gtest/gtest.h"
#include "../../include/Formula.h"

TEST(blaTest, test1) {
    std::cout << "GOT HERE!" << std::endl;
    //arrange
    //act
    //assert
    EXPECT_EQ(Formula::bla(0), 0);
    EXPECT_EQ(Formula::bla(10), 20);
    EXPECT_EQ(Formula::bla(50), 100);
}

TEST(blaTest, test2) {
    std::cout << "GOT HERE!" << std::endl;
    //arrange
    //act
    //assert
    EXPECT_EQ(Formula::bla(1), 0);
    EXPECT_EQ(Formula::bla(10), 20);
    EXPECT_EQ(Formula::bla(50), 100);
}