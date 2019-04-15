#include "pch.h"

using namespace std;

struct MyPrint
{
	void operator()(int val)
	{
		cout << val<<"->";
	}
	int operator+(int val)
	{
		return val;
	}
};

struct MyCompare
{
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
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
	auto fun = MyPrint();
	MyPrint m;
	m.operator();
	//m + 1;
	//auto fun1 = MyPrint + 1;
	for_each(v1.begin(), v1.end(), fun);
	cout << endl;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	cout << "------------------------------------------------" << endl;
	
	for_each(v2.begin(), v2.end(), m);
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		v3.push_back(rand() % 20);
	}
	for_each(v3.begin(), v3.end(), MyPrint());
	cout << endl;
	cout << "------------------------------------------------" << endl;

	swap(v3, v2);
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << endl;
	for_each(v3.begin(), v3.end(), MyPrint());
	cout << endl;
	cout << "------------------------------------------------" << endl;


}

void test02()
{
	cout << "-------------test 02-------------" << endl;
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	for_each(v1.begin(), v1.end(), MyPrint());

	cout << endl;

	cout << "-------------test 02-------------" << endl;
}
int main()
{
	test01();
	cout << endl;
	test02();
	cout << endl;
    std::cout << "Hello World!\n"; 
}

