/*
20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
*/
char pairs(char a) {
    if (a == '}') return '{';
    if (a == ']') return '[';
    if (a == ')') return '(';
    return 0;
}


bool isValid(char * s)
{
    int n = strlen(s) ;
    if(n % 2 == 1)
    {
       return false ;
    }
    int steak[ n+1 ] ;
    int  top = 0;  //now top is at position "0" of steak.
    for(int i = 0 ; i < n ; i ++)
    {
       char ch = pairs(s[i]) ;
       if(ch)
       {   
         if(top == 0 || steak[top-1] != ch)
        {
           return false ;
        }
        top -- ;
       }
       else
       {
       steak[top++] = s[i] ;
       }
       
    }
    return top == 0 ;
}