
#include <iostream>
#include <cstdlib>

#include <windows.h>
using namespace std;


/*
 * time:
 * 1.两种类型 ->> time_t(秒数) 和 tm(结构体)
 * 2.两种时间 ->> UTC时间 和 local时间
 * 3.clock_t ->> c/c++的一个基本计时单位; clock_t clock(void) 返回clock函数执行起（一般为程序的开头），处理器时钟所使用的时间。
 *
 * 计算机的随机数：
 * 1.计算机的随机数都是由伪随机数，即是由小M多项式序列生成的，其中产生每个小序列都有一个初始值，即随机种子。
 * 2.小M多项式序列的周期是65535，即每次利用一个随机种子生成的随机数的周期是65535 (2^16)，当你取得65535个随机数后它们又重复出现了。
 *
 * 随机数API
 * (1) rand() 产生的是伪随机数字，每次执行时是相同的; 若要不同, 用函数 srand() 初始化它。 范围：0 至 RAND_MAX (2^15-1)间
 * (2) srand() 用来设置 rand() 产生随机数时的随机数种子。参数 seed 必须是个整数，如果每次 seed 都设相同值，rand() 所产生的随机数值每次就会一样。
 *
 *
 *
 * Sleep(毫秒) :  windows下支持，需要引入头文件windows.h; linux下支持，需要引入头文件unistd.h
 * */

// 存储年月日的是一个结构体 tm
//struct tm
//{
//    int tm_sec;  /*秒，正常范围0-59， 但允许至61*/
//    int tm_min;  /*分钟，0-59*/
//    int tm_hour; /*小时， 0-23*/
//    int tm_mday; /*日，即一个月中的第几天，1-31*/
//    int tm_mon;  /*月， 从一月算起，0-11*/  1+p->tm_mon;
//    int tm_year;  /*年， 从1900至今已经多少年*/  1900＋ p->tm_year;
//    int tm_wday; /*星期，一周中的第几天， 从星期日算起，0-6*/
//    int tm_yday; /*从今年1月1日到目前的天数，范围0-365*/
//    int tm_isdst; /*日光节约时间的旗标*/
//};


void demo1()
{
    time_t t;   // time_t 这种类型就是用来存储从1970年到现在经过了多少秒 ; time_t实质上是一个long long类型

    time_t cur_t = time(&t);    // 获取time_t类型当前时间, 和t其实一样，秒数
    time_t cur_t1 = time(nullptr);      // 用nullptr也可以
    cout << cur_t << "  " << t << "  " << cur_t1 << endl;


    tm * cur_tm_t = gmtime(&t);     //  获取tm类型当前时间, 结构体如上所示
    cout << cur_tm_t->tm_year << "  " << cur_tm_t->tm_mday << endl;

    time_t cur_time_t = mktime(cur_tm_t);       // 将tm类型的时间转为time_t类型时间
    cout << cur_time_t << endl;

    string utc_cur_tmie = asctime(gmtime(&t));      // 没有经过时区转换的UTC(格林威治)时间 ->> unix系统的date命令所打印的时间
    cout << utc_cur_tmie << endl;

    string bj_time = ctime(&t);     // 获得时区转换后的时间，即本地时间（北京时间）
    cout << bj_time << endl;

    clock_t c1 = clock();
    Sleep(1000);           // windows下支持，需要引入头文件windows.h; linux下支持，需要引入头文件unistd.h
    clock_t c2 = clock();
    cout << "xxxxxxx: " << (double)(c2 -c1)/CLOCKS_PER_SEC << "   " << c2 << endl;
    cout << CLOCKS_PER_SEC << endl;
}

// 产生一定范围随机数的通用表示公式
// 1.要取得 [a,b) 的随机整数，使用 (rand() % (b-a))+ a;
// 2.要取得 [a,b] 的随机整数，使用 (rand() % (b-a+1))+ a;
// 3.要取得 (a,b] 的随机整数，使用 (rand() % (b-a))+ a + 1;
//
// 通用公式: a + rand() % n；其中的 a 是起始值，n 是整数的范围。
// 要取得 a 到 b 之间的随机整数，另一种表示：a + (int)b * rand() / (RAND_MAX + 1)。
// 要取得 0～1 之间的浮点数，可以使用 rand() / double(RAND_MAX)。

void demo2(){
    int a = rand();         //  0 至 RAND_MAX 间; 产生的是伪随机数字，每次执行时是相同的;
    cout << rand() << "  " << rand() << endl;
    time_t t;
//    srand((unsigned int) time(&t));     // 一般用时间作为seed
    srand((unsigned int) time(nullptr));    //
    cout << rand() << "  " << rand() << endl;

}

int main()
{
    demo1();
//    demo2();
    cout << endl;
    cout << is_same<time_t, long long >() << endl;  // true
    cout << is_same<clock_t, long>() << endl;  //true
    return 0;
}