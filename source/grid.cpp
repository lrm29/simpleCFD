#include "grid.hpp"

using namespace std;

simpleCFD::grid::grid()
:
 nCells_(5)
{}

bool simpleCFD::grid::loadGrid()
{

    // Load in cell centre coordinates.
    for(int i=1; i<nCells_-2; ++i){
        cells_.insert(pairLabelCell(i,simpleCFD::cell()));
    }

    return true;
    
}
