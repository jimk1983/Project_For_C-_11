// Project_const.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

int main()
{
	//1. 指向常量的指针, *ptr的值是固定的，不能被修改
	int age = 30;
	const int *ptr = &age;
	age = 31;
	std::cout << "1. age=" << age << std::endl;

	//2.  将
	int *ptr2 = NULL;
	//常规指针，不能赋值const指针
	//ptr2 = ptr;
	//const 指针可以赋值常规指针
	const int *ptr3 = ptr2;

	//3. 
	/*const int **pp2;
	int *p1;
	const int n = 12;
	pp2 = &p1;
	*pp2 = &n;
	*p1 = 10;
	printf("3. n=%d\n", n);*/

	int age1 = 10;
	int age2 = 20;
	int const *pa = &age1;
	//pa = &age2;

	printf("pa value=%d\n", *pa);

    std::cout << "Hello World!\n"; 
}

