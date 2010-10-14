#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <map>

#include "cell.hpp"

namespace simpleCFD {

    typedef std::map<int,cell> mapLabelCell;
    typedef std::pair<int,cell> pairLabelCell;
    
    /*! grid Class.
    *
    */
    class grid
    {

        private:

            mapLabelCell cells; 

        public:

            grid();

            ~grid(){}


        // Member Functions.
        bool loadGrid();
        

    };

} // End namespace simpleCFD.

#endif // GRID_H
