#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_DEQUE
#define STL_LIST

template<typename T>void print(const std::vector<T>& vec)
{
	for (typename std::vector<T>::const_iterator it = vec.begin(); it != vec.end(); it++)
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
#ifdef STL_DEQUE
	std::deque<int> deque = { 3,5,8,13,21 };
	deque.push_back(34);
	deque.push_back(55);
	deque.push_back(89);
	
	deque.push_front(2);
	deque.push_front(1);
	deque.push_front(1);
	deque.push_front(0);
	for (int i = 0; i < deque.size(); i++)
	{
		cout << deque[i] << tab;
	}
	cout << endl;
#endif // STL_DEQUE
#ifdef STL_LIST
	std::list<int> list = { 3,5,8,13,21 };
	for (int i : list)cout << i << tab; cout << endl;
	
	//insert
	int insert_element;
	int insert_index;
	int insert_count;
	cout << "Введите индекс добавляемого элемента: "; cin >> insert_index;
	cout << "Введите количество добавляемого элемента: "; cin >> insert_count;
	cout << "Введите значение добавляемого элемента: "; cin >> insert_element;
	std::list<int>::iterator iterator = list.begin();
	for (int i = 0; i < insert_index; i++)iterator++;
	list.insert(iterator, insert_count ,insert_element);
	for (int i : list)cout << i << tab; cout << endl;

	//erase
	/*int erase_index;
	cout << "Введите индекс удаляемого элемента: "; cin >> erase_index;
	std::list<int>::iterator position = list.begin();
	for (int i = 0; i < erase_index; i++)position++;
	list.erase(position);
	for (int i : list)cout << i << tab; cout << endl;*/

	int begin;
	int end;
	cout << "Введите диапазон удаляемых значений!" << endl;
	cout << "Удалить: " << endl;
	cout << "от "; cin >> begin; 
	cout << "до "; cin >> end;
	std::list<int>::iterator it1, it2;
	it1 = it2 = list.begin();
	for (int i = 0; i < begin; i++)it1++;
	std::advance(it2, end);
	list.erase(it1, it2);
	for (int i : list)cout << i << tab; cout << endl;
#endif // STL_LIST

	
}