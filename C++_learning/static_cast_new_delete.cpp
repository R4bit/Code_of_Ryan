#include <iostream>
using namespace std ;

int main()
{
    void* pc;
    //pc = (int*)( malloc(sizeof(int)) );// won't chang "pc" ptr itself./just malloc .
    
    pc = static_cast<int* >( static_cast<int* >(malloc(sizeof(int))) );
    // every "static_cast" need a "( )" behind.
    
/*
这两行代码的主要区别在于内存分配函数 malloc 的返回值类型和 static_cast 的使用方式。

第一行代码 pc = static_cast<int*>(malloc(sizeof(int))); 
将 malloc 的返回值直接转换为 int* 类型的指针，这是不安全的做法，因为 malloc 返回的指针类型是 void*，它不具有类型安全的属性，可能导致程序错误或崩溃。

第二行代码 pc = static_cast<int*>(static_cast<void*>(malloc(sizeof(int)))); 
先将 malloc 的返回值转换为 void* 类型的指针，再将其转换为 int* 类型的指针。这样做的好处是显式地将 void* 类型的指针转换为目标类型的指针，可以确保类型安全，并减少潜在的错误。

因此，建议使用第二种方式分配动态内存，并进行类型转换，以确保程序的健壮性和可维护性。
*/
    int i = 123;
    char c = 'a';
    pc = &i;
	cout << pc << endl;         //输出指针地址006FF730
	cout << *static_cast<int*>( pc ) << endl;
    int *arr = new int[7] ;
    delete arr ;
//static_cast<int*>(.......) 
//是 C++ 中的一个强制类型转换运算符
//它在编译时执行类型检查，确保类型转换的安全性
//如果类型转换不安全，则会产生编译错误。
}
/*
int* pi = new int;
int* pa = new int[10];

delete pi;
delete[] pa;
注意，释放数组时需要使用 delete[] 运算符
而不是 delete 运算符。
*/
 