// 注意算法的通常模式，首先是算法的主要思想，先干什么再做什么，是否需要多余的辅助空间，这一切都准备好
//然后，某些函数的参数或者是条件也要准备好，想好如何划分函数和循环
//最后，注意一些边界情况的处理，比如数组靠近边界怎么办，空链表怎么办等情况


#include <iostream>
#include <algorithm>

using namespace std;

template<typename T> //自下而上的迭代
void mergesort_iteration(T array[], int len)
 {
    T* a = array;      
    T* b = new T[len];  //创建一个新的数组副本
    for (int seg = 1; seg < len; seg += seg)   //这是的seg是逐渐翻倍的，从1开始，代表从单个元素的向量开始归并
    {
        //每次的循环，start的位置也是开始变的，每次加两个seg
        for (int start = 0; start < len; start += seg + seg)   //依次两个向量两个向量的归并，并找到两个向量的起始位置
        {
            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);  //这里使用min是怕越界了，可以看作是边界的一种处理方式
            int k = low;
            int start1 = low, end1 = mid;  //拆分为两个子区间
            int start2 = mid, end2 = high;
            //子区间的合并
            while (start1 < end1 && start2 < end2) //比较两个子区间的头部元素，小的输出
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            //如果有一个子区间元素输出完了，则把另一个子区间剩余的元素依次输出即可
            while (start1 < end1) 
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        //当前一轮的归并完成之后，开始下一轮的
        //我们需要互换a和b数组，之前作为辅助空间的数组，现在变成了原数组
        T* temp = a;  //a在每一轮迭代中扮演源数组的角色
        a = b;
        b = temp;
    }
    if (a != array)   //如果a指针最后没指回去，说明a那时候是辅助空间，需要把元素都赋给原来array（也就是现在的b）
    {
        for (int i = 0; i < len; i++)
            b[i] = a[i];
        //赋值完成之后，让b指向a，也就是辅助空间
        b = a;
    }
    delete[] b; //删除辅助空间
}


template<typename T>  //自上而下的递归
void mergesort_recursive_t(T array[], T reg[], int start, int end) //后面两个是数组中元素的起始位置，与结尾位置
{
    if (start >= end)   //递归基，直到还有一个元素的时候停止使用
        return;
    int len = end - start, mid = (len >> 1) + start; //找到起始和中间
    int start1 = start, end1 = mid;  //划分为两个部分，都是闭区间
    int start2 = mid + 1, end2 = end;
    mergesort_recursive_t(array, reg, start1, end1);  //归并子区间
    mergesort_recursive_t(array, reg, start2, end2);
    int k = start;   //开始合并两个子区间，把合并的
    while (start1 <= end1 && start2 <= end2) //
    {       //比较两个子区间的头部元素，小的输出
            reg[k++] = array[start1] < array[start2] ? array[start1++] : array[start2++]; 
    }
    //如果有一个子区间元素输出完了，则把另一个子区间剩余的元素依次输出即可
    while (start1 <= end1)  //
        reg[k++] = array[start1++];
    while (start2 <= end2)
        reg[k++] = array[start2++];
    for (k = start; k <= end; k++)  //最终把副本中的元素拷贝回去就行了
        array[k] = reg[k];
}
template<typename T> 
void mergesort_recursive(T array[], const int len) {
    T *reg = new T[len];  //创造用于合并的临时空间
    mergesort_recursive_t(array, reg, 0, len - 1);
    delete[] reg;
}

int main() {

    int array[] = {3, 1, 7, 5, 2, 4, 6};
    int len = (int) sizeof(array) / sizeof(*array);   
    for (int i = 0; i < len;i++)
    {
    cout << array[i];
    }
    cout << endl;
    mergesort_recursive(array,len);
    for (int i = 0; i < len; i++)
        cout << array[i] ;
    cout << endl;
    mergesort_iteration(array,len);
    for (int i = 0; i < len; i++)
        cout << array[i] ;
    return 0;
}
