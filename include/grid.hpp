#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <map>

#include "cell.hpp"

namespace simpleCFD {

    typedef std::map<int,cell> mapLabelCell;
    typedef std::pair<int,cell> pairLabelCell;
    typedef std::map<int,double> mapLabelDouble;
    
    /*! grid Class.
    *
    */
    class grid
    {

        private:

            mapLabelCell cells_;
            double nCells_;

        public:

            grid();

            ~grid(){}


        // Member Functions.
        bool loadGrid();

        inline const double& nCells() const
        {
            return nCells_;
        }

        inline const cell& getCell(const int& i)
        {
            return cells_[i];
        }

    };

} // End namespace simpleCFD.

#endif // GRID_H
