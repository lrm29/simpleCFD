#ifndef CELL_H
#define CELL_H

namespace simpleCFD {

    
    /*! grid Class.
    *
    */
    class cell
    {

        private:

        double a_w;
        double a_e;

        double cellCentre;
    

        public:

            cell(){}

            ~cell(){}

    };

} // End namespace simpleCFD.

#endif // CELL_H
