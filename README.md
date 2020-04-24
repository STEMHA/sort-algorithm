## 排序算法比较
|排序算法|平均时间复杂度|最佳时间复杂度|最坏时间复杂度|空间复杂度|
|:-|:-|:-|:-|:-|
|冒泡排序|O(n<sup>2</sup>)|O(n)|O(n<sup>2</sup>)|O(1)|
|插入排序|O(n<sup>2</sup>)|O(n)|O(n<sup>2</sup>)|O(1)|
|选择排序|O(n<sup>2</sup>)|O(n<sup>2</sup>)|O(n<sup>2</sup>)|O(1)|
|快速排序|O(n log n)|O(n log n)|O(n<sup>2</sup>)|O(log n)|
|归并排序|O(n log n)|O(n log n)|O(n log n)|O(n)|

## 基本概念
### 局部有序与整体有序
- 一组数的序列array[0,n-1]，满足array[i-1]<=array[i]的相邻元素称为顺序的
- 所有相邻元素均顺序的序列，也必然整体有序。
### 扫描交换
- 通过不断改变局部的有序性来实现整体的有序
- 从前到后依次检查每一对相邻元素，一旦发现逆序立即交换二者位置
- 对于array中的n个元素，一共n-1对，所以一趟扫描交换需要做n-1次比较和不超过n-1次交换
### 内部（外部）排序
内部排序：一般在内存中实现的排序。
外部排序：数据量很大时，内存有限，不能将所有的数据都放到内存中来，需要使用外存来实现排序。

## 冒泡排序（bubblesort） 
[冒泡排序](./冒泡排序.cpp)  
算法思路：
- 经过一趟扫描交换，序列未必达到整体有序，所以我们可以对序列做多次扫描交换，直到序列中不存在任何逆序的相邻元素。
- 多数这类操作会使得越小（大）的元素朝上（下）方移动，直至到达各自应该处于的位置（就位）。当然也有少部分操作会使得元素扫描交换的过程中上下漂浮。
- 排序的过程中，所有的元素超着各自的最终位置亦步亦趋的移动，这种就像气泡在水中的上下沉浮，所以叫冒泡排序（bubblesort）

平均时间复杂度O(n<sup>2</sup>)       

最佳时间复杂度O(n)      

最坏时间复杂度O(n<sup>2</sup>)       

## 插入排序（insertionsort）
[插入排序.cpp](./插入排序.cpp)    
后缀的首元素插入到前缀   
**算法思路：**
将整个序列视作和切分为两部分：有序的前缀，无序的后缀；然后不断迭代，将后缀的首元素移到前缀中 
类似打扑克牌时的码牌，左手的牌是有序的，右手是无序的。  
适用于向量和列表在内的任何序列结构。  
**实现思路：**
1. 待排序序列的第一个元素看做一个有序序列，把第二个元素到最后一个元素当成是未排序序列；
2. 然后从头到尾依次扫描未排序序列，将扫描到的每个元素插入有序序列的适当位置，直到所有数据都完成排序；
3. 如果待插入的元素与有序序列中的某个元素相等，则将待插入元素插入到相等元素的后面。
### 平均时间复杂度O(n<sup>2</sup>)  

### 最佳时间复杂度O(n)    
当输入序列已经有序时候，算法中在有序前缀中寻找插入位置的时间为O(1).总共插入n次一共是O(n)。
### 最坏时间复杂度O(n<sup>2</sup>)   
如果输出序列完全逆序，则各次插入的操作将线性递增，累计共需要O(n<sup>2</sup>)
### 空间复杂度
O(1),只有一个key辅助空间。

## 选择排序(selectionsort)
[选择排序.cpp](./选择排序.cpp)  
从前缀中选择出最大者，并作为最小元素转移到后缀中  

**算法思路：** 
- 将整个序列视作和切分为两部分：无序的前缀，有序的后缀。
- 要求前缀不大于（<=）后缀。
- 每次需要从前缀中选择出最大者，并作为最小元素转移到后缀中。
- 也就是后缀array(m,n)已经有序，且不小于前缀array[0,m]
- 适用于向量和列表在内的任何序列结构。

### 平均时间复杂度O(n<sup>2</sup>)     

### 最佳时间复杂度O(n<sup>2</sup>)   

### 最坏时间复杂度O(n<sup>2</sup>)  

### 空间复杂度O(1)  





## 快速排序（quicksort）
[快速排序.cpp](./快速排序.cpp)    
`快速排序算法（quicksort）`：
- 发明者：英国计算机科学家，1980年图灵奖得主C.A.R.Hoare于1960年发明。
- 分治法策略（Divide and conquer）的典型应用

- 实际应用中的首选算法
  - 易于实现，代码结构紧凑简练
  - 对于通常按照规律随机分布的输入序列，快排实际的平均运行时间比同类算法更少
**算法思路：**
使用分治法策略来把一个序列（list）分为两个子序列（sub-lists）。
1. 首先从数列中挑出一个元素，并将这个元素称为`基准或轴点（pivot）`。
2. 重新排序数列，所有比基准值小的元素摆放在基准前面，所有比基准值大的元素摆在基准后面（相同的数可以到任何一边）。在这个分区结束之后，该基准就处于数列的中间位置。这个称为`分区（partition）操作`。
3. 之后，在子序列中继续重复这个方法，直到最后整个数据序列排序完成。  
**实现思路：**
构造轴点/快速划分算法（quick partitioning）  
在array区间[low,high]内构造出一个轴点
1. 取首元素array[low]作为候选，将其从向量中取出备份到tmp,在向量中腾出的空闲单元用于其他元素的位置调整。 
2. 不断试图移动low和high，使其相互靠拢。  
  2.1 移动过程中要保证low左侧的元素均不大于tmp  
  2.2 移动过程中要保证high右侧的元素均不小于tmp
3. 当low和high彼此重合时候，只需要将备份的tmp回填到重合的位置，则array[low=high]=tmp就称为了名副其实的轴点。
4. 然后以轴点为界，递归地对前后子向量实施快速排序；子向量的排序结构就地返回之后，原向量的整体排序完成。


### 平均时间复杂度O(n log n)

### 最坏时间复杂度O(n<sup>2</sup>)    
原因：    
- 虽然快排划分出的子任务彼此独立，且规模综合保持渐进不变，但是不能保证两个子任务的规模大体相当，甚至可能极不平衡。  
- 分治策略高效实现的两个必要条件之一——子任务规模接近——无法保证
- 比如每次选择的最左端的元素，对于完全（或者几乎完全）有序的输入向量，每次（或者几乎每次）划分的结果都是1和n-1。

降低最坏情况概率：  
- 随机法：划分的时候在快速划分算法入口加一个swap(array[low],array[low+rand%(high-low+1)])。这样使得后续的处理等同于随机选择一个候选轴点。  
- 三者取中法：从待排序的向量中任取三个元素，将数值居中者作为候选轴点。  

空间复杂度（O(log n)）   
辅助空间 log n次



## 堆排序




## 希尔排序



## 归并排序(mergesort)
- 第一个在最坏的情况下可以保持O(n log n)运行时间的确定性排序算法
- 早期只能使用磁带和磁盘之类的顺序存储设备，促进了归并排序的诞生
- 由冯诺伊曼1945年首次在EDVAC上面实现
- 采用分治法（Divide and Conquer）的一个典型的应用。


`二路归并（2-way merge）`
- 将两个<u>有序序列</u>合并成一个有序的序列
- 属于迭代是真的算法，每一步迭代，只需比较两个待归并向量的首元素，将小的先输出，大的后输出，逐渐追加到新序列的末尾

**算法思想：**
它首先将数据样本拆分为两个子数据样本, 并分别对它们排序, 最后再将两个子数据样本合并在一起;
拆分后的两个子数据样本序列, 会继续递归的拆分为更小的子数据样本序列（直到拆分为1个元素）, 再分别进行排序。
最后反复调用二路归并算法，相邻的等长的子向量不断地合并为规模更大的向量，最终得到整个有序向量。

归并排序严格遵循从左到右或从右到左的顺序合并子数据序列, 它不会改变相同数据之间的相对顺序, 因此归并排序是一种稳定的排序算法.

作为一种典型的分而治之思想的算法应用，归并排序的实现分为两种方法：
- 自上而下的递归；
- 自下而上的迭代；

## 堆排序



## 计数排序



## 桶排序



## 基数排序





## 参考资料
十大经典排序算法 https://zhuanlan.zhihu.com/p/41923298  
数据结构 邓俊辉
