#include<iostream>
#include"object.h"



void Pet::set(int age_)
{
	Pet::age = age_;
}


void Pet::set(const std::string & name_)
{
	Pet::name = name_;
}

int Pet::set(int i, int j) const 
{
	std::cout << "sunhongjiang" << std::endl;
	return i + j;

}