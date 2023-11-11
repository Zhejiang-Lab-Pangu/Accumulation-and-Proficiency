//
// Created by root on 11/2/23.
//


#include <iostream>
#include <unistd.h>
using namespace std;



int main(){

    int i=0;
    while(true){
        i++;
        cout << "main-mian-mian-" << i << endl;
        sleep(1);
    }
}