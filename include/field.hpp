#ifndef FIELD_H
#define FIELD_H

#include "grid.hpp"

namespace simpleCFD {

    typedef std::vector<double> doubleVector;

    /*! Field Class.
    *
    */
    class field
    {

        const simpleCFD::grid& Grid_;

        doubleVector data_;

        public:

            field(const simpleCFD::grid& Grid);

            ~field(){}

            double operator [] (int i) const;
            double& operator [] (int i);

    };

} // End namespace simpleCFD.

#endif //FIELD_H
