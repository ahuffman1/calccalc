#ifndef SOLUTION_CC_H
#define SOLUTION_CC_H

namespace calccalc
{
    class Solution // The estimated solution to a math equation.
    {
    public:
        Solution(const double& val, const bool& exists);
        Solution() {}

        const bool& exists() const {return _exists;}
        const double& getSolution() const {return _solution;}

        void setExists(const bool& e) {_exists = e;}
        void setSolution(const double& s) {_solution = s;}

        static Solution undef() {return Solution(0.0, false);} // Builds an instance of an undefined Solution.


    private:
        double _solution = 0.0;
        bool _exists = true;


    };
}


#endif // SOLUTION_CC_H