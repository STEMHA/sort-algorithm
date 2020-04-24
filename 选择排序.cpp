#include <iostream>
#include <algorithm>
using namespace std;



//开始的时候，有序后缀是空的,从无序前缀中找到最大的交换到有序后缀的开头。
template<typename T> 
void selectionsort(T array[],int len ) {
    for (int i = len-1; i>0; i--)  
    { //有序的不断移到后缀中 
        int max = i;//假定最大值是无i序前缀的第一个 
        for (int j = i-1; j >= 0; j--)
            if (array[j] > array[max])
                max = j;
        swap(array[i], array[max]);  //swap里面使用了辅助空间
    }
}
int main() {

    int array[] = {3, 1, 7, 5, 2, 4, 6};
    int len = (int) sizeof(array) / sizeof(*array);    //计算数组的长
        for (int i = 0; i < len;i++)
    {
    cout << array[i];
    }
    cout << endl;
    selectionsort(array, len);
    for (int i = 0; i < len;i++)
    {
    cout << array[i];
    }
    cout << endl;
}
