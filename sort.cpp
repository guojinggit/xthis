//
// Created by Administrator on 2017/6/5.
//

#include <iostream>


//快速排序

//递归，注意栈溢出


void quickSort(int data[],int start,int end) {
    if (!data || start < 0 || end < 0 || end < start)
        return;

    int i = start;
    int j = end;
    int dataTmp = data[start];

    while (i < j) {
        while (i < j && data[j] >= dataTmp )
            j--;
        data[i] = data[j];

        while (i < j && data[i] <= dataTmp)
            i++;
        data[j] = data[i];
    }
    data[i] = dataTmp;

    if (start < i -1)
        quickSort(data, start,i-1);
    if (end > i+1)
        quickSort(data,i+1, end);

    return;
}



int main(){
    int data[10] = {4,8,9,2,11,18,61,6,1,8};
    quickSort(data,0,9);
    for (int i =0 ; i < 10;++i)
        std::cout << data[i] << std::endl;
    return 0;
}






