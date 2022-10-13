//
// Created by Administrator on 2022/9/30.
//

#include<iostream>
using namespace std;
#include <string>

/* string
 *
 *
 *
 *
 * */


// 构造
void demo1()
{
    string s1;      // string();
    string s2("abc");   // string(const char *p);
    string s3(s2);        // string(const string &str);
    string s4 (2, 's'); // string(int n, char s);

    cout << s1 << " == " << s2 << " == " << s3 << " == " << s4 << endl;
}

// 赋值
/*
 * string &operator=(const char *p)
 * string &operator=(const string &str)
 * string &operator=(char c)
 *
 * string &assign(const char *p)
 * string &assign(const char *p, int n)
 * string &assign(const string &str)
 * string &assign(int n, char c)
 * string &assign(const string &str, int start, int n)
 *
 * */
void demo2()
{
    string str1;
    str1 = "abcd";
    string str2;
    str2 = str1;
    string str3;
    str3 = 'c';
    cout << str1 << "--" << str2 << "--" << str3 << endl;

    string s1;
    s1.assign("abcd");
    string s2;
    s2.assign("abcd", 3);
    string s3;
    s3.assign(s1);
    string s4;
    s4.assign(4, 'a');
    string s5;
    s5.assign(s1, 1, 2);
    cout  << s1 << "--" << s2 <<"--" << s3 <<"--" << s4 << "--" <<s5 << endl;
}


// c和c++字符串风格转换
void demo3()
{
    const char *p = "abcf";
    string s = string(p);       // c风格转c++风格
    cout << s << endl;

    const char *p2 = s.c_str();     // c++转c风格
    cout << p2 << endl;  // 这里不用解引用
}


void demo4()
{
    // 是否为空
    string s1;
    cout << s1.empty() << "--" << s1.length() << "--" <<s1.size() << endl;
    string s2 = "a孙";
    cout << s2.empty() << "--" << s2.length() << "--" <<s2.size() << endl;

    // 取值
    string s3 = "abcd";
    cout << s3.at(1) << "--" << s3[1] << endl;

    // for循环
    for(int i=0; i<s3.length(); i++)
    {
        cout << s3.at(i) << "\t";
    }
    cout << endl;
    for (char i: s3)
    {
        cout << i << "\t";
    }
    cout << endl;
    for (char &i: s3)   // 引用传递，可以修改值
    {
        i = toupper(i);     // 小写该大写
        cout << i << "\t";
    }
    cout << endl;
    cout << s3 << endl;
}


// 拼接
void demo5()
{
    string s1 = "abc";
    string s2 = "1234";


    s1 += "xyz";
    cout << s1 << endl;
    s1 += s2;
    cout << s1 << endl;
    s1 += 'w';
    cout << s1 << endl;

    s1.append("xyz");
    cout << s1 << endl;
    s1.append("ABCD", 2);
    cout << s1 << endl;
    s1.append(s2);
    cout << s1 << endl;
    s1.append(s2, 1, 2);
    cout << s1 << endl;
    s1.append(2, 'S');
    cout << s1 << endl;
}

// 比较
void demo6()
{
    string s1 = "abc";
    string s2 = "abc";
    const char *p = "abc";

    cout << s1.compare(s2) << endl;
    cout << s1.compare("abc") << endl;
    cout << s1.compare(p) << endl;

    cout << string(p).compare(s1) << endl;          //返回0，表示相同

    cout << (s1 == "abc") << endl;
    cout << (p == "abc") << endl;           // 1表示true
    cout << (p == s1) << endl;
}

// 插入删除
void demo7()
{
    string s1 = "abc";
    string s2 = "XYZ";

    s1.insert(0, "ABC");
    s1.insert(3, s2);
    cout << s1 << endl;


    s1.erase(3, 3);
    cout << s1 << endl;

    //子串
    string s3 = s1.substr(0, 4);
    cout << s3 << endl;

    // 删除
    s1.clear();
    cout << s1.empty() << endl;
}



// 查找
void demo8()
{
    string s1 = "123456abcd1234";
    string s2 = "23";
    cout << s1.find(s2, 3) << endl;

    string s3 = "xxx";
    cout << s1.find(s3, 3) << endl;
    cout << string::npos << endl;       // string中的一个常量，表示没找到

//    string s4 = "cdxxyu";
    cout << s1.find("cdxy", 0, 2) << endl;      // 在s1中，从0开始找cdxy中的前两个字符首次出现的位置


    cout << s1.rfind("23") << endl;
    cout << s1.rfind("23", 10) << endl;         // 在s1中的前10个，从右侧找到的第一个的位置
}

// 替换
void demo9()
{
    string s1 = "0123456789";
    string s2 = "FGH";
    s1.replace(1, 2, s2);       // 替换从pos开始的n个字符为s2
    cout << s1 << endl;
}

int main()
{
//    demo1();
//    demo2();
//    demo3();
//    demo4();
//    demo5();
//    demo6();
//    demo7();
    demo8();
    demo9();
    return 0;
}