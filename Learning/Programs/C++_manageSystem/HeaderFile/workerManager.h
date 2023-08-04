#pragma once // 防止“.h”文件被重复包含
#include <iostream>
#include <string>
using namespace std ;


class WorkerManager
{
public:
    WorkerManager() ;

    void ShowMenu() ;

    void exitSystem() ;

    ~WorkerManager() ;
};

class Worker // 是个抽象类，因为内有纯虚函数
{
public:
    // 纯虚函数
    virtual void showInfo() = 0 ;

    virtual string getDeptName() = 0 ;

    int m_Id ;
    string m_Name ;
    int m_DeptId ;

};