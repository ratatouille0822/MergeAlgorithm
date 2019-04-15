#include "pch.h"
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

struct MyPrint
{
	void operator()(int i)
	{
		cout << i<<"->";
	}
};
void test01()
{
	//accumulate:
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(9);
	v.push_back(3);
	v.push_back(5);

	int ret = accumulate(v.begin(), v.end(), 0);

	cout << ret << endl;

	//fill:
	cout << "-------------------------v2--------------------" << endl;
	vector<int> v2;
	v2.resize(10);
	fill(v2.begin(), v2.end(), rand()%10);
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << endl;
}
void test02()
{
	vector<int> v1;
	vector<int>v2;

	
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for (int i = 5; i < 15; i++)
	{
		v2.push_back(i);
	}
	cout << "--------V1-----------" << endl; 
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
	cout << "--------V2-----------" << endl; 
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << endl;
	cout << "*********************" << endl;

	
	vector<int> v3;
	v3.resize(min(v1.size(), v2.size()));

	cout << "--------intersection-----------" << endl; 
	vector<int>::iterator it1 = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), it1, MyPrint());
	cout << endl;


	vector<int> v4;
	v4.resize(v1.size()+ v2.size());

	cout << "--------Union-----------" << endl; 
	vector<int>::iterator it2 = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v4.begin());
	for_each(v4.begin(), it2, MyPrint());
	cout << endl;

	cout << "--------Difference-----------" << endl; 
	vector<int> v5;
	v5.resize(max(v1.size(), v2.size()));
	vector<int>::iterator it3 = set_difference(v1.begin(), v1.end(), v2.begin(),v2.end(),v5.begin());
	for_each(v5.begin(),it3 , MyPrint());
	cout << endl;
}

int main()
{
	test01();
	cout << endl;
	test02();
	cout << endl;
    std::cout << "Hello World!\n"; 
}
