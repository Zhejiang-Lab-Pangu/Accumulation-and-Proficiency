//
// Created by Administrator on 2022/9/20.
//
/* 将输入的参数原封不动地传递到下一个函数中，这个“原封不动”指的是:
 * 如果输入的参数是左值，那么传递给下一个函数的参数的也是左值；如果输入的参数是右值，那么传递给下一个函数的参数的也是右值。
 * */
#include<iostream>
using namespace std;
#include <string>

class CData
{
public:
    CData()=delete;
    CData(const char * ch): data(ch)
    {
        cout << "const char * ch" << endl;
    }
    CData(string& str): data(str)
    {
        cout << "string & str" << endl;
    }
    CData(string&& str): data(str)
    {
        cout << "string&& str" << endl;
    }
    ~CData()
    {
        cout << "~CData" << endl;
    }

private:
    string data;

};

template<typename T>
CData* Creator(T&& t)
{
//    return new CData(t);  // 调用CData(string& str): data(str)构造
    // 完美转发
    return new CData(forward<T>(t));    // 调用CData(string&& str): data(str)构造

}
// forword的用场：在模板中使用T&&接受参数（万能模板），将参数使用forward()转发给被调函数，这样左值作为仍旧作为左值传递，右值仍旧作为右值传递。


void Forward()
{
    const char* value = "hello";
    string str1 = "hello";
    string str2 = " world";
    CData* p = Creator(str1 + str2);

    delete p;
}




int main()
{
    Forward();
    return 0;
}