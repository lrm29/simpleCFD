#include "grid.hpp"

using namespace std;

simpleCFD::grid::grid()
{}

bool simpleCFD::grid::loadGrid()
{

    // Load in cell centre coordinates.
    for(int i=1; i<9; ++i){
        cells.insert(pairLabelCell(i,simpleCFD::cell()));
    }

    return true;
    
}
