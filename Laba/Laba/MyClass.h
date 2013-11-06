#include <iostream>
#include <windows.h> 
#include <limits.h>
char* ErrorZero = "Деление на ноль НЕВОЗМОЖНО !!!!!!!";
char* ErrorSize = "Размер массива отрицательный или равен 0";
char* ErrorInt = "Элементы массива выходят за диапазон";
using namespace std;
  
//класс array - одномерный динамический массив целых чисел
class Array
{
public:
	//конструктор с параметром size
    Array(int size);
	//деструктор
    ~Array();
	Array(Array &);
	//функция генерации чисел массивов
	void generate();
	int Lenght()
	{ return size;}
	Array operator - (const int&);
	Array operator + (const int&);
	Array operator / (const Array&);
	Array operator = (const int&);
	bool operator > (const Array&);
	bool operator > (const int &rhs);
	bool operator < (const int &rhs);
	bool operator < (const Array&);
	bool operator == (const Array&);
	friend ostream &operator<<(ostream &, const Array&);
	friend istream &operator>>(istream &, const Array&);
	friend Array operator*(const int&, const Array&);
	private:
	//указатель
    int *arr;
	//размер массива
    int size;
public:
	void prov(const int MAX=INT_MAX)
	{	
		for (int i=0; i<size; i++)
			if (fabs((double) arr[i])>MAX) throw ErrorInt;
		}
};

void Array::generate()
{
	for (int i=0; i < size; i++)
		{
			arr[i]= rand()%10;
			arr[i]=arr[i]+1;
	}
}
Array::Array(int size)
{
	this->size = size;
	//выделить память под массив arr размером size
	arr = new int[size];
	}
//деструктор
Array::~Array()
{
}
Array::Array(Array & rhs)
	{
		size = rhs.size;
		arr = new int [size];
		for (int i = 0; i<size; i++)
			arr[i] = rhs.arr[i];
	}
	//перегружаемая f-операция вывода всех элементов массива
	//Операция вывода out << возвращает значение оstream&. 
ostream &operator<<(ostream &output, const Array &rhs)
{
	for (int i = 0; i < rhs.size; i++)
	{
		//вывод массива
		output << rhs.arr[i] << " ";
	}
	return output;
}
	//перегружаемая f-операция ввода всех элементов массива
	//Операция ввода input >> возвращает значение istream&. 
istream &operator>>(istream &input, const Array &rhs)
{
	for (int i = 0; i < rhs.size; i++)
	{
		//ввод массива
		input >> rhs.arr[i];
	}
	return input;
}
//Перегружаемая операция ">" для массива
bool Array::operator>(const Array &a)
{
	for (int i=0; i<size; i++)
		{if (arr [i] >a.arr[i] )
			return true;
		else if(arr [i] <a.arr[i] )
			return false;}
	
	if(this->size>a.size)
		return true;
	return false;
}

bool Array::operator>(const int &rhs) //проверка переполненя инта
{
	try
	{
	for (int i=0; i<size; i++)
		if (arr [i] >rhs ) throw ErrorInt;
	return 0;
	}
		catch(char* v )
	{
	cout << "\n!!!!! Обработка исключительной ситуации." << endl;
	cout << "Ошибка: ";
	cout << v  << endl;
	return 1;
	}
}
//Array Array :: (int c, const int MIN=-INT_MIN, const int MAX=INT_MAX)
//{
//	try
//	{
//	if (fabsl(c)>MAX) throw ErrorInt;
//	return 0;
//	}
//		catch(char* v )
//	{
//	cout << "\n!!!!! Обработка исключительной ситуации." << endl;
//	cout << "Ошибка: ";
//	cout << v  << endl;
//	return 1;
//	}
//}

//Перегружаемая операция "<" для массива
bool Array::operator<(const Array &b)
{
	for (int i=0; i<size; i++)
		{if (arr [i] <b.arr[i] )
		return true;
			else if(arr [i] >b.arr[i] )
			return false;}
	return true;
	return false;
}
bool Array::operator<(const int &rhs)  //проверка переполненя int
{
	try
	{
	for (int i=0; i<size; i++)
		if (arr [i] <rhs ) throw ErrorInt;
	return 0;
	}
		catch(char* v )
	{
	cout << "\n!!!!! Обработка исключительной ситуации." << endl;
	cout << "Ошибка: ";
	cout << v  << endl;
	return 1;
	}
}

//Перегружаемая операция "==" для массива
bool Array::operator==(const Array &rhs)
{	if (size !=rhs.size)   // сравниваемые массивы разных размеров
		return 0;
	for (int i=0; i<size; i++)
		if (arr [i] !=rhs.arr[i] ) // элементы массивов НЕ равны
			return 0;
	return 1;                       // массивы равны
}

//Перегружаемая операция "=" для массива
Array Array::operator=(const int &rhs)
{	
	for (int i = 0; i < size; i++)
	{
		arr[i] = rhs;
	}
	return *this;
}
//Перегружаемая операция "-" для массива
Array Array::operator-(const int &rhs)
{
	Array x(*this);
	for (int i = 0; i < size; i++)
		x.arr[i]-= rhs;
	return x;
}
//Перегружаемая операция "+" для массива
Array Array::operator+(const int &rhs)
{
	Array x(*this);
	for (int i = 0; i < size; i++)
		x.arr[i]+= rhs;
	return x;
}
//Перегружаемая операция "*" для массива
Array operator*(const int &left, const Array &rhs)
{
	Array x(rhs.size); 
	for (int i = 0; i < rhs.size; i++)		
		x.arr[i] = left*rhs.arr[i];
	return x;
}

//Перегружаемая операция "/" для массива
Array Array::operator/(const Array &rhs)
	{
		try
		{
		Array x(size< rhs.size? size : rhs.size);
		if(size>rhs.size) //если а больше б
		{
			for (int i = 0; i < rhs.size; i++)
			{
				if (rhs.arr[i]==0) throw ErrorZero;
				x.arr[i] = arr[i]/rhs.arr[i];
			}

		return x;		
		}
			else // если б больше а
			for (int i = 0; i < x.size; i++)
			{
				if (rhs.arr[i]==0) throw ErrorZero;
				x.arr[i]=arr[i]/rhs.arr[i];
			}
		return x;
		}
	
	catch(char* v )
		{
		cout << "\n!!!!! Обработка исключительной ситуации." << endl;
		cout << "Ошибка: ";
		cout << v  << endl;
		return 0;
		}
	}
