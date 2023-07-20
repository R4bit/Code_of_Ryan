/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。
*/
char * longestCommonPrefix(char ** strs, int strsSize){
    
    int  i , j , len , val , flag ;
    len = strlen( strs[0] ) ;
    char* prefix = (char*)malloc((len+1) * sizeof(char)) ;
/*Important*/memset(prefix, '\0', (len + 1) * sizeof(char));  // 初始化为'\0'
/*
例如有一个结构体Some x，可以这样清零：

memset( &x ,0,sizeof(Some));   //X是单独的变量就要用&

如果是一个结构体的数组Some x[10]，可以这样：

memset( x ,0,sizeof(Some)*10); //X是数组就不要用&，数组名就是地址喽
*/   
    for(i = 0 ; i < len ; i++ ){
        flag = 0 ;
        for(j = 0 ; j < strsSize-1 ; j++){
            if(strs[j][i] != strs[j+1][i]){
               flag++ ;
               break ;
            }
        }
        if(flag == 1){
            break ;
        }
        prefix[i] = strs[0][i] ;
    }
    return prefix ;
}