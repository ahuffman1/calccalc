#ifndef I_EVALUABLE
#define I_EVALUABLE

#include "../classes/Solution.h"

namespace calccalc
{
    class IEvaluable
    {
        virtual Solution evaluate() = 0;
    };

}


#endif // I_SOLVABLE_CC_H