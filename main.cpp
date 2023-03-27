#include <iostream>
#include <fstream>
#include "Knapsack.h"
#include "Backpack.h"
#include "BackpackDynamic.h"

using namespace std;

int main() 
{
    /*
    // 1 часть
    
    Knapsack ks;
    ks.ReadFile("input.txt");
    ks.SetPrintFlag(true);
    ks.SearchMaxPrice();
    ks.PrintBestItems();
    
    
    // 2 часть
    
    Backpack bp;
    bp.solve();
    bp.print();

    */
    // 3 часть

    BackpackDynamic bp(1);
    bp.solve();
    bp.print();
    
    return 0;
}