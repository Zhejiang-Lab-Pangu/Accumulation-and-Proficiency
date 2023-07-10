//
// Created by Administrator on 2023/2/15.
//
#include <iostream>
using namespace std;
#include <random>

int main()
{
    std::random_device rd;
    cout << rd() << endl;

    std::mt19937 engine(rd());
    cout << engine() << endl;
    return 0;
}
