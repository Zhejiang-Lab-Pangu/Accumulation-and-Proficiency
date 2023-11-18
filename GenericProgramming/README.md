# c++ 泛型编程与模板

## 模板
```
1. 函数模板的定义、调用、参数推导
2. 
(1) 函数模板与普通函数重载：同事满足调用规则时，优先调用普通函数；若想调用函数模板，需显示指定模板类型
(2) 函数模板与函数模板的重载
3.
(1) 函数模板类型参数默认值     void func0(T1 a, T2 b=123);
(2) 函数模板参数默认值        template<typename T1, int T2=123>  //支持整形、枚举、指针
(3) 函数模板的泛化与特化，默认函数模板（没有默认值）的都是泛化
4.
(1) 类模板中参数推导 (C++17后支持)
(2) 类模板的编译规则：
    ① 没有实例化，不会编译类模板 (被编译器优化，认为是无效代码)
    ② 如果实例化，只编译出对应的参数类型的代码
    ③ 若成员函数不调用，则不编译
5. 类模板的泛化与特化
(1) 成员函数不能半特化
6. 成员函数模板
7. 类模板的嵌套
8. 类模板中的友元
9. 可变参数的函数模板
10. 可变参数模板 --- 折叠表达式
11. 可变参表达式
12. 
(1) 可变参 类模板的递归继承
(2) 可变参数 模板的递归组合
13. 模板里面的多态 --- 静态多态
14. 子类做父类的模板参数
15. 类模板的混入(把模板参数当作父类继承)
```


## STL
```
16. STL基本介绍， 三大组件：容器、算法、迭代器
17. string 容器
18. array 容器
19. 迭代器 -- 迭代器是一种数据类型 (是仿指针的类模板，封装了原生指针)
20. vector 容器： 不定长同期，空间地址连续，可动态扩容
21. deque 容器 (双端队列)
22. stack 容器    (.pop()     .top()      删和取栈顶元素)
23. queue 容器    (.front()   .back()     取元素)
24. list 容器 (双向链表)
25. set 和 multiset 容器   (底层红黑树，一种平衡二叉树)
26. pair 容器
27. map 和 multimap 容器   (multimap: 可以有重复的键值)
```
```
28.
适配器：
(1) 函数对象，即STL中的仿函数
(2) 仿函数是一个类，重载了()操作符，使类可以像函数一样调用
(3) 根据重载()时的参数个数，可分为一元仿函数和二元仿函数
(4) 返回值为bool的仿函数被称为 谓词
(5) find_if(.begin(), .end(), 函数对象)
29.
(1) 函数对象适配器: 当函数对象的参数不够用，可以使用适配器来配置函数对象
(2) bind1st; bind2nd将二元函数配置成一元函数
(3) not1: 构造一个与谓词结果相反的一元函数对象
(4) not2: 构造一个与谓词结果相反的二元函数对象
30.
(1) 普通函数适配器：ptr_fun 把普通函数转为函数对象，再加适配器
(2) 类中成员函数适配器：当容器中存储的是对象，则用mem_fun_ref 来适配其成员函数; 当容器中存储的是对象指针,则用mem_fun 来适配其成员函数
```
```
31.分配器：(空间配置器)
(1) 负责空间的配置与管理， 是一个实现了动态空间分配与释放的类模板
(2) 统一对容器中需要的内存空间进行管理（申请，释放）
(3) .allocate()     .deallocate(ptr, size)
```
```
算法：
#include <functional>       // 函数对象
#include <algorithm>        // 算法
#include <numeric>          // 算法补充

32.
(1) for_each(begin, end, callback)      返回值为callback的函数对象
(2) transform(v1.begin(), v1.end(), v2.begin(), 函数对象);     将指定容器区间元素搬运到另一容器中， 必须给目标容器提前分配内存;返回值为v2对应位置的迭代器
(3) transform(v1.begin()+2, v1.end(), v2.begin()+2, v3.begin(), 函数对象);     将两个指定容器的元素搬运到第三个容器
33.
(1) auto rs = find(v1.begin(), v1.end(), 3);        返回值为迭代器
(2) auto rs = find_if(v1.begin(), v1.end(), xxx());     返回值为迭代器
34.
(1) 查找相邻重复元素: iterator adjacent_find(begin, end)
(2) 二分查找: bool binary_search(begin, end, val, less<T>)
35.
(1) int count(begin, end, val);     返回val出现的次数
(2) int count(begin, end, func);    符合函数适配器的元素次数
36.
(1) iterator merge(begin1, end1, begin2, end2, begin3, func)        以函数对象的规则合并两个容器至第三个容器
37.
(1) void random_shuffle(begin, end);
(2) void shuffle(begin, end)
38.
(1) sort(begin, end);       sort(begin, end, 函数适配器)
(2) reverse(begin(), end());
39.
(1) iterator copy(begin1, end1, begin2)
(2) void replace(begin, end, oldVal, newVal)
(3) void replace_if(begin, end, func, newVal)
(4) iterator replace_copy(begin1, end1, begin2, oldVal, newVal)       cp到容器2中，当源容器中的元素等于oldVal时，目标容器中用newVal替换
(5) iterator replace_copy_if(begin1, end1, begin2, func, newVal)
40.
(1) 算术生成算法: T accumulate(begin, end, val, func)
(2) fill(v1.begin(), v1.end(), 100);
41.
要求： 原容器元素都必须是有序的，且排序规则一致， 目标容器使用前要分配空间
(1) 交集  iterator set_intersection(begin1, end1, begin2, end2, begin3, func);
(2) 并集  iterator set_union(begin1, end1, begin2, end2, begin3, func);
(3) 差集  iterator set_difference(begin1, end1, begin2, end2, begin3, func);
```
## 泛型编程 的 一些知识点
```
42. 左值和右值  &  左值引用和右值引用
43. 万能引用(转发引用)
44. 完美转发
(1) 转发： 通过中间函数间接调用目标函数，若目标函数有参数，则参数也要通过中间函数传递
(2) 完美转发 - 在转发的过程中，实参属性完全保留，通过跳板函数，完全传递给目标函数
(3) 在万能引用中，通std::forward<>()配合实现完美转发
45. SFINAE(Substitution failure is not an error) - 替换失败不是错误
46. enable_if 结构体模板
47. conditional<bool, T1, T2> 结构体模板 --- 类似于3目运算
48. remove_all_extent   获取数组元素中的具体类型
49.
(1) true_type 、 false_type  本质是一种数据类型
(2) is_union、is_class 判断是否是union和class
```
```
萃取 - traits(特质)      主要用于对模板中的模板参数进行操作，这种模板一般称其为 traits 模板； 标准库中很常见
50. 萃取的分类和固定萃取
(1) 给定一种类型。萃取另一种类型；这两个类型之间的对应关系是固定的；所以称为固定萃取
51. 固定萃取 -- 获取数组元素中的具体类型
52. 退化  &  固定萃取实现退化
(1) std::decay<T>  去掉T的各种修饰：
(2) 丢弃const、左右引用修饰符; 数组转指针(const不丢弃); 函数名转函数指针
53. 值萃取 - value traits         给定一个类型，得到一个值
54.
(1) 类型萃取 - type traits         从boots库发展而来；实现了类型信息的提取和变换
(2) 就是一堆接口，官方文档称其为 type traits (https://en.cppreference.com/w/cpp/meta#Type_traits)
55.
(1) 策略萃取 - 给定一个类型，萃取出一种算法或实现方式 【其实就是用模板的方式实现一些算法，再根据类型参数调用】
```

## 元编程
```
56.
(1) 元编程(模板元编程): 一种编程方式，能让代码在编译期间就执行并返回结果，以达到提升程序执行效率的作用 - 相当于执行前置
(2) 元函数: 用元编程思想写的函数，可在编译期被执行的函数; 元函数包含模板
(3) constexpr 关键字，标识变量或函数在编译器执行
57.
(1) 阶乘的元编程
(2) 连续自然数求和的元编程 - 函数模板 - 递归拆包
```
