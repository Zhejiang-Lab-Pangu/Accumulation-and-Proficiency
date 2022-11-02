//
// Created by Administrator on 2022/10/21.
//

#include<iostream>
using namespace std;
#include <string>
#include <algorithm>


void demo1()
{
    pair<int, string> p1;
    pair<int, string> p2{123, "sun"};
    pair<int, string> p3(p2);
    pair<int, string> p4 = p3;

    cout << p4.first << "\t" << p4.second << endl;

    // get
    cout << get<0>(p4) << "\t" << get<1>(p4) << endl;
    get<0>(p4) = 900;
    get<1>(p4) = "liu";
    cout << get<0>(p4) << "\t" << get<1>(p4) << endl;
    cout << get<0>(p3) << "\t" << get<1>(p3) << endl;

    pair<int, string> p5;
    p5 = make_pair(123, "ooo");
    cout << p5.first << "\t" << p5.second << endl;
}

int main()
{
    demo1();
    return 0;
}