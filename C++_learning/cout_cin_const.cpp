#include <iostream>
#include <iomanip>
//#include "learn2.h"


using namespace std;
// using namespace learn2; //为了避免名称冲突
                     //应该在源文件中使用using namespace std;
                     //而不是在头文件中使用。
/*标准命名空间std包含了C++标准库中的所有标识符
例如cout、cin、endl等等
如果不使用using namespace std;
在代码中使用这些标识符时必须要加上std::前缀
例如std::cout、std::cin、std::endl等。*/
int main() 
{

    int i ;
    float f ;
    cin >> i >> f ;// i first , then f.
    cout << f << i;
   
    //cin / cout : from left to right.
    return 0;

    /*
    // setw(10) : set width of cout : 10  (#include <iomanip>)
    cout << setw(10) << "Name" << setw(10) << "Age" << endl;
    cout << setw(10) << "Alice" << setw(10) << 25 << endl;
    cout << setw(10) << "Bob" << setw(10) << 30 << endl;
    return 0;
    
     cout :
      Name       Age
     Alice        25
       Bob        30
    */
}
//const可以与指针一起使用，它们的组合情况复杂，可归纳为3种：指向常量的指针、常指针和指向常量的常指针。

////指向常量的指针：一个指向常量的指针变量。

const char* pc = "abcd";
//该方法不允许改变指针所指的变量，即
    pc[3] = ‘x';   是错误的，
但是，由于pc是一个指向常量的普通指针变量，不是常指针，因此可以改变pc所指的地址，例如
    pc = "ervfs";
该语句付给了指针另一个字符串的地址，改变了pc的值。

////常指针：将指针变量所指的地址声明为常量

char* const pc = "abcd";
创建一个常指针，一个不能移动的固定指针，可更改内容，如
    pc[3] = 'x';
但不能改变地址，如
    pc = 'dsff';  不合法

////指向常量的常指针：这个指针所指的地址不能改变，它所指向的地址中的内容也不能改变。

const char* const pc = "abcd";