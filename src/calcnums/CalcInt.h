#ifndef CALC_INT_CC_H
#define CALC_INT_CC_H

#include "../common/interfaces/IEvaluable.h"
#include "../common/classes/Solution.h"

namespace calccalc
{
    class CalcInt : IEvaluable
    {
    public:
        CalcInt(const int& base, const unsigned int& root);
        CalcInt() {}

        Solution evaluate() override;

        const unsigned int& getBase() const {return _base;}
        const int& getRoot() const {return _root;}

        void setBase(const int& b) {_base = b;}
        void setRoot(const int& r) {_root = r;}



    private:
        unsigned int _base;
        int _root;

    };

}


#endif // CALC_INT_CC_H