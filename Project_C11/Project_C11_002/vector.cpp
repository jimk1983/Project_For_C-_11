#include "pch.h"
#include <string.h>
#include <vector>
#include <iostream>


#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
	return a < b; //�������У������Ϊreturn a>b����Ϊ���� 
}


void vector_high()
{
	int N = 5, M = 6;
	vector<vector<int> > obj(N); //�����ά��̬�����С5�� 
	//������ֱ�Ӷ����
	//vector<vector<int> > obj(N, vector<int>(M)); //�����ά��̬����5��6�� 

	cout << "vector size=" << obj.size() << endl;
	cout << "vector size=" << obj[0].size() << endl;

	//��̬��ά����Ϊ5��6�У�ֵȫΪ0 
	for (int i = 0; i < obj.size(); i++)
	{
		obj[i].resize(M);
	}

	//�����ά��̬���� 
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


	//��������
	for (int i = 0; i < 10; i++)
	{
		obj.push_back(i);
		cout << obj[i] << ",";
	}

	//�Ƴ�����
	for (int i =0; i < 5; i++)
	{
		obj.pop_back();
	}

	cout << "\n" << endl;
	//��������
	for (unsigned int i=0; i < obj.size(); i++)
	{
		cout << obj[i] << ",";
	}

	cout << "\n" << endl;

	//�������
	obj.clear();

	obj.push_back(1);
	obj.push_back(3);
	obj.push_back(0);
	obj.push_back(5);
	obj.push_back(8);
	obj.push_back(6);

	//�㷨: ��С��������
	sort(obj.begin(), obj.end());

	for (int i=0; i<obj.size(); i++)
	{
		cout << obj[i] << ",";
	}
	cout << "\n" << endl;

	//�㷨�� �Ӵ�С����
	reverse(obj.begin(), obj.end());

	for (int i = 0; i < obj.size(); i++)
	{
		cout << obj[i] << ",";
	}

	cout << "\n" << endl;

	cout << "���õ��������:";
	//ʹ�õ�������������������� 
	vector<int>::iterator it;//����һ����������������vector���������ã���������ָ��vector������Ԫ�� 
	for (it = obj.begin(); it != obj.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n" << endl;


	//�߼��÷�
	vector_high();
	//
	//�㷨�� �Զ���������
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







