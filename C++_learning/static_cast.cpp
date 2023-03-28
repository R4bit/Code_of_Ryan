#include <iostream>
using namespace std ;

int main()
{
    void* pc;
    pc =static_cast<int*>( malloc(sizeof(int)) );
    //pc = (int*)malloc(sizeof(int));
    int i = 123;
    char c = 'a';
    pc = &i;
	cout << pc << endl;         //输出指针地址006FF730
	cout << pc << endl;
//static_cast<int*>(.......) 
//是 C++ 中的一个强制类型转换运算符
//它在编译时执行类型检查，确保类型转换的安全性
//如果类型转换不安全，则会产生编译错误。
}
 