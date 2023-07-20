#include <iostream>
#include <string>

using namespace std ;

class person
{
private:
    int age ;
    int height ;
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
        cout << "Height : " << height << endl ; 
        cout << "Age : " << age << endl ;
    }

    // construction founction :
    // founction has no return value
    // it's name is same as the class 
    // run auto , and only once.
    // can be with parameter , which means can reloaded
    person(int a , int b ) : age(a) , height(b) 
    {
        cout << "-----------------------------------------" << endl ;
        cout << "| this is initialize founction          |" << endl ;
        cout << "| this founction will run automatically |" << endl ;
        cout << "-----------------------------------------" << endl ;
    }

    // distruction fouction :
    // cannot be with parameter , which means cannot be reloaded.
    ~person()
    {
        cout << "-------------------------------------------------------" << endl ;
        cout << "| this is distruction founction                       |"<< endl ;
        cout << "| this founction will run after 'main' founction over |" << endl ;
        cout << "-------------------------------------------------------" << endl ;
    
    }
};

int main()
{
    person me(199 , 185 ) ;
    
    me.setName("Mr.Liu" ) ;
    me.setAge(19 ) ;

    me.display() ;


    system("pause") ;
    system("cls") ;
    return 0 ;
}