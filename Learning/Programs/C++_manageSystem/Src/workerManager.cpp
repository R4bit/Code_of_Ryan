#include "include.h"

//把“.h”文件里的构造函数、析构函数补全：
WorkerManager::WorkerManager()
{
    cout << "1构造函数" << endl ;
}

void WorkerManager::ShowMenu()
{
    cout<< "-------------------------------------" << endl ;
    cout<< "-------欢迎使用职工管理系统！--------" << endl ;
    cout<< "------------0.退出-------------------" << endl ;
    cout<< "------------1.增加员工信息-----------" << endl ;
    cout<< "------------2.显示员工信息-----------" << endl ;
    cout<< "------------3.删除员工信息-----------" << endl ;
    cout<< "------------4.修改员工信息-----------" << endl ;
    cout<< "------------5.查找员工信息-----------" << endl ;
    cout<< "------------6.按照编号排序-----------" << endl ;
    cout<< "------------7.清空所有文档-----------" << endl ;
    cout<< "-------------------------------------" << endl ;
    cout << endl ;
}

void WorkerManager::exitSystem()
{
    cout << "\nbye~\n" << endl ;
    system("pause") ;
    exit(0) ;
}

WorkerManager::~WorkerManager()
{
    cout << "1析构函数" << endl ;
}