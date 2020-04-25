#include <iostream>
#include <algorithm>

using namespace std;


const int INCRGAP = 3;//步长

template<typename T>
void shellsort(T array[], int len) {
    int w = 1;   //宽度w
    while (w < len / INCRGAP) 
    {
        w = INCRGAP * w + 1; //注意如果当len<INCRGAP时，w为0，所以为了保证进入循环，w至少为1
    }
    //找到一个宽度递增的序列w
    while (w >= 1) //直到宽度为1
    {
        for (int i = w; i < len; i++) // 分组，在每个子序列中进行插入排序
        //此处i为什么等于w呢？是因为假设第一行已经是有序的，也就是每一列的第一个元素
        //对于后面所有的元素，都要进行插入操作，插入操作是一个个分组来的
        {
            for (int j = i; j >= w && array[j] < array[j - w]; j -= w) //每轮流到一个元素，就开始沿着列找到合适的位置插入进去
            {
                swap(array[j], array[j - w]); //不断借助交换空间进行交换，插入到合适的位置
            }
        }
        w = w / INCRGAP; //递减增量
    }
}
int main() {

    int array[] = {3, 1, 7, 5, 2, 4, 6};
    int len = (int) sizeof(array) / sizeof(*array);   
    for (int i = 0; i < len; i++)
        cout << array[i];
    cout << endl;
    shellsort(array,len);
    for (int i = 0; i < len; i++)
        cout << array[i] ;
    cout << endl;
    return 0;
}
