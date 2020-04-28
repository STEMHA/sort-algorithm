## 排序算法比较
|排序算法|平均时间复杂度|最佳时间复杂度|最坏时间复杂度|空间复杂度|辅助数据结构|
|:-|:-|:-|:-|:-|:-|
|冒泡排序|O(n<sup>2</sup>)|O(n)|O(n<sup>2</sup>)|O(1)|相邻元素用于swap的一个空间|
|插入排序|O(n<sup>2</sup>)|O(n)|O(n<sup>2</sup>)|O(1)|用于插入数key的副本|
|选择排序|O(n<sup>2</sup>)|O(n<sup>2</sup>)|O(n<sup>2</sup>)|O(1)|用于找出最大值的一个max|
|快速排序|O(n log n)|O(n log n)|O(n<sup>2</sup>)|O(log n)|用于保存基准值的副本|
|归并排序|O(n log n)|O(n log n)|O(n log n)|O(n)|
|堆排序|O(n log n)|O(n log n)|O(n log n)|O(1)|堆顶堆尾用于swap的一个空间|
|桶排序|O(n+m)|O(n+m)|O(n<sup>2</sup>)|O(n+m)| |
|基数排序|O(n×k)|O(n×k)|O(n×k)|O(n+k)||
|计数排序|Ο(n+k)|Ο(n+k)|Ο(n+k)|Ο(k)|其中k是整数的范围）|
|希尔排序|O(n·log2n)|||O(1)|相邻元素用于swap的一个空间|

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


平均时间复杂度O(n log n)

最坏时间复杂度O(n<sup>2</sup>)    
原因：    
- 虽然快排划分出的子任务彼此独立，且规模综合保持渐进不变，但是不能保证两个子任务的规模大体相当，甚至可能极不平衡。  
- 分治策略高效实现的两个必要条件之一——子任务规模接近——无法保证
- 比如每次选择的最左端的元素，对于完全（或者几乎完全）有序的输入向量，每次（或者几乎每次）划分的结果都是1和n-1。

降低最坏情况概率：  
- 随机法：划分的时候在快速划分算法入口加一个swap(array[low],array[low+rand%(high-low+1)])。这样使得后续的处理等同于随机选择一个候选轴点。  
- 三者取中法：从待排序的向量中任取三个元素，将数值居中者作为候选轴点。  

空间复杂度（O(log n)）   
辅助空间 log n次






## 希尔排序（shellsort）
[希尔排序.cpp](./希尔排序.cpp)
- 由D.L.Shell于1959年发明得名
- 将整个待排序向量视为二维矩阵
- 增量（increment）：矩阵的宽度
- 递减增量排序，是插入排序的一种改进版本，矩阵的宽度会逐渐变小；
缺点：
- 效率虽高，但不稳定
算法思路：
- 插入排序在对几乎已经排好序的数据操作时，效果是非常好的；但是插入排序每次只能移动一位数据，因此插入排序效率比较低。
- 希尔排序在插入排序的基础上进行了改进；
- 先将整个数据序列分割成若干子序列分别进行直接插入排序，待整个序列中的记录基本有序时，再对全部数据进行依次直接插入排序。

算法步骤：
- 取一个递增的增量序列H={w<sub>1</sub>,w<sub>2</sub>,...,w<sub>i</sub>,...}
- 设k=max{i|w<sub>i</sub><n},w<sub>k</sub>是H中小于n的最后一项。
- 依次使用w<sub>k</sub>来将A视为w<sub>k</sub>宽度的矩阵B
- 对B的每一**列**进行插入排序
- 我们可以看出矩阵的宽度是不断缩减的，所以又叫做`递减增量排序（diminshing increment）`
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

## 堆排序（heapsort）
[堆排序.cpp](./堆排序.cpp)
- 前面的归并排序算法已经达到理论上最有的复杂度O(n log n)，所以我们希望可以降低复杂度常系数，或者是空间复杂度
- 借助堆（heap）来实现高效排序的算法
- 就地堆排序，可以将空间复杂度降为o(1)
- `就地堆排序算法（in-place heapsort）`——>是`选择排序算法`的原理
- 就地算法指的是几乎不需要更多辅助空间的算法

堆是一个近似完全二叉树的结构，并同时满足堆积的性质：即子结点的键值或索引总是小于（或者大于）它的父节点。

堆排序实现分为两种方法：
大顶堆：每个节点的值都大于或等于其子节点的值，在堆排序算法中用于升序排列；
小顶堆：每个节点的值都小于或等于其子节点的值，在堆排序算法中用于降序排列；

实现步骤：
1. 创建一个堆 Heap[0……n-1]；
2. 把堆首（最大值）和堆尾互换；
3. 把堆的尺寸缩小 1，并调用 下滤操作，目的是把新的数组顶端数据调整到相应位置；
4. 重复步骤 2，直到堆的尺寸为 1

记忆方法：
看一下参考资料的gif文件，主要是三个步骤，建立一个堆，然后对堆顶进行下滤操作，保证堆顶是最大的，然后堆顶和堆尾进行交换，堆的规模缩小
用数组实现堆
一、二叉树的俩个子节点与索引的关系
对于索引为K的节点，其左孩子为（2*K） 右孩子为（ 2*K+1）
 平均时间复杂度O(n·log2n)

## 计数排序
[计数排序.cpp](./计数排序.cpp)
计数排序使用一个额外的数组C，其中第i个元素是待排序数组A中值等于 i的元素的个数。然后根据数组C来将A中的元素排到正确的位置。
- 牺牲空间换取时间的做法
- 非比较性质的排序算法（计数排序过程中不存在元素之间的比较和交换操作）
- 元素从未排序状态变为已排序状态的过程，是由额外空间的辅助和元素本身的值决定的。

算法步骤：
1. 找出待排序的数组A中最大和最小的元素，根据差值范围申请额外空间（max-min+1），建立数组C
2. 遍历待排序集合A，将每一个元素的值value出现的次数times记录到元素值value对应的额外空间C[index]内；（index=value-min）
3. 对所有的计数累加,从C中的第一个元素开始，每一项和前一项相加（对额外空间内数据进行计算，得出每一个元素的正确位置）
4. 反向填充目标数组targetarray,将每个元素i放在新数组targetarray的第C[i]项，每放一个元素就将C[i]减去1


[排序算法（八）：计数排序](https://www.jianshu.com/p/86c2375246d7)

## 桶排序（bucketsort）
- 利用哈希桶对关键码进行分拣
- 数组划分到一定数量的有序的桶里，然后再对每个桶中的数据进行排序，最后再将各个桶里的数据有序的合并到一起。
- 

平均时间复杂度O(n+m)
所用散列表共占用O(m),散列表的创建和初始化耗时O(m)
将所有关键码键入插入列表耗时O(n),依次读出非空桶中的关键码耗时O(m)，总体运行时间O(n+m)

最大间隙（maximum gap）问题：任意n个互异的点都将实轴划分为n+1段，除去最外侧无界的两段，其余有界的n-1段中哪一个最大？
简单的方法是先排序，然后依次计算相邻间隙，不断更大最大间隙的记录。
有没有更有效率的方法呢？
有的
- 先一趟顺序扫描找到low和high的点
- 然后建立长度为n的散列表，散列函数为hash(x)=(x-low)/[(hi-lo)/(n-1)] 向下取整 
- 效果相当于：有效区间[low, high) 均匀划分为宽度为(high-low)/(n-1)的n-1个左闭右开的区间，对应于第0到n-2单元；high独自占用n-1号桶   
- 然后对散列表做一个遍历，确定每个非空桶中的最左边和最右边的点，删除所有的空桶。
- 最后顺序扫描一趟列表，确定相邻非空桶之间的间隙，报告其中最大者即可
原理是最大间隙的两个点绝对不会落到同一个桶单元内部。

## 基数排序（radixsort）
- `低字段优先（least significance digit first）策略`。桶排序的趟数却决于组成关键码的字段数
- 低位优先的多趟**桶排序**
- `字典序（lexicographical order）`：任意两个关键码之间的大小关系，取决于第一个异的域。
- 举例子，对于三位数的几个数，分别对个位十位百位进行桶排序，即可得到最终的顺序




## 参考资料
十大经典排序算法 https://zhuanlan.zhihu.com/p/41923298  
各种排序算法的时间复杂度和空间复杂度 https://www.cnblogs.com/wuxiangli/p/6399266.html
数据结构 邓俊辉
