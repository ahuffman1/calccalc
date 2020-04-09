#include <iostream>
#include <string>

#include "fourfunc/FourFuncString.h"

using namespace std;

int main()
{
    string input;
    cout << "Enter a four function string >> ";
    getline(cin, input);
    cout << "Input: " << input << endl;

    calccalc::FourFuncString ff(input);

    cout << ff.evaluate().getSolution();

}