#ifndef MATRIX_H
#define MATRIX_H

#include<map>

#include "grid.hpp"
#include "field.hpp"
#include "boundaryConditions.hpp"

namespace simpleCFD {
    
    /*! matrix Class.
    *
    */
    class matrix
    {

        private:

        simpleCFD::grid& Grid_;
        simpleCFD::field& Field_;
        
        simpleCFD::boundaryConditions Boundaries_;

        mapLabelDouble a_w, a_e, a_p;
        mapLabelDouble S_u, S_p;

        doubleVector lowerDiagonal;
        doubleVector diagonal;
        doubleVector upperDiagonal;

        void applyBoundaryConditions();

        public:

            matrix(simpleCFD::grid& Grid, simpleCFD::field& Field);

            ~matrix(){}

            void discretise(const double& constant, const field& variable);

            void solve();

            bool gaussSeidel();

            bool TDMA();

    };

} // End namespace simpleCFD.

#endif // MATRIX_H
