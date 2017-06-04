//
// Created by Administrator on 2017/6/3.
//


#include <iostream>

//将空格替换成"%20"
//假设字符串空间足够
char* replace_space(char* str){
    /*首先判断参数*/
    if (!str)
        return NULL;

    /*记录首地址*/
    char* pBk = str;

    /*然后遍历str,寻找有多少个*/
    int spaceNum  = 0;
    int totalSize = 0;
    int strSize   = 0;
    char* pStr  = str;

    for(int i = 0;*(pStr+i);++i) {
        if (*(pStr+i) == ' ')
            ++spaceNum;
        ++strSize;
    }

    totalSize = strSize + spaceNum*2;

    /*现在，str和pStr分别指向末尾*/
    str  += strSize  - 1;
    pStr += totalSize -1;
    /*然后从后面到前*/
    for(;spaceNum > 0;) {
        if (*str == ' ') {
            *pStr-- = '0';
            *pStr-- = '2';
            *pStr-- = '%';
            --spaceNum;
        } else
            *pStr-- = *str;
        --str;
    }
    return pBk;
}


char* replace_space_2(char* str) {
    if (!str)
        return NULL;

    char* newStr = new char[100];
    char* pStr = newStr;

    for (; *str; ++str) {
        if (*(str) == ' '){
            *(pStr++) = '%';
            *(pStr++) = '2';
            *(pStr++) = '0';
        } else
            *(pStr++) = *(str);
    }

    return (char*)newStr;
}

int main(){
    char str[100] ="  i step xx ";
    std::cout << replace_space_2(str) << std::endl;
    return 0;
}
