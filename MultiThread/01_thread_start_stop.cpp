//
// Created by Administrator on 2023/11/7.
//

#include <iostream>
#include <thread>
using namespace std;

// 线程运行的开始和结束
/*
 * 初始函数：自己创建的线程需要从一个函数开始运行，此函数运行结束，线程结束
 *
 * 一般情况下，若子线程没执行完，而主线程已退出，则子线程会被操作系统强行终止；
 *
 * 创建流程：
 *      (1) <thread>头文件
 *      (2) 初始函数
 *      (3) 主函数：
 *          ① 创建线程对象，并用初始函数初始化
 *          ② join() 阻塞主线程，等待子线程执行完毕
 *          ③ detach() 分离。主线程和子线程不汇合了，detach后，子线程对象失去与主线程的关联，子线程会驻留在后台运行，即子线程被C++运行时库接管，执行完毕后，运行时库清理相关资源(守护进程)
 *                           程序员会失去其控制权，一旦detach后就不能join，否则出现异常
 *          ④ joinable() 判断是否可以成功使用join() 或 detach(); 返回bool
 *
 * */


void myThread(){
    cout << " my thread start " << endl;

    cout << " my thread - 1 " << endl;
    cout << " my thread - 2 " << endl;
    cout << " my thread - 3 " << endl;
    cout << " my thread - 4 " << endl;
    cout << " my thread - 5 " << endl;
    cout << " my thread - 6 " << endl;
    cout << " my thread - 7 " << endl;
    cout << " my thread - 8 " << endl;
    cout << " my thread - 9 " << endl;

    cout << " my thread end " << endl;
}

/*
int main() {

    thread myobj(myThread);
//    myobj.join();

    cout << "001:" << myobj.joinable() << endl;
    myobj.detach();
    cout << "002:" << myobj.joinable() << endl;

    cout << " in main - 1 " << endl;
    cout << " in main - 2 " << endl;
    cout << " in main - 3 " << endl;
    cout << " in main - 4 " << endl;
    cout << " in main - 5 " << endl;
    cout << " in main - 6 " << endl;
    cout << " in main - 7 " << endl;
    cout << " in main - 8 " << endl;
    cout << " in main - 9 " << endl;

    return 0;
}
*/

// 用类对象作为thread的可调用对象
/*
 * 注意：
 *      1. detach后，当主线程执行完成但子线程没有执行完，主线程中的局部变量都会释放，如果传递给子线程的参数是有这些局部变量，则会出现异常；因此要用拷贝或着移动
 *
 *
 * */


class TA{
public:
    void operator()(){
        cout << " operator -- my thread start " << endl;
        cout << " operator -- my thread end " << endl;
    }
};


/*
int main() {

    TA ta;
    thread myobj(ta);   // thread myobj(ta) 是将 ta 复制到线程 myobj中的，执行的是拷贝构造函数。
    myobj.join();

    // myobj.detach(); 没问题。主线程结束后，ta对象销毁，但 thread myobj(ta) 是将 ta 复制到线程 myobj中的，执行的是拷贝构造函数。


    cout << " in main - 1 " << endl;


    return 0;
}
*/



// 用lambda表达式作为可调用对象
int main() {

    auto myLmbda = [](){
        cout << "lambda -- thread3 start" << endl;
        cout << "lambda -- thread3 end" << endl;
    };

    thread myobj(myLmbda);
    myobj.join();

    cout << " in main - 1 " << endl;


    return 0;
}