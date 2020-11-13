#include <gtest/gtest.h>
#include "Graphs.cpp"
#include <iostream>

using namespace std;

TEST(init, 0)
{
    std::cout << "Hello, world" << std::endl;
}

int main(int argc, char **argv) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
