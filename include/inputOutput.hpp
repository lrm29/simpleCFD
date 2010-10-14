#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <iostream>
#include <ostream>
#include <fstream>

namespace simpleCFD {

    /*! Input/Output Class.
    *
    */
    class inputOutput
    {

        public:

            inputOutput(){}

            ~inputOutput(){}

            //! Print header to an output stream.
            bool printHeader(std::ostream& outputStream);

    };

} // End namespace simpleCFD.

#endif //INPUT_OUTPUT_H
