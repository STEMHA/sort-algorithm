
//快速排序算法，画个图就知道了
//比方 3175246 的数组
//辅助空间tmp，把第一个数作为基准转移到辅助空间，此时p指向第一个数
// 右边的q中的数覆盖掉p中的数，
// 左边的p中的数覆盖掉q中的数
//循环结束后
// tmp的数再移动到p


# include <iostream>

using namespace std;

void quicksort(int *array,int first,int last)
{
    if(first<last)
    {
        int tmp = array[first]; //区间的第一个数作为基准数目
        //同时tmp还是一个辅助空间！
        int p = first; //左边第一个数
        int q = last;  //右边最后一个数目
        
        //第一个位置就是一个辅助空间。
        while(p<q)

        {
            //当右边的数大于基准数的时候
            while(p<q && array[q]>tmp) 
                q--;  //指向的数的索引不断向左移，最终的索引是右边的小于基准的第一个p数
            //
            array[p] = array[q]; // 将小于基准的数与基准数的位置对调  q移到p
            
            //当左边的数小于基准数的时候
            while(p<q && array[p]<=tmp) 
                p++;   //指向的数的索引不断向右移，最终的索引是左边的大于基准的第一个数
            
            array[q] = array[p]; //将大于基准的数与基准数的位置对调     p移到q

            //数组p这时候存的值在数组q之间也有一部分，所以可以覆盖
        }
        array[p] = tmp; //因为被覆盖了，所以重新填一下，
        

        //上面这样做的结果是一个数组，数组中基准数找到了他的位置
        quicksort(array, first, p - 1);
        quicksort(array, p + 1, last);
    }
    else
        return;

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
quicksort(array, 0, 6);
for (int i = 0; i < 7;i++)
{
    cout << array[i];
}
cout << endl;
}
