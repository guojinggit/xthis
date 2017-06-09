//
// Created by Administrator on 2017/6/6.
//

#include <iostream>


//求数字转换成二进制后包含1的个数

//这是一种错误的解法，遇到负数就是死循环
int bit_op(int data){
    int count = 0;
    while (data) {
        if (data & 1)
            ++count;
        data = data >> 1;
    }
    return count;
}

//修复上面的bug
int bit_op_fix(int data) {
    int count = 0;
    unsigned int flag = 1;
    while (flag) {
        if (flag & data)
            ++count;
        flag = flag << 1;
    }
    return count;
}

//精简的解法
int bit_op_(int data) {
    int count = 0;
    while (data){
        data = data & (data -1);
        ++count;
    }
    return count;
}

int main(){

    std::cout << bit_op_(-2) << std::endl;
}