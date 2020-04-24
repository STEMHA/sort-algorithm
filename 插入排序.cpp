//插入排序
//平均时间复杂度O(n^2),主要来源于二重循环和插入位置的寻找
//总结起来就是，一个空间的副本，假设第一个位置是有序的，从第二个位置开始不断向第一个位置插入，插入到大于或等于副本值的数的后一个位置

# include <iostream>
using namespace std;

void insertionsort(int * array,int len)
{
        for(int i=1;i<len;i++)
        {
                int key=array[i];  //要插入的哪个数，拉出来备份，
                int j; //找到比插入的数小的数或者等于
                for(j=i-1;j>=0 && key<array[j];j--)
                        array[j+1]=array[j];  //一个个的移位
                 //比插入的数小或者等于的数的后面一个位置可以覆盖
                array[j+1]=key;//最后空出的位置填上key 
        }
}

int main()
{

//...
int array[] = {3, 1, 7, 5, 2, 4, 6};
for (int i = 0; i < 7;i++)
{
    cout << array[i];
}
cout << endl;
insertionsort(array, 7);
for (int i = 0; i < 7;i++)                                   
{
    cout << array[i];
}
    cout << endl;
}
