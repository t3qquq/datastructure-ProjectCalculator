#include <iostream>
#include "Stack.h"
#include "Calculator.h"

using namespace std;

void errExplain(int err)
{
    if (err == -1)
        cout << "�ڿ���, ��ȣ �� ��Ģ���길 �Է� ����" << endl;
}

int main()
{
    char expr[1000];

    cout << "������ �Է��Ͻÿ� : ";

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

    //         cout << "����ǥ��� : " << postfix << "����� : " << c.getValue() << endl;
    //     }
    //     catch (const char *errmsg)

    //     {

    //         cout << errmsg << endl;
    //     }
    // }
}