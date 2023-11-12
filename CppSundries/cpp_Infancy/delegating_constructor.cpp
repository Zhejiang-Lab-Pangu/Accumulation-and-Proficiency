//
// Created by Administrator on 2022/9/14.
//

/*委托构造函数*/

#include <iostream>
using namespace std;
#include <string>


class Home
{
public:
    Home(int a1, char a2, string a3, double a4, float a5): f(a1), m(a2), g(a3), s(a4), d(a5)
    {
        cout << "被委托的构造函数" << endl;
    };
    Home(int a1, char c): Home(a1, c, " ", 0, 0) {
        cout << "委托了上面的构造函数1" << endl;
    };
    Home(char c): Home(0, c){
        this->g = "sunhongjiang";   // 参数体在函数参数传递后执行
        cout << "委托了上面的构造函数2" << endl;
    }

    void func()
    {
        cout << f << "\t" << m << "\t" << g << "\t" << s << "\t" << d<< endl;
    }

private:
    int f;
    char m;
    string g;
    double s;
    float d;
};


void demo()
{
    Home h(1, 'a', "sun", 2.4, 4.2);
    h.func();

    Home h1(100, 'H');
    h1.func();

    Home h2('S');
    h2.func();
}

int main()
{
    demo();
    return 0;
}