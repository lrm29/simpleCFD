#include "matrix.hpp"

//----------------------------------------------------------------------------//

void simpleCFD::matrix::sources(const double& constant, const field& variable)
{


}

//----------------------------------------------------------------------------//

simpleCFD::matrix::matrix(simpleCFD::grid& Grid, simpleCFD::field& Field)
:
 Grid_(Grid),
 Field_(Field),
 Boundaries_(Grid)
{

    for (unsigned int i=1; i<=Grid_.nCells(); ++i) {
        S_u.insert(std::make_pair<int,double>(
            i,0.0   
        ));
    }
    
    for (unsigned int i=1; i<=Grid_.nCells(); ++i) {
        a_w.insert(std::make_pair<int,double>(i,0.0));
        a_e.insert(std::make_pair<int,double>(i,0.0));
    }
    
    for (unsigned int i=1; i<=Grid_.nCells(); ++i) {
        a_p.insert(std::make_pair<int,double>(i,0.0));
    }
    
}

void simpleCFD::matrix::divergence(const double& constant, const field& variable)
{

    for (unsigned int i=1; i<=Grid_.nCells(); ++i) {
        a_w[i] += std::max(0.0,constant);
        a_e[i] += std::max(0.0,-constant);
    } 

    a_w[1] = 0.0;
    a_e[Grid_.nCells()] = 0.0;

    S_u[1] += constant*variable[0];

    Boundaries_.applyBoundaryConditionsConvection(a_w, a_p, a_e, constant, variable);

}

void simpleCFD::matrix::laplacian(const double& constant, const field& variable)
{

    for (unsigned int i=1; i<=Grid_.nCells(); ++i) {
        a_w[i] += constant*Grid_.getCell(i).A()/Grid_.getCell(i).dx();
        a_e[i] += constant*Grid_.getCell(i).A()/Grid_.getCell(i).dx();
    }

    a_w[1] = 0.0;
    a_e[Grid_.nCells()] = 0.0;

    S_u[1] += 2*variable[0]*constant*Grid_.getCell(1).A()/Grid_.getCell(1).dx();    
    S_u[Grid_.nCells()] += 2*variable[Grid_.nCells()+1]*constant*Grid_.getCell(Grid_.nCells()).A()/Grid_.getCell(Grid_.nCells()).dx(); 

    Boundaries_.applyBoundaryConditionsDiffusion(a_w, a_p, a_e, constant, variable);
    
}

void simpleCFD::matrix::solve()
{

    for (unsigned int i=1; i<=Grid_.nCells(); ++i) {
        a_p[i] += a_w[i]+a_e[i];
    }

    TDMA();

}

bool simpleCFD::matrix::TDMA()
{
    
    doubleVector A, C;

    A.push_back(0.0);
    C.push_back(0.0);
    for (unsigned int i=1; i<=Grid_.nCells(); ++i) {    
        A.push_back(a_e[i]/(a_p[i]-a_w[i]*A[i-1]));
        C.push_back((a_w[i]*C[i-1] + S_u[i])/(a_p[i] - a_w[i]*A[i-1]));
    }

    for (unsigned int i=Grid_.nCells(); i>=1; --i) {
        Field_[i] = A[i]*Field_[i+1] + C[i];
    }

    return true;

}

bool simpleCFD::matrix::gaussSeidel()
{

    return true;

}
