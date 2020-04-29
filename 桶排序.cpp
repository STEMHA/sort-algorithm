//1. 构造节点，构造函数
//2. 分配足够多的的哈希位置，512个 也就是一个字节的两倍，然后全部初始化为0，memset（）
//3. 准备好基础指针，哈希表的移动指针，和创建新节点所用的指针
//4.计算偏移量，也就是哈希，利用右移24位获得数值的高8位来做哈希
//5.根据值创建节点
//6.找到合适的位置，如果位置是空的，把节点链接上去
//7.如果不是空的，先比较首部节点，如果小于等于则插入到它之前，如果不是，下一步
//8. 依次遍历拉链后面的节点，找到小于或等于的节点，插入到之前，循环条件是p->next!=null 跳出循环后则表明没有找到，则新节点是最大的，擦汗如到最后



#include <iostream>
#include<memory.h>
using namespace std;

struct tNode
{
    int tValue; 
    tNode *next; 

    tNode(int val)         //构造函数是没有返回值的
    {
        this->tValue = val;
        this->next = NULL;
    }
};



bool bucketsort(int *array, const int len)
{
    //分配512个指针指向tnode变量，然后pnode是指向*tnode的指针变量
    tNode **pNode = new tNode*[512];//等同于(tNode **)malloc(sizeof(tNode *) * 512);
    if (NULL == pNode)
        return false;

    memset(pNode, 0, sizeof(tNode *) * 512);//512个指针变量都初始化为空的,这是按字节覆盖的

    int shiftNum = 0;    //要排序的数在表中的偏移量
    tNode *p = NULL;    //用于找到偏移量所指向的那个位置的指针
    tNode *pNewNode = NULL; //用于创建一个数值的节点

    for (int i = 0; i < len; ++i)  //
    {
        shiftNum = array[i] >> 24;  //右移24位,4个字节，1个字节是8位。所以第一次右移24位，把最前面8位（第25-32位）的移到第1-8位
        p = pNode[shiftNum];  //根据高位找到合适的插入位置

        pNewNode = new tNode(array[i]);  //根据数值创建一个节点
        if (NULL == pNewNode)
            return false;

        if (NULL == p)  //如果哈希表那个位置还没有任何一个节点（也就是指针为空）
        {
            pNode[shiftNum] = pNewNode;  //就将刚创建的新的节点分配给它
        }
        else if (array[i] <= p->tValue)  //如果已经有了首节点，就需要找合适的位置了，如果小于等于，就插在之前
        {
            pNode[shiftNum] = pNewNode; 
            pNewNode->next = p;
        }
        else  //对于后面的情况，也就是第一个结点之后了，从第二个节点开始看
        {
            while (NULL != p->next) //第一个节点之后的节点
            {
                if (array[i] > p->next->tValue) //如果大于
                    p = p->next;   //就接着找后面的
                else       //一旦找到不大于的，就跳出插入
                    break; 
            }
            //或者遍历到最后一个时候，也没招到不大于的
            pNewNode->next = p->next;  //
            p->next = pNewNode;   //
        }
    }

    for (int i = 0, k = 0; i < 512; i++) //遍历哈希表
    {
        p = pNode[i];

        while (NULL != p) //如果当前指针不为空，就将拉链输入到原来数组
        {
            array[k++] = p->tValue; //这里的k不用管，数目肯定是对的
            p = p->next;
        }
    }

    return true;
}

int main() {

    int array[] = {3, 1, 7, 5, 2, 4, 6};
    int len = (int) sizeof(array) / sizeof(*array);    //计算数组的长
        for (int i = 0; i < len;i++)
    {
    cout << array[i];
    }
    cout << endl;
    if(bucketsort(array, len))
    {

    }
    for (int i = 0; i < len;i++)
    {
    cout << array[i];
    }
    cout << endl;
}
