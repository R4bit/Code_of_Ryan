#include <iostream>
#include <iomanip>

using namespace std;
// using namespace learn2; //为了避免名称冲突
                     //应该在源文件中使用using  namespace std;
                     //而不是在头文件中使用。
/*标准命名空间std包含了[C++标准库]中的所有标识符
例如cout、cin、endl等等
如果不使用using namespace std;
在代码中使用这些标识符时必须要加上std::前缀
例如std::cout、std::cin、std::endl等。*/
int main() 
{

    int i ;
    float f ;
    cin >> i >> f ;// from left to right !
    cout << "\n" << i << "\n" << f << "\n\n" ;// from left to right !
 
    cout << "hello" << endl ;
    cout << 'h' << endl ;
    cout << '1' << endl ;
    cout << 123 << endl ;


    float f1 = 1.23456789 ;
    float f2 = 1.23456789f ;
    float f3 = 1e2 ; // f3 = 100 = 1 x 10的二次方

    cout << "f1 = " << f1 << "\n" << endl ;
    cout << "f2 = " << f2 << "\n" << endl ;
    cout << "f3 = " << f3 << "\n" << endl ;
    cout << "size of float : " << sizeof(float) << "\n" << endl ;

    double d1 = 1.23456789 ;
    
    cout << "d1 = " << d1 << "\n" << endl ;
    cout << "size of double : " << sizeof(double) << "\n" << endl ;


    // all above have only "6" nums. 
   
    return 0;

}