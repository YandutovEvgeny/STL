﻿#include<iostream>
#include<array>
#include<vector>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

//#define STL_ARRAY
#define STL_VECTOR
template<typename T>void print(const vector<T>& vec)
{
	for (typename vector<T>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	array<int, 5>arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY
#ifdef STL_VECTOR
	vector<int> vec = {0,1,1,2,3,5,8,13,21,34,55,89,144,232};
	cout << "Size:	   " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl; //есть только у вектора
	cout << "MaxSize:  " << vec.max_size() << endl;
	vec.push_back(55);
	int* data = vec.data();
	try
	{ 
		for (int i = 0; i < vec.size(); i++)
		{
			//cout << vec[i] << tab;
			cout << vec.at(i) << tab;
		}
		cout << endl;
		//subscript - индексирование
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	

	/*int insert_index, insert_element;
	cout << "Введите индекс по которому хотите вставить значение: "; cin >> insert_index;
	cout << "Введите значение, которое хотите вставить: "; cin >> insert_element;
	vector<int>::iterator it;
	it = vec.begin();
	vec.insert(it + insert_index, insert_element);
	for (it = vec.begin(); it < vec.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;

	int erase_index;
	cout << "Введите индекс по которому хотите удалить значение: "; cin >> erase_index;
	vec.erase(vec.begin() + erase_index);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec.at(i) << tab;
	}
	cout << endl;*/  
	/*vector<vector<int>> vec2;
	cout << "Size:	   " << vec2.size() << endl;
	cout << "Capacity: " << vec2.capacity() << endl;
	cout << "MaxSize:  " << vec2.max_size() << endl;*/  
	
	int index;
	int value;
	int count;
	cout << "Введите индекс добавляемого элемента:\t"; cin >> index;
	cout << "Введите количество добавлений:\t\t"; cin >> count;
	cout << "Введите значение добавляемого элемента:\t"; cin >> value;
	//                    insert(position, count, value)
	if (index < vec.size())vec.insert(vec.begin() + index, count, value);
	else cout << "Error: out of range" << endl;
	print(vec);
	
	std::vector<int> powers = { 1024,2048,4096,8192,16384 };

	/*vec.insert(vec.begin() + 4, powers.begin(), powers.end());
	vec.insert(vec.begin() + 3, { 256,384,512,768 });
	for (int i : vec)cout << i << tab; cout << endl;*/

	/*vec.insert(vec.begin() + 4, vec.begin() + 15, vec.begin() + 17);
	for (int i : vec)cout << i << tab; cout << endl;*/

	cout << "Введите индекс удаляемого элемента:\t"; cin >> index;
	cout << "Введите количество добавлений:\t\t"; cin >> count;
	if (index <= vec.size())vec.erase(vec.begin() + index, vec.begin()+index+count);
	else cout << "Error: out of range" << endl;
	print(vec);

	cout << "\n---------------------------------------------------\n";
	vec.swap(powers);
	print(vec);
	print(powers);
#endif // STL_VECTOR

}