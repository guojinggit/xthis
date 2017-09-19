//
// Created by Administrator on 2017/6/6.
//

#include <iostream>

//递归实现，简洁，但是效率低有溢出风险
int fibonacii(unsigned int n){
    int result[2] = {0,1};
    if (n <=1)
        return result[n];

    return fibonacii(n-1) + fibonacii(n-2);
}

//循环实现

int fibonacii_2(unsigned int n){
    int result[2] = {0,1};
    if (n <= 1)
        return result[n];
    int sum = 0;
    int f1 = 0;
    int f2 = 1;
    for (int i = 2; i <= n; ++i) {
        sum = f1 + f2;
        f1 = f2;
        f2 = sum;
    }
    return sum;
}



int main(){
    //fibonacii
    std::cout << fibonacii(5) << std::endl;
    return 0;
}