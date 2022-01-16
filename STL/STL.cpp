#include<iostream>
#include<array>
#include<vector>
using namespace std;

#define tab "\t"

//#define STL_ARRAY
#define STL_VECTOR

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
	
	int insert_index, insert_element;
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
	cout << endl;
	/*vector<vector<int>> vec2;
	cout << "Size:	   " << vec2.size() << endl;
	cout << "Capacity: " << vec2.capacity() << endl;
	cout << "MaxSize:  " << vec2.max_size() << endl;*/
	
#endif // STL_VECTOR

}