# C++指针
```
1.指针变量，指针大小(8B)
2.指针步长
3.野指针
4.万能指针
5.(1)常量指针： const T * ptr;
  (2)指针常量： T *const ptr;
6.数组与指针
7.二维数组与指针
8.指针（数组）的加法和减法计算
9.指针数组：数组中的元素为指针：int* pArr[]={}
10.(1)指针（数组）做函数参数
   (2)指针做函数返回值：注意函数中声明的局部变量会造成野指针（使用已销毁的内存地址）
11.字符数组的指针（注意字符串是用\0结尾）
12.字符指针的数组（数组的元素为字符指针：char *p[3]=）
13.字符串的两种初始化：
   (1) char x[] = "abc";  有数据拷贝
   (2) char *x = "abc";   指针地址的指向
14.数组和指针
```

## 函数指针相关
```
15.函数指针（函数的指针）
	(1) 定义：T *pfunc(Type1, Type2) = &func; 调用：T res=(*pfunc)(value1, value2);
	(2) 函数名即为一个函数指针，即func等价于&func；
16.函数指针数组：本质上是数组，里面的元素都是函数指针
	(1) 定义： int (*p[4])(int, int)= { p1, p2, p3, p4};
	(2) 调用
17.函数指针底层原理：
	函数名就是一个隐式的指针，即函数名在程序里面，就是函数指针的一个别名。
18.回调函数（回调函数就是一个被作为参数传递的函数）
	（1）在C语言中，回调函数只能用函数指针实现；
	（2）在C++等中，还可用仿函数或匿名函数；
```

## 结构体指针
```
19.结构体内存对齐
20.结构体指针：定义时初始化，避免野指针
21.结构体多级指针（结构体指针的嵌套）
```

## 内存管理接口
```
22.calloc和realloc
	(1) calloc分配内存后会清零，相当于malloc+memset(0)
	(2) realloc 表示扩充原有的指针空间： ptr = (Type *)realloc(p, size)
23.C++/C内存分区
	栈、堆、常量、静态（全局）区、代码区
24.NULL和nullptr的区别
	NULL是一个宏定义；nullptr是一个编译期常量。
25.new和delete
```
## 智能指针

```
26. 智能指针的引入：将new/delete作了一层封装，方便内存管理

```
#### 1.shared_ptr
```
27.
(1)定义
shared_ptr<T> ptr;      定义完即为空指针（裸指针定义完若不初始化为野指针）

(2)初始化
  ① 用裸指针: shared_ptr<T> ptr(new T(value));
  ② 赋值/拷贝构造
  ③ shared_ptr<T> ptr = make_shared<T>(value);

28.shared_ptr共享智能指针
(1) 共享：一块内存，可有多个指针指向，均有读写和销毁权限；
(2) 原理：每个shared_ptr指针变量都会维护一个指向自身指向的那个内存空间的引用计数器，并同步更新；
(3) 引用计数器增加的情况：
    ① 新建一个新的shared_ptr，并初始化，此时引用计数为1；
    ② 用上述shared_ptr初始化一个新的shared_ptr，则二者的引用计数都加1；
    ③ shared_ptr作为参数传递到函数中，再函数周期内，其引用计数是加1；但引用传参不会加1；
    ④ shared_ptr作为返回值，且有变量接收，则引用计数加1；
(4) 引用计数减少和内存空间的释放：
    ① 当某个shared_ptr不再指向此内存空间，其他指向该内存空间的shared_ptr的引用计数 减1；
    ② 当最后一个指向该内存空间的shared_ptr被释放或销毁，该内存释放；
29.shared_ptr的常用操作：
    (1) use_count();
    (2) unique();
    (3) reset();
    如果独占，则释放内存空间，并将shared_ptr置为空指针(新的内存地址);
    如果不是独占，则将其他指向该内存的shared_ptr变量的引用计数减1，并将当前shared_ptr指向空(引用计数0)或参数的新内存地址(引用计数为1);
    (4) get();
    (5) swap(p1, p2);
30.自定义删除器
    (1) make_shared 不支持
    (2) 语法：shared_ptr<T> p(new T(value), 函数指针)；
```
#### 2.weak_ptr
```
31.
    (1) weak_ptr 不能直接用来操作内存空间，必须依附于shared_ptr;
    (2) 不能用裸指针初始化，可用make_shared初始化，但无意义;
    (3) 当一个shared_ptr新增一个weak_ptr时，其weak 计数器加1；销毁一个weak_ptr，其weak 计数器减1;
    (4) 当一个shared_ptr销毁时，指向其的weak_ptr会过期(expired)；
    (5) 常用方法：
       ① lock(); 返回其对应的shared_ptr，接收后，引用计数加1；
       ② expired(); 是否过期，返回bool

使用场景：
    (1) 循环引用
    (2) 探查内存空间是否有效 (使用expired()方法)  

```

#### 3.unique_ptr

```
32.
    (1) unique_ptr 
        独占含义：同一时间只能优一个unique_ptr变量指向同一个内存空间,且只有此unique_ptr对该内存空间有操作权限；
    (2) 定义
            unique_ptr<T> ptr;  定义完成即为空指针
    (3) 初始化
        ① unique_ptr<T> p(new T(value));
        ② unique_ptr<T> p1 = move(p);
        ③ make_unique<T>()
33.常用操作
    (1) get()
    (2) reset()
    (3) release()    返回裸指针，并将unique_ptr置为空
    (4) swap()
34.自定删除器
    unique_ptr<int, decltype(lambda)> p3(new int(456), lambda);
```
