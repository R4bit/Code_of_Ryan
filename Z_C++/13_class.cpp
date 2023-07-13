#include <iostream>
#include <string>

using namespace std ;

class person
{
private:
    int age ;
    string name ;

public:
    void setName(string input)
    {
        name = input ;
    }

    void setAge(int input)
    {
        age = input ;
    }

    void display()
    {
        cout << "Name : " << name << endl ;
        cout << "Age : " << age << endl ;
    }
};

int main()
{
    person me ;
    
    me.setName("Mr.Liu" ) ;
    me.setAge(19 ) ;

    me.display() ;


    system("pause") ;
    system("cls") ;
    return 0 ;
}