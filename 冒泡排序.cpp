
# include <iostream>
using namespace std;


//非降序排列
void bubblesort(int *array, int n)
{
    bool sorted = false; //是否整体排序完毕的标志

    while(!sorted)
    {
        sorted = true;  //假设以及整体排序了
        for (int i = 1; i < n;i++)
        {
            if(array[i-1]>array[i])
            {
                swap(array[i - 1], array[i]); //交换后整体性不能够保证的
                sorted = false;
            }
        }
        n--;//末尾元素肯定是就位的，每扫描交换一趟就会就位一个
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
bubblesort(array,7);
for (int i = 0; i < 7;i++)
{
    cout << array[i];
}
cout << endl;
}