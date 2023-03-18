/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。
*/
char * longestCommonPrefix(char ** strs, int strsSize){
    
    int  i , j , len , val , flag ;
    len = strlen( strs[0] ) ;
    char* prefix = (char*)malloc((len+1) * sizeof(char)) ;
    memset(prefix, '\0', (len + 1) * sizeof(char));  // 初始化为'\0'
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