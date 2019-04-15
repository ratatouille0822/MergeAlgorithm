// MergeAlgorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>


using namespace std;

struct MyPrint
{
	void operator()(int value)
	{
		cout << value << "->" ;

	}
};


void test01()
{
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;



	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(rand() % 20);
	}
	for (int i = 0; i < 13; i++)
	{
		v2.push_back(rand() % 20);
	}

	v3.resize(v1.size() + v2.size());
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << endl;
	for_each(v3.begin(), v3.end(), MyPrint());
}

void test02()
{
	vector<int> v21;
	for (int i = 0; i < 10; i++)
	{
		v21.push_back(i);
	}

	for_each(v21.begin(), v21.end(), MyPrint());
	cout << endl;
	random_shuffle(v21.begin(), v21.end());
	for_each(v21.begin(), v21.end(), MyPrint());
	cout << endl;

}

void test03()
{
	vector<int> v31;
	for (int i = 0; i < 10; i++)
	{
		v31.push_back(i);
	}

	for_each(v31.begin(), v31.end(), MyPrint());
	cout << endl;
	reverse(v31.begin(), v31.end());
	for_each(v31.begin(), v31.end(), MyPrint());
	cout << endl;

}
int main()
{
	test01();
	cout << endl;
	test02();	
	cout << endl;
	test03();	
	cout << endl;
    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
