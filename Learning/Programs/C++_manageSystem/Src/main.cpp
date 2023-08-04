#include <iostream>
#include "workerManager.h"
#include "workerManager.cpp"
using namespace std ;

int main()
{   
    WorkerManager wm ;
    
    int choiceNumber = 0 ;
    while(1)
    {
        wm.ShowMenu() ;
        cout << "input your choice : " << endl ;
        cin >> choiceNumber ;

        switch ( choiceNumber )
        {
        case 0: // quit
            wm.exitSystem() ;
            break;
        case 1: // add
            
            break;
        case 2: // show
            
            break;
        case 3: // delete
            
            break;
        case 4: // edit
            
            break;
        case 5: // search
            
            break;
        case 6: // sort

            break;
        case 7: // clear all

            break;
        default:
            system("cls") ;
            break;
        }   
    }



    system("pause") ;
    return 0 ; 
}