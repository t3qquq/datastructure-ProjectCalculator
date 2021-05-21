#include <iostream>
#include "Stack.h"
#include "Calculator.h"

using namespace std;

void errExplain(int err)
{
    if (err == -1)
        cout << "자연수, 괄호 및 사칙연산만 입력 가능" << endl;
}

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
    catch (int err)
    {
        errExplain(err);
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