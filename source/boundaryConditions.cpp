#include "boundaryConditions.hpp"

simpleCFD::boundaryConditions::boundaryConditions
(
    simpleCFD::grid& Grid
)
:
 Grid_(Grid)
{}

void simpleCFD::boundaryConditions::applyBoundaryConditions
(
    mapLabelDouble& a_w, 
    mapLabelDouble& a_p, 
    mapLabelDouble& a_e,
    const double& constant,
    const simpleCFD::field& variable
)
{

    S_P.insert(std::make_pair<int,double>(
        1,-2*constant*Grid_.getCell(1).A()/Grid_.getCell(1).dx()
    ));
    
    S_P.insert(std::make_pair<int,double>(
        Grid_.nCells(),-2*constant*Grid_.getCell(Grid_.nCells()).A()/Grid_.getCell(Grid_.nCells()).dx()
    ));
    
    a_p[1] -= S_P[1];
    a_p[Grid_.nCells()] -= S_P[Grid_.nCells()];

}
