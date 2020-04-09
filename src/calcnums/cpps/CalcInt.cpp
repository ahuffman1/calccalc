#include "../CalcInt.h"

#include <cmath>

using namespace std;

namespace calccalc
{
    CalcInt::CalcInt(const int& base, const unsigned int& root):
    _base(base), _root(root)
    {

    }

    Solution CalcInt::evaluate()
    {
        if (_root == 0)
            return Solution::undef();
        else if (_base < 0 && _root % 2 == 0)
            return Solution::undef();
        else
            return Solution(pow(_base, 1.0/ _root), true);
    }

}