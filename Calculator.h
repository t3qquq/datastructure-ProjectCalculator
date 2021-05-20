#pragma once
#include "List.h"
#include "String.h"

class Calculator
{

private:
    List<String> tokens;

    int errCode; // �߻��� �����ڵ� �� : 0 -> ���� ���� , �ٸ� �� -> ���� ����

    int value; // ���� ��

    String postfix; // ����ǥ��� = ���� �������� �ʱ�ȭ

    int makePostFix(); /*   postfix �� �����ϴ� �Լ� :
                            ���� ���°��, 0, ������ �ִ� ���, 1�� ��ȯ
                            �������� postfix ������ ����, ������ ������ �ڵ带 errCode �� ���� (�����ڵ�� ���ڰ� ����) */

    int evaluation(); /*    postfix �� ����ϴ� �Լ� :
                            ���� ���� ����, ���� ���°�� 0, ������ �ִ� ���, 1�� ��ȯ
                            ���� ���� value �� ����, ������ ������ �ڵ带 errCode �� ���� (�����ڵ�� ���ڰ� ����) */

public:
    void setTokens(char *sen); //���� ���ڿ��� ��ū���� ��ȯ�ؼ� ����

    int getErrorCode(); // �����ڵ� ��ȯ

    int setExpression(const char *expr); //expr�� ���޵� ����(����ǥ���)�� postfix�� �����ϰ� ����ϴ� �Լ�
                                         //���� ���°��, 0, ������ �ִ� ���, 1�� ��ȯ

    String getPostFix(); // ��ȯ�� ����ǥ����� ��ȯ   --> ������ ������� ���ʰ��� ������ ����

    int getValue(); // ���� �������� --> ���ܹ߻�
    // ���� �������� --> ����� ����
};

void Calculator::setTokens(char *sen)
{
    int charCount = 0;

    for (int i = 0; i < 1000; i++)
    {
        if (sen[i] != ' ')
            charCount++;
        if (sen[i] == '\0')
            break;
    }
    char *newSen = new char[charCount];

    charCount = 0;

    for (int i = 0; i < 1000; i++)
    {
        if (sen[i] != ' ')
            newSen[charCount++] = sen[i];
        if (sen[i] == '\0')
            break;
    }

    String newExpr(newSen, charCount - 1); //  expr�� ���鹮�� �� ���ڿ��� ���� �� String Ŭ������ ����
                                           //  char* newSen  =>  String newExpr

    int *maskBit = new int[charCount];

    std::fill_n(maskBit, charCount, -99);

    for (int i = 0; i < charCount; i++)
    {
        if (newSen[i] == '(' || newSen[i] == ')' || newSen[i] == '+' || newSen[i] == '-' || newSen[i] == '*' || newSen[i] == '/')
            maskBit[i] = 1;

        else if (newSen[i] == '0' || newSen[i] == '1' || newSen[i] == '2' || newSen[i] == '3' || newSen[i] == '4' || newSen[i] == '5' || newSen[i] == '6' || newSen[i] == '7' || newSen[i] == '8' || newSen[i] == '9')
            maskBit[i] = 0;

        else if (newSen[i] == '\0')
            maskBit[i] = -1;
    }

    int anch = 0;

    for (int i = 0; i < charCount; i++)
    {
        if (maskBit[i] == -99)
            throw "���ڳ� ��ȣ, ��Ģ���길 �Է� ����";
        if (maskBit[i] == 1)
        {
            String tmp;
            tmp = newExpr.Substr(i, i);
            tokens.addItem(tmp);
            anch++;
        }
        else if (maskBit[i] == 0)
        {
            if (maskBit[i + 1] == 1 || maskBit[i + 1] == -1)
            {
                String tmp;
                tmp = newExpr.Substr(anch, i);
                tokens.addItem(tmp);
                anch = i + 1;
            }
        }
    }

    //tokens.print();
    //verified!
}