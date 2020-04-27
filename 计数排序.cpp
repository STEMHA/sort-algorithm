
#include <iostream>
#include <algorithm>
using namespace std;

//辅助数组最终存储的是位置映射，还需要减一；
template<typename T>
T * countsort(T array[],int len)
{
    T max = *max_element(array, array + len);
    T min = *min_element(array, array + len);
    int k = max - min + 1;
    T *auxiliaryspace = new T[k]();  //辅助空间初始化为0；
    for (int i = 0; i < len;i++)  //扫描以便要排序的序列进行统计
    {
        auxiliaryspace[array[i] - min]++;   //将对应值存放到数组的相应位置，数组的下标等于值与min的差
    }
    for (int i = 1; i < len;i++)    //更正位置，对应值应该放在数组的对应位置
    {
        auxiliaryspace[i] = auxiliaryspace[i] + auxiliaryspace[i - 1];
    }
    T *targetarr = new T[len]; //最终排序后的数组
    for (int i = len-1; i>=0;i--)    //反向填充目标数组
    {
        int countIndex = array[i] - min;  //对应值的对应位置
        targetarr[auxiliaryspace[countIndex] - 1] = array[i]; //因为是次数的缘故，需要减1得到数据位置
        auxiliaryspace[countIndex] -= 1;
    }
    delete[] auxiliaryspace;
    return targetarr;
}

int main()
 {
    int array[] = {3, 1, 7, 5, 2, 4, 6};
    int len = (int) sizeof(array) / sizeof(*array);   
    for (int i = 0; i < len; i++)
        cout << array[i];
    cout << endl;
    int *targetarr=countsort(array,len);
    for (int i = 0; i < len; i++)
        cout << targetarr[i] ;
    cout << endl;
    return 0;
}
