/*
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

例如，121 是回文，而 123 不是。
*/
bool isPalindrome(int x)
{
   if( x<0 || (x % 10 == 0 && x > 0) )
   // less than 0  -> certainly not. for it has sign " - "
   // bigger than 0 , end as 0 -> not .for no one is begining with "0"
   return false ;

   int num ;
   for(  num = 0 ; num < x ; x /= 10 )
   {
       num *= 10 ;
       num += x % 10 ;
       
   }

   return (num == x || num/10 == x ) ;
}