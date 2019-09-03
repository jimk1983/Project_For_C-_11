#include "pch.h"
#include <string.h>
#include <vector>
#include <iostream>


#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
	return a < b; //升序排列，如果改为return a>b，则为降序 
}


void vector_high()
{
	int N = 5, M = 6;
	vector<vector<int> > obj(N); //定义二维动态数组大小5行 
	//这种是直接定义的
	//vector<vector<int> > obj(N, vector<int>(M)); //定义二维动态数组5行6列 

	cout << "vector size=" << obj.size() << endl;
	cout << "vector size=" << obj[0].size() << endl;

	//动态二维数组为5行6列，值全为0 
	for (int i = 0; i < obj.size(); i++)
	{
		obj[i].resize(M);
	}

	//输出二维动态数组 
	for (int i = 0;  i < obj.size();  i++)
	{
		for (int j = 0;  j < obj[i].size();  j++)
		{
			cout << obj[i][j] << " ";
		}
		cout << "\n";
	}


}

int vector_main()
{
	vector <int> obj;


	//插入数据
	for (int i = 0; i < 10; i++)
	{
		obj.push_back(i);
		cout << obj[i] << ",";
	}

	//移除数据
	for (int i =0; i < 5; i++)
	{
		obj.pop_back();
	}

	cout << "\n" << endl;
	//访问数据
	for (unsigned int i=0; i < obj.size(); i++)
	{
		cout << obj[i] << ",";
	}

	cout << "\n" << endl;

	//清除数据
	obj.clear();

	obj.push_back(1);
	obj.push_back(3);
	obj.push_back(0);
	obj.push_back(5);
	obj.push_back(8);
	obj.push_back(6);

	//算法: 从小到大排序
	sort(obj.begin(), obj.end());

	for (int i=0; i<obj.size(); i++)
	{
		cout << obj[i] << ",";
	}
	cout << "\n" << endl;

	//算法： 从大到小排序
	reverse(obj.begin(), obj.end());

	for (int i = 0; i < obj.size(); i++)
	{
		cout << obj[i] << ",";
	}

	cout << "\n" << endl;

	cout << "利用迭代器输出:";
	//使用迭代器将容器中数据输出 
	vector<int>::iterator it;//声明一个迭代器，来访问vector容器，作用：遍历或者指向vector容器的元素 
	for (it = obj.begin(); it != obj.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n" << endl;


	//高级用法
	vector_high();
	//
	//算法： 自定义升序降序
	int a[20] = { 2,4,1,23,5,76,0,43,24,65 }, i;
	for (i = 0; i < 20; i++)
		cout << a[i] << ",";

	cout << "\n" << endl;

	sort(a, a + 20, compare);
	for (i = 0; i < 20; i++)
		cout << a[i] << ",";
	cout << "\n" << endl;
	return 0;
}







