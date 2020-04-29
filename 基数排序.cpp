#include <iostream>
#include<memory.h>
# include<algorithm>
using namespace std;
 
 
 int maxbit(int array[], int len) //辅助函数，求数据的最大位数
{
    int maxarray = *max_element(array, array + len);  //先求最大值

    int digitcapacity=0;
    while (maxarray != 0)
    {
        
        maxarray /= 10;  //不断除以十直到0
        ++digitcapacity;//位数不断加1
    }
    return digitcapacity;
}
void radixsort(int array[], int len) //基数排序
{
    int d = maxbit(array, len);
    int *tmp = new int[len];  //分配一个额外的数组
    int *count = new int[10]; //计数器
    int i, j, k;
    int radix = 1;
    for(i = 1; i <= d; i++) //进行d次排序 从个位开始
    {
        for(j = 0; j < 10; j++)
            count[j] = 0; //每次分配前清空计数器
        for(j = 0; j < len; j++)
        {
            k = (array[j] / radix) % 10; //统计每个桶中的记录数
            count[k]++;
        }
        for(j = 1; j < 10; j++)   //与计数排序一样，根据count计算出合适的位置
            count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
        for(j = len - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中，
        {
            k = (array[j] / radix) % 10;  
            tmp[count[k] - 1] = array[j];  //数据复制到临时数组中去
            count[k]--;
        }
        for(j = 0; j < len; j++) //将临时数组的内容复制到array中，然后准备下一轮
            array[j] = tmp[j];
        radix = radix * 10; //基数变大了，10倍的移动
    }
    delete []tmp;
    delete []count;
}
int main() {

    int array[] = {3, 1, 7, 5, 2, 4, 6};
    int len = (int) sizeof(array) / sizeof(*array);    //计算数组的长
        for (int i = 0; i < len;i++)
    {
    cout << array[i];
    }
    cout << endl;
    radixsort(array, len);

    for (int i = 0; i < len;i++)
    {
    cout << array[i];
    }
    cout << endl;
}
