#include "grid.hpp"

using namespace std;

simpleCFD::grid::grid()
:
 nCells_(20),
 gridLength_(0.02)
{

    // Load in cell centre coordinates.
    for(int i=1; i<=nCells_; ++i){
        cells_.insert(pairLabelCell(i,simpleCFD::cell()));
    }

    for(int i=1; i<=nCells_; ++i){
        getCell(i).setCellCentre((i-0.5)*gridLength_/nCells_);
    }

}

bool simpleCFD::grid::loadGrid()
{


    
    return true;
    
}
