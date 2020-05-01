我们可以用STL库中的函数或者容器实现排序的需求
- sort 在 <algorithm>库里面
```cpp
template <class RandomAccessIterator>
 void sort ( RandomAccessIterator first, RandomAccessIterator last );    //默认升序的，比较函数是小的为true
template <class RandomAccessIterator, class Compare>
 void sort ( RandomAccessIterator first, RandomAccessIterator last, Compare comp );  //比较函数可以自己定义，
 //前两个参数是起始地址和中止地址
 //第三个参数是一个比较函数
 //如果想实现降序函数，可以使用返回值是大的为true的比较函数，比如
 bool cmp(int a,int b) { return a > b; }
```
当然比较函数的模板也已经有写好的啦，就是：
- greater 升序比较函数  
- less 降序比较函数  
```cpp
sort(a,a+n,greater<int>()); //升序
sort(a,a+n,less<int>()); //降序，注意尖括号内写的是排序的数组类型
```
 并非所有容器都使用（能用、适用）sort算法，既然问的是STL的sort算法实现，那么先确认一个问题，哪些STL容器需要用到sort算法？  
1. 首先，关系型容器（map、set、multimap、multiset）拥有自动排序功能，因为底层采用红黑树（RB-Tree），所以不需要用到sort算法。  
2. 其次，序列式容器中的stack、queue和priority-queue都有特定的出入口，不允许用户对元素排序。  
3. **剩下的vector、deque，适用sort算法**。    
4. 实现逻辑:STL的sort算法，数据量大时采用QuickSort快排算法，分段归并排序。一旦分段后的数据量小于某个门槛（16），为避免QuickSort快排的递归调用带来过大的额外负荷，就改用Insertion Sort插入排序。如果递归层次过深，还会改用HeapSort堆排序。
 
[C++ STL sort 函数的用法](https://www.cnblogs.com/lrj124/p/7254043.html)
[十大排序算法的实现以及各自的优缺点、适用情况](https://blog.csdn.net/derbi123123/article/details/104318134)
