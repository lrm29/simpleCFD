#include "simpleCFD.hpp"

using namespace std;

int main()
{

    simpleCFD::inputOutput IO;
    
    // Print Info
    IO.printHeader(cout);
    
    // Load Variables from File.
    
    // Create Grid.
    simpleCFD::grid Grid;

    simpleCFD::field T(Grid);
    double k = 10;
    
    // Construct Matrix.
    simpleCFD::matrix temperatureMatrix(Grid, T);

    temperatureMatrix.discretise
    (
        k, T
    );
    
    // Solve Matrix.
    temperatureMatrix.solve();

    // Output results.
    IO.plotGraph(T);

    return 0;

}

