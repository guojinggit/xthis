//
// Created by Administrator on 2017/6/5.
//

#include <iostream>
#include <stack>

#define fail_return_null

template <typename T>
class MQue{
public:
    MQue(){}
    ~MQue(){}

    void push(const T& t);
    T pop fail_return_null();
private:
    std::stack<T> s1;
    std::stack<T> s2;
};

template <typename T>
void MQue<T>::push(const T &t) {
    s1.push(t);
}

template <typename T>
T MQue<T>::pop()  {
    /*如果s2为空，就从s1去拿*/
    if (s2.size() <=0 ) {
        while (s1.size() > 0) {
            T& t = s1.top();
            s1.pop();
            s2.push(t);
        }
    }
    /*如果此时s2依然为空，那么就返回一个NULL吧*/
    if (s2.size() <=0 )
        return NULL;

    T t = s2.top();
    s2.pop();
    return t;
}

int main() {

    MQue<int> que;
    que.push(1);
    que.push(2);
    std::cout << que.pop() << std::endl;
    return 0;
}