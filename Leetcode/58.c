/*
58. 最后一个单词的长度
给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。

单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。

*/
int lengthOfLastWord(char * s){
    int count=0;
    int i=0;
    while(s[i]!='\0')
    {
        //遇到空格就跳过
        while(s[i]==' ')
        {
            i++;
        }
        if(s[i]=='\0')
        {
            break;
        }

        //不是空格就是单词，开始计数
        count=0;
        while(s[i]!=' '&&s[i]!='\0')
        {
            count++;
            i++;
        }
        if(s[i]=='\0')
        {
            break;
        }

        i++;
    }
    return count;
}