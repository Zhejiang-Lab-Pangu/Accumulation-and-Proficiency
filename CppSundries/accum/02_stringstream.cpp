//
// Created by Administrator on 2023/2/10.
//

#include <iostream>
# include <sstream>
using namespace std;


// stringstream::str(); returns a string object with a copy of the current contents of the stream.
// stringstream::str (const string& s); sets s as the contents of the stream, discarding any previous contents.
void demo1()
{
    string s ="ABCD";
    stringstream ss;
    ss.str(s);
    cout << ss.str() << endl;
}

// 数据传入传出
void demo2()
{
    string s1 = "abc";
    string s2 = "123";
    stringstream ss;
    ss << s1 << s2;       // 向字符流中传入数据
    cout << ss.str() << endl;
    string result;
    ss >> result;
    cout << result << endl;
}

// 类型转换
void demo3()
{
    // 数值型转字符
    int a = 12;
    float b = 34.56;
    double c = 67.89;
    stringstream ss;
    ss << a << b << c;
    string s;
    ss >> s;
    cout << s << endl;
    cout << ss.str() << endl;

    // 字符转数值
    stringstream ss1;
    ss1.str("123.4");
    int a1;
//    ss1 >> a1;
//    cout << a1 << endl;
    float b1;
    ss1 >> b1;
    cout << b1 << endl;
}


template <typename T>
void demo4(T val)
{
    stringstream ss;
    ss << "0x" << std::hex << val << std::dec << endl;
    cout << ss.str() << endl;
}

int main()
{
    demo1();
    demo2();
    demo3();
    uint64_t a = 10;
    demo4<uint64_t>(a);
    return 0;
}