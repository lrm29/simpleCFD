#include "inputOutput.hpp"

using namespace std;

bool simpleCFD::inputOutput::printHeader(std::ostream& outputStream)
{
    outputStream << "\n|----------------------------------------------------|" << endl;
    outputStream << "|simpleCFD: A 1D Convection-Diffusion Equation Solver|" << endl;
    outputStream << "|----------------------------------------------------|" << endl;
    outputStream << "|----------------Laurence R. McGlashan---------------|" << endl;
    outputStream << "|----------------------------------------------------|\n" << endl;    

    return true;
}
