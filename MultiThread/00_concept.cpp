//
// Created by Administrator on 2023/11/1.
//


#include <iostream>
using namespace std;
#include <map>

// 并发
/*
 * 1.真正的并发： 多核计算机 -- 硬件并发
 *
 * */

// 可执行程序
/*
 * 1.磁盘上的一个文件
 * 2.能够运行
 * 3.可执行程序执行起来，就创建了一个进程；进程即为运行起来的可执行程序
 * */


// 线程
/*
 * 1. 每个进程(执行起来的可执行程序)，都有一个主线程，这个主线程是唯一的，即一个进程只能有一个主线程
 * 2. 当执行可执行程序，建立进程后，主线程也跟随进程启动起来；
 * 3. 实际运行程序时，时进程中的主线程来执行(调用)main函数中的代码；
 * 4. 主线程与进程的生命周期完全一致的。
 *
 * 线程：一条代码的执行通路；
 *
 * 1. 没创建一个新线程，就可以干一个不同的事；
 * 2. 多线程（并发）；
 * 3. 线程并不是越多越好，内个线程都需要独立的堆栈空间（1M），且线程切换要保存很多中间状态，耗时（过多线程反而耗时）；
 * */


// 并发的实现方法
/*
 * 1. 多进程实现并发；
 *      (1) 进程之间的通信：
 *          ① 同一台电脑： 管道、文件、消息队列、共享内存
 *          ② 不同电脑：socket通信技术
 *
 * 2. 多线程实现并发；（写代码创建除主线程之外的线程）
 *      (1) 一个进程中的所有线程共享内存；
 *      (2) 全局变量、指针、引用等都可在线程之间传递；开销远小于进程；
 *      (3) 共享内存带来的问题：数据一致性。
 *
 * 3. 多进程和多线程可以混合使用，但优先考虑多线程技术手段
 *
 * */


// C++11新标准线程库
/*
 * C++语言本身增加了对多线程的支持，可跨平台
 *
 * */


#include <vector>
#include <algorithm>





int main() {

    return 0;
}
