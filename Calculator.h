#pragma once
#include "List.h"
#include "String.h"

class Calculator
{

private:
    List<String> tokens;

    int errCode; // 발생된 오류코드 값 : 0 -> 오류 없음 , 다른 값 -> 오류 있음

    int value; // 계산된 값

    String postfix; // 후위표기식 = 최초 공백으로 초기화

    int makePostFix(); /*   postfix 로 변경하는 함수 :
                            오류 없는경우, 0, 오류가 있는 경우, 1을 반환
                            변경결과는 postfix 변수에 저장, 오류시 적절한 코드를 errCode 에 저장 (오류코드는 각자가 정의) */

    int evaluation(); /*    postfix 를 계산하는 함수 :
                            계산된 값을 구함, 오류 없는경우 0, 오류가 있는 경우, 1을 반환
                            계산된 값은 value 에 저장, 오류시 적절한 코드를 errCode 에 저장 (오류코드는 각자가 정의) */

public:
    void setTokens(char *sen); //받은 문자열을 토큰으로 변환해서 저장

    int getErrorCode(); // 오류코드 반환

    int setExpression(const char *expr); //expr에 전달된 수식(중위표기식)을 postfix로 변경하고 계산하는 함수
                                         //오류 없는경우, 0, 오류가 있는 경우, 1을 반환

    String getPostFix(); // 변환된 후위표기식을 반환   --> 오류가 있을경우 최초값인 공백이 리턴

    int getValue(); // 수식 오류있음 --> 예외발생
    // 수식 오류없음 --> 결과값 리턴
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

    String newExpr(newSen, charCount - 1); //  expr을 공백문자 뺀 문자열로 만든 후 String 클래스로 만듦
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
            throw "숫자나 괄호, 사칙연산만 입력 가능";
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