#include <iostream>
#include "List.h"
#include "String.h"
#include "Calculator.h"

using namespace std;

int main()
{
    char expr[1000];

    cout << "수식을 입력하시오 : ";

    cin.getline(expr, 1000);

    Calculator c;

    try
    {
        c.setTokens(expr);
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }

    // if (!c.setExpression(expr))

    // {

    //     String posfix = c.getPostFix();

    //     try
    //     {

    //         cout << "후위표기식 : " << postfix << "결과값 : " << c.getValue() << endl;
    //     }
    //     catch (const char *errmsg)

    //     {

    //         cout << errmsg << endl;
    //     }
    // }
}