#include "field.hpp"

using namespace std;

simpleCFD::field::field(const simpleCFD::grid& Grid)
:
 Grid_(Grid),
 data_(Grid.nCells()+2)
{

    data_[0] = 100;

    data_[6] = 500;

}


double simpleCFD::field::operator [] (int i) const
{
    return data_[i];
}

double& simpleCFD::field::operator [] (int i)
{
    return data_[i];
}
