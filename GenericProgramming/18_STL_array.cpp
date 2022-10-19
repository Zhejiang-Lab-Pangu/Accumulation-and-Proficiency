//
// Created by Administrator on 2022/10/12.
//

#include <iostream>
using namespace std;
#include <string>
#include <array>

/*   array/vector   */


// 构造
void demo1()
{
    array<int, 3>arr1{};    // 加{}，默认给一个空值或0值
    array<int, 3>arr2 = {};
    array<int, 3>arr3{0, 1, 2};
    array<int, 3>arr4(arr3);
    array<int, 3>arr5({1, 2, 3});

    arr1 = arr4;

    arr2.fill(123);
    get<0>(arr2) = 456;
    cout << arr2.at(0) << "--" << arr2[1] << "--" << arr2[2] << endl;
}

// size
void demo2()
{
    array<int, 3>arr1{1, 2, 3};
    array<int, 0>arr2{};

    cout << arr1.empty() << "--" << arr1.size() << "--" << arr1.max_size() << endl;
    cout << arr2.empty() << "--" << arr2.size() << "--" << arr2.max_size() << endl;

    // 取值
    cout << arr1[0] << "--" << get<0>(arr1) << "--" << arr1.at(0) << endl;
    cout << arr1.front() << "--" << arr1.back() << endl;

    //指针
    cout << arr1.data() << "--" << &arr1.front() << endl;
    cout << *arr1.data() << "--" << arr1.front() << endl;
    cout << *(arr1.data() + 1) << "--" << arr1.at(1) << endl;

    //swap
    array<int, 3> arr3{4, 5, 6};
    cout << arr1[0] << "--" << arr3[0] << endl;
    arr1.swap(arr3);
    cout << arr1[0] << "--" << arr3[0] << endl;

    // operator=
    array<int, 3>arr4(arr1);
    cout << (arr1 == arr3) << "--" << (arr1 == arr4) << endl;
}


// 迭代器
void demo3()
{
    array<int, 3>arr1{1, 2, 3};

    array<int, 3>::iterator start = arr1.begin();
    array<int, 3>::iterator end;
    end = arr1.end();

    while(start != end)
    {
        cout << *start << "\t" << start << endl;
        *start += 10;
        start++;
    }
    cout << end << endl;


    for(auto start = arr1.cbegin(); start != arr1.cend(); start++)      // c表示const
    {
        cout << *start << "\t" << start << endl;
//        *start += 10;
    }
}

int main()
{
//    demo1();
//    demo2();
    demo3();
    return 0;
}