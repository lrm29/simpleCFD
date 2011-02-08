// Main file.

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

    // Create Field.
    simpleCFD::field T(Grid);
    
    // Construct Matrix.
    simpleCFD::matrix temperatureMatrix(Grid, T);
    
    // Diffusion Coefficient.
    double k = 0.001;
    double coeff = 1.0;
    temperatureMatrix.laplacian(k, T);
    temperatureMatrix.divergence(coeff, T);
    
    // Solve Matrix.
    temperatureMatrix.solve();

    // Output results.
    IO.printResults(cout,Grid,T);
    
    ofstream file("results.txt");
    IO.printResults(file,Grid,T);
    file.close();
    
    IO.plotGraph(T);

    IO.printTime();

    return 0;

}

