#ifndef BOUNDARY_CONDITIONS_H
#define BOUNDARY_CONDITIONS_H

#include "grid.hpp"
#include "field.hpp"

namespace simpleCFD {

    
    /*! boundaryConditions Class.
    *
    */
    class boundaryConditions
    {

        private:

            simpleCFD::grid& Grid_;

            mapLabelDouble S_P;
    

        public:

            boundaryConditions
            (
                simpleCFD::grid& Grid
            );

            ~boundaryConditions(){}

            void applyBoundaryConditions
            (
                mapLabelDouble& a_w, 
                mapLabelDouble& a_p, 
                mapLabelDouble& a_e, 
                const double& constant,
                const simpleCFD::field& variable
            );

    };

} // End namespace simpleCFD.

#endif // BOUNDARY_CONDITIONS_H
