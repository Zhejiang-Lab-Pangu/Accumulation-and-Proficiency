//
// Created by Administrator on 2022/10/25.
//

#include <iostream>
using namespace std;
#include <vector>
#include <numeric>
#include <string>

int main()
{
    // iota 区域赋连续值
    vector<int> v1{};
    v1.resize(10);
    iota(v1.begin(), v1.end(), 1);

    cout << v1.at(8) << endl;
    cout << v1.size() << "\t" << v1.capacity() << endl;

    for(auto & it: v1)
    {
        cout << it << endl;
    }


    // stoi 将字符串转成n进制
    string s1 = "1209";
    int a;
    a = stoi(s1, nullptr, 10);
    cout << "=========" << a<< endl;
    return 0;
}

void Fun()
{

}