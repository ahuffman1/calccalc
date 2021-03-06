#include "../FourFuncString.h"

#include "../../common/GlobalConsts.h"

#include <stdexcept>
#include <algorithm>

#include <iostream>

using namespace std;

enum operation
{
    add, subtract, multiply, divide
};

void mathReplace(string& str, const int& pos, const operation& op) 
{
    int rightNumEndPos = pos; // The last digit of the right number, inclusive.
    int leftNumBeginPos = pos; // The first digit of the left number, inclusive.

    // Get the end positions of the numbers.
    for(rightNumEndPos = pos + 1; rightNumEndPos < str.length(); rightNumEndPos++)
    {
        if(str[rightNumEndPos] != '.' && !isdigit(str[rightNumEndPos]) && str[rightNumEndPos] != '-')
        {
            rightNumEndPos--;
            break;
        }
    }
    if (rightNumEndPos = str.length()) rightNumEndPos--;
    for(leftNumBeginPos = pos - 1; leftNumBeginPos >= 0; leftNumBeginPos--)
    {
        if(str[leftNumBeginPos] != '.' && !isdigit(str[leftNumBeginPos]) && str[leftNumBeginPos] != '-')
        {
            leftNumBeginPos++;
            break;
        }
    }
    if (leftNumBeginPos < 0) leftNumBeginPos++;

    // Substring the numbers.
    string leftNumStr = str.substr(leftNumBeginPos, pos - leftNumBeginPos );
    string rightNumStr = str.substr(pos + 1, rightNumEndPos - pos + 1 );

    // parse them to doubles.
    double leftNum = stod(leftNumStr);
    double rightNum = stod(rightNumStr);

    // Perform the provided operation.
    double result = 0.0;
    switch (op)
    {
        case add : result = leftNum + rightNum; break;
        case subtract : result = leftNum - rightNum; break;
        case multiply : result = leftNum * rightNum; break;
        case divide : 
            if (rightNum < doubleEpsilon )
            {
                throw runtime_error("Cannot divide by zero.");
            }
            else
            {
                result = leftNum / rightNum;
            }

            break;
            

    }


    // Replace them in the string.
    str.replace(leftNumBeginPos, rightNumEndPos - leftNumBeginPos + 2, to_string(result));

}


namespace calccalc
{
    FourFuncString::FourFuncString(const string& str)
    {
        for(size_t i = 0; i < str.length(); i++)
        {
            if(!isspace(str[i]))
            {
                _str.push_back(str[i]);
            }
        }

        _edit_string = _str;

    }

    // TODO: For later, come up with a more efficient way to check for +- and --'s.
    Solution FourFuncString::evaluate() // throws invalid_argument
    {
        if(!_sltn_found)
        {

            // Multiplication and division check
            for(size_t i = 0; i < _edit_string.length(); i++)
            {
                if(_edit_string[i] == '*')
                {
                    mathReplace(_edit_string, i, multiply);
                }
                else if(_edit_string[i] == '/')
                {
                    try
                    {
                        mathReplace(_edit_string, i, divide);
                    }
                    catch(const runtime_error&)
                    {
                        _sltn_found = true;
                        _sltn = Solution(0.0, false);
                        return _sltn;
                    }
                    
                    
                }

            }


            // Remove "+-'s" and "--'s"
            size_t plusminusi = _edit_string.find("+=");

            while (plusminusi != string::npos)
            {
                _edit_string.replace(plusminusi, 2, "-");
                plusminusi = _edit_string.find("+=");

            } 

            size_t minusminusi = _edit_string.find("--");

            while (minusminusi != string::npos)
            {
                _edit_string.replace(minusminusi, 2, "+");
                minusminusi = _edit_string.find("--");

            }

            

            // Plus and minus check
            for(size_t i = 0; i < _edit_string.length(); i++)
            {
                if(i != 0 && _edit_string[i] == '+')
                {
                    mathReplace(_edit_string, i, add);
                }
                else if(i != 0 && _edit_string[i] == '-')
                {
                    mathReplace(_edit_string, i, subtract);
                }
            }


            _sltn = Solution(stod(_edit_string), true);



        }

        return _sltn;

    }

    void FourFuncString::setString(const string& str)
    {
        if(str != _str)
        {
            _sltn_found = false;
            _str = str;
        }
    }
}