#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <vector>
#include "Knapsack.h"
#include "Backpack.h"
#include "BackpackDynamic.h"

using namespace std;

TEST_CASE("Knapsack Test")
{
    Knapsack ks;
    ks.ReadFile("input.txt");
    ks.SetPrintFlag(true);
    ks.SearchMaxPrice();
    ks.PrintBestItems();

    Backpack bp;
    bp.solve();
    bp.print();

    REQUIRE(ks.GetMaxPrice() == bp.GetMaxPrice());
}



