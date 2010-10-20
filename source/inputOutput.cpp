#include "inputOutput.hpp"

using namespace std;

simpleCFD::inputOutput::inputOutput()
{

    time(&startTime);

}

bool simpleCFD::inputOutput::printHeader(std::ostream& outputStream)
{
    time_t rawtime;
    time(&rawtime);
    //std::cout << "Current time is: " << asctime(localtime(&rawtime));

    outputStream << "\n|----------------------------------------------------|" << endl;
    outputStream << "|simpleCFD: A 1D Convection-Diffusion Equation Solver|" << endl;
    outputStream << "|----------------------------------------------------|" << endl;
    outputStream << "|----------------Laurence R. McGlashan---------------|" << endl;
    outputStream << "|----------------------------------------------------|" << endl;    
    outputStream << "|Time Tag: " << asctime(localtime(&rawtime));
    outputStream << "|----------------------------------------------------|\n" << endl; 
    return true;
}

void simpleCFD::inputOutput::printResults
(
    std::ostream& outputStream,
    simpleCFD::grid Grid,
    simpleCFD::field Field
)
{

    outputStream << std::left << std::setw(10) << "# x (m)" << " " << "Temperature (K)" << std::endl; 
    for (unsigned int i=1; i<=Grid.nCells(); ++i) {
        outputStream << std::setw(10) << Grid.getCell(i).cellCentre() << " " << Field[i] << std::endl;
    }

}

void simpleCFD::inputOutput::printTime()
{

    time(&endTime);
    std::cout << std::endl << "Simulation finished in: " << difftime(endTime, startTime) << " seconds." << std::endl;

}

void simpleCFD::inputOutput::plotGraph(const simpleCFD::field& variable)
{

    //std::system("gnuplot");

}
