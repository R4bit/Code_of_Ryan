/*
public成员可以被任何代码访问，包括类的成员函数、类的对象以及外部代码。
通常，public成员是表示类的接口的一部分，供外部代码使用。

protected成员可以被类的成员函数和类的派生类的成员函数访问，但不能被外部代码访问。
通常，protected成员是表示类的实现的一部分，供类的派生类使用。

private成员只能被类的成员函数访问，不能被类的派生类的成员函数或外部代码访问。
通常，private成员是表示类的实现的一部分，但不应该被类的使用者直接访问。
*/
#include <iostream>
using namespace std ;
class Animal {
public:
    void Eat() { cout << "Animal is eating." << endl; }
public:
    int age;
protected:
    string name;
private:
    int weight;
};

class Cat : public Animal  // 公有派生

/*在C++中，派生类可以访问其基类的protected成员，
但不能访问其基类的private成员。
因此，如果将Animal类定义为public继承，
那么Cat类就可以访问Animal类的protected成员，
但不能访问Animal类的private成员。

如果将Animal类定义为private继承， // 私有派生
那么Cat类就不能直接访问Animal类的任何成员*/
 {
public:
    void Meow() { cout << "Cat is meowing." << endl; }
public:
    string color;
protected:
    int numOfLives;
private:
    bool isCute;
};

int main() {
    Animal animal;
    animal.Eat();
    animal.age = 3;

    Cat cat;
    cat.Eat();
    cat.Meow();
    cat.age = 2;
    cat.color = "gray";
    return 0;
}