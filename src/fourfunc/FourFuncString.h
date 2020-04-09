#ifndef FOUR_FUNC_STRING_CC_H
#define FOUR_FUNC_STRING_CC_H

#include <string>

#include "../common/interfaces/IEvaluable.h"
#include "../common/classes/Solution.h"

namespace calccalc
{
    class FourFuncString : IEvaluable // A class that can solve a provided four-function string.
    {
    public:
        FourFuncString(const std::string& str);
        FourFuncString() {}

        Solution evaluate() override;

        const std::string& getString() const {return _str;}
        void setString(const std::string& str);

    private:
        std::string _str;
        Solution _sltn;
        bool _sltn_found = false;

    protected:
        std::string _edit_string; // The string that is edited in the process of solving.

    };
}



#endif // FOUR_FUNC_STRING_CC_H