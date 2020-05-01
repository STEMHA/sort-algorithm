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
[C++ STL sort 函数的用法](https://www.cnblogs.com/lrj124/p/7254043.html)
