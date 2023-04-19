// first problem solved by C++ !!!
/*
66. 加一
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() ;
        // traverse from tail of vector 
        for(int i = n - 1 ; i >= 0 ; i --){

            // if != 9 , means need to Carry !
            if(digits[i] != 9 ){
                digits[i] ++ ;

                // then , allocate 0 to element after the one been carried :
                for(int j = i+1 ; j < n ; j ++ ){
                    digits[j] = 0 ;

                }
                return digits ;

            }

        } // for   over

        // if case : 999999999999 :
        vector<int> retunner(n + 1) ;
        fill(retunner.begin() , retunner.end() , 0 ) ;
        retunner[0] = 1 ;
        
        return retunner ;

    } // plusOne over



};