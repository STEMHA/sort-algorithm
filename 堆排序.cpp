#include <iostream>
#include <algorithm>
using namespace std;
//使用数组存储一个完全二叉堆    

//最大堆调整（Max Heapify）：将堆的末端子节点作调整，使得子节点永远小于父节点
//下滤操作:用于删除堆顶后，使用堆尾的元素移到堆顶，然后进行下滤操作
void max_heapify(int arr[], int start, int end)
{    
    //堆顶的序号是0，所以左孩子是dad * 2 + 1，右边孩子是dad * 2 + 2
    int dad = start; //初始化父顶点，指向栈顶 ，堆顶的序号是0
    int son = dad * 2 + 1; //父顶点左孩子
    while (son <= end) { //子节点指标在范围内才做比较
        if (son + 1 <= end && arr[son] < arr[son + 1]) //比较两个子节点大小，选择最大的
            son++;  //选择最大的孩子与父亲比较
        if (arr[dad] > arr[son]) //如果父节点大于子节点代表调整完毕，直接跳出函数
            return;
        else { //否則交换父子内容再继续子节点和孙节点比较
            swap(arr[dad], arr[son]);  //下滤是一层层的
            dad = son;
            son = dad * 2 + 1;
        }
    }
}


//二叉堆内部节点的计算，一共是len/2个
//移除位在第一个数据的根节点，并做最大堆调整的递归运算
void heapsort(int arr[], int len) 
{
    //建立完全二叉堆！
    //初始化，i从最后一个父节点开始调整
    //下滤只需要操作所有的内部节点就行了，一共len/2次
    for (int i = len / 2 - 1; i >= 0; i--)  //建立完全二叉堆
        max_heapify(arr, i, len - 1);//每插入一个堆变大一些    

    //先將第一个元素和已经排好的元素前一位做交换，再重调整，(刚调整的元素之前的元素)，直到排序完毕
    for (int i = len - 1; i > 0; i--) 
    {
        swap(arr[0], arr[i]); //取出堆顶，堆尾接替堆顶的位置
        max_heapify(arr, 0, i - 1); //堆的规模变小，对堆顶进行下滤操作
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
    heapsort(array, len);
    for (int i = 0; i < len;i++)
    {
    cout << array[i];
    }
    cout << endl;
}
