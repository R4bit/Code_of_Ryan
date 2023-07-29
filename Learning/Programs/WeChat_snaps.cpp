/*
This c++ program shows coherently_aoto sent Wechat news.
*/
#include <iostream>
#include <windows.h>

using namespace std ;

int main()
{
    u_int repeatNum = 0 ;
    cout << "input repeat times that u need : " << endl;
    cin >> repeatNum ;


    // find window : ( using [spy++] )
    HWND WeChatWindow = FindWindow("WeChatMainWndForPC" , "微信") ; // 003204F6
    cout << "这是微信所在窗口的句柄：" << WeChatWindow << endl ;

    if(repeatNum <= 0)
        return 0 ;

    // set Window topMost :
    SetWindowPos(WeChatWindow , HWND_TOPMOST , 0 , 0 , 0 , 0 , SWP_NOMOVE|SWP_NOSIZE) ;

    // get position :
    RECT RectWeChat ;
    GetWindowRect(WeChatWindow , &RectWeChat) ;


    // BEGAN :
    for( int i = 0 ; i < repeatNum ; i ++ )
    {
        // move Cursor :
        SetCursorPos(RectWeChat.left + 427 , RectWeChat.top + 433) ;
    
        // imitate cursor tap :
        mouse_event(MOUSEEVENTF_LEFTDOWN , 0 , 0 , 0 , 0) ;
        mouse_event(MOUSEEVENTF_LEFTUP , 0 , 0 , 0 , 0) ;
    
        // input( using paste) :
        keybd_event(VK_CONTROL , 0 , 0 , 0) ;
        keybd_event('V' , 0 , 0 , 0) ; // need Capital LETTER as perameter!!!
    
        keybd_event('V' , 0 , KEYEVENTF_KEYUP , 0) ;
        keybd_event(VK_CONTROL , 0 , KEYEVENTF_KEYUP , 0) ;
    
        // sent message :
        SetCursorPos(RectWeChat.left + 618 , RectWeChat.top + 470) ;
    
        mouse_event(MOUSEEVENTF_LEFTDOWN , 0 , 0 , 0 , 0) ;
        mouse_event(MOUSEEVENTF_LEFTUP , 0 , 0 , 0 , 0) ;
    
        Sleep(2) ;
    }

    // window restore : ( cancel window topMost )
    SetWindowPos(WeChatWindow , HWND_NOTOPMOST , 0 , 0 , 0 , 0 , SWP_NOMOVE|SWP_NOSIZE) ;
    cout << "Demostration over......" << endl ;


    return 0 ;
}