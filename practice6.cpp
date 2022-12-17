/* Изучите основные операции над вектором и продемонстрируйте их работу :

1.	push_back, erase, insert
2.	emplace_back (push_back и emplace_back создают новый 
объект в контейнере. push_back делает это 
при помощи конструктора копирования, а emplace_back 
может делать это при помощи любого конструктора)
3.	resize, reserve, shrink_to_fit, capacity
4.	clear
5.	оператор присваивания и [] */


#include <iostream>
#include <vector> 
#include <string>
using namespace std;

int main()
{
	vector<int> meow;
	meow.push_back(19); // добавляет элемент в конец
	meow.push_back(7);
	meow.push_back(5);
	for (int n : meow)
		cout << "meow:" << n << "\n";

	vector<int> bark = { 2, 4, 6, 8, 10 };
	auto d = bark.cbegin(); // константный итератор указывает на первый элемент
	bark.erase(d + 3);   // удаление 4-го элемента
	bark.insert(d + 4, 12); //добавление 5-го элемента
	for (int n : bark)
		cout << "bark:" << n << "\n";

	vector<int> moo = { 1, 3, 5, 7, 9, 11, 13 };
	auto s = moo.cbegin(); // указатель на первый элемент
	auto e = moo.cend(); // указатель на последний элемент
	moo.erase(s + 2, e - 1); // удаление элементов из диапазона
	moo.insert(s + 2, 3, 0); //добавление нуля 3 раза начиная с 3-го элемента
	for (int n : moo)
		cout << "moo:" << n << "\n";

	vector<int> kva = { 1321, 432, 65, 349, 304, 43 };
	auto l = kva.cbegin();
	kva.emplace_back(1); //добавление элемента в конец
	kva.resize(5); //в векторе остаются первые 5 элементов 
	kva.resize(10, 0); //изменение рамера до 10 элементов и добавление 0, если размер был меньше
	for (int n : kva)
		cout << "kva:" << n << "\n";

	vector <int> roar = {32, 43, 4, 1, 78};
	roar.reserve(10); //резервирует место для заполнения
	
	cout << "roar capacity: " << roar.capacity() << endl; // показывает, сколько выделено места для вектора
	cout << "roar size: " << roar.size() << endl; // показывает, сколько на деле места занимает вектор
	
	vector <int> oink = { 234, 12, 55, 9, 0, 23 };
	oink.reserve(8); //резервирует место для заполнения
	oink.shrink_to_fit(); //уменьшает зарезервированное место, чтобы соответствовать размеру (size) вектора
	cout << "oink capacity: " << oink.capacity() << endl; //теперь вектор занимает столько же места, сколько и его размер
	
	meow.clear(); //удаляет все элементы вектора и делает его размер равным 0
	cout << "meow size: " << meow.size() << endl;
	
	bark[2] = 1; // изменяем значение 3-го элементы вектора, т.е. 6 на 1 
	cout << "bark[3]: "<< bark[2] << endl; //вывод 3-го элемента вектора
	cout << "bark[5]: " << bark[4] << endl; //вывод 5-го элемента вектора
	system("pause");
	return 0;
} 
