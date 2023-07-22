#include <iostream>
#include <string>
using namespace std ;

class Calculator
{
public:
    int getResult(string oper)
    {
        if(oper == "+" ){
            return m_Num1 + m_Num2 ;
        }else if(oper == "-" ){
            return m_Num1 - m_Num2 ;
        }else if(oper == "*" ){
            return m_Num1 * m_Num2 ;
        }else if(oper == "/" ){
            return m_Num1 / m_Num2 ;
        }

        return 0 ;
    }

    int m_Num1 , m_Num2 ;

};

void test01()
{
    Calculator c ;
    c.m_Num1 = 10 ;
    c.m_Num2 = 20 ;

    cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl ;
    cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl ;
    cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl ;
    cout << c.m_Num1 << " / " << c.m_Num2 << " = " << c.getResult("/") << endl ;
}

int main()
{
    test01() ;

    return 0 ;
}
