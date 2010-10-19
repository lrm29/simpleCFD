#include "matrix.hpp"

//----------------------------------------------------------------------------//



//----------------------------------------------------------------------------//

simpleCFD::matrix::matrix(simpleCFD::grid& Grid, simpleCFD::field& Field)
:
 Grid_(Grid),
 Field_(Field),
 Boundaries_(Grid)
{

}

void simpleCFD::matrix::discretise(const double& constant, const field& variable)
{

    for (unsigned int i=1; i<=Grid_.nCells(); ++i) {
        a_w.insert(std::make_pair<int,double>(i,constant*Grid_.getCell(i).A()/Grid_.getCell(i).dx()));
        a_e.insert(std::make_pair<int,double>(i,constant*Grid_.getCell(i).A()/Grid_.getCell(i).dx()));
    }

    a_w[1] = 0.0;
    a_e[Grid_.nCells()] = 0.0;
    
    for (unsigned int i=1; i<=Grid_.nCells(); ++i) {
        a_p.insert(std::make_pair<int,double>(i,a_w[i]+a_e[i]));
    }
    
    for (unsigned int i=1; i<=Grid_.nCells(); ++i) {
        std::cout << a_w[i] << " " << a_p[i] << " " << a_e[i] << std::endl << std::endl;
    }

    Boundaries_.applyBoundaryConditions(a_w, a_p, a_e, constant, variable);

    for (unsigned int i=1; i<=Grid_.nCells(); ++i) {
        std::cout << a_w[i] << " " << a_p[i] << " " << a_e[i] << std::endl << std::endl;
    }

/*    upperDiagonal.clear();
    diagonal.clear();
    lowerDiagonal.clear();
    
    for (unsigned int i=1; i<=Grid_.nCells(); ++i) {
        if(i!=Grid_.nCells()){upperDiagonal.push_back(a_e[i]);}else{upperDiagonal.push_back(0.0);}
        diagonal.push_back(a_p[i]);
        if(i!=1){lowerDiagonal.push_back(a_w[i]);}else{lowerDiagonal.push_back(0.0);}
    }
    
    for (unsigned int i=1; i<=Grid_.nCells(); ++i) {
        std::cout << lowerDiagonal[i] << " " << diagonal[i] << " " << upperDiagonal[i] << std::endl;
    }*/
    
}

void simpleCFD::matrix::solve()
{

    TDMA();



}

bool simpleCFD::matrix::TDMA()
{

    doubleVector A, C;

    A.push_back(0.0);
    C.push_back(0.0);
    for (unsigned int i=1; i<=Grid_.nCells(); ++i) {    
        A.push_back(a_e[i]/(a_p[i]-a_w[i]*A[i-1]));
        C.push_back((a_w[i]*C[i-1] + Boundaries_.getSource(i))/(a_p[i] - a_w[i]*A[i-1]));
    }

    for (unsigned int i=Grid_.nCells(); i>=1; --i) {
    std::cout << A[i]*Field_[i+1] << " " << std::endl;
        Field_[i] = A[i]*Field_[i+1] + C[i];
    }

   std::cout << std::endl;
   
    for (unsigned int i=1; i<=Grid_.nCells(); ++i) {
        std::cout << A[i] << " " << C[i] << std::endl;
    }

   std::cout << std::endl;

    for (unsigned int i=1; i<=Grid_.nCells(); ++i) {
        std::cout << Field_[i] << " " << i << std::endl;
    }

    return true;

}

bool simpleCFD::matrix::gaussSeidel()
{

    return true;

}
