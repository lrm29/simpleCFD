#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <iostream>
#include <ostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

#include "field.hpp"
#include "grid.hpp"

namespace simpleCFD {

    /*! Input/Output Class.
    *
    */
    class inputOutput
    {

        time_t startTime, endTime;

        public:

            inputOutput();

            ~inputOutput(){}

            //! Print header to an output stream.
            bool printHeader(std::ostream& outputStream);

            //! Print results to an output stream.
            void printResults
            (
                std::ostream& outputStream,
                simpleCFD::grid Grid,
                simpleCFD::field Field
            );

            void printTime();

            //! Plot gnuplot graph
            void plotGraph(const simpleCFD::field& variable);

    };

} // End namespace simpleCFD.

#endif //INPUT_OUTPUT_H
