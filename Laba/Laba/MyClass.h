#include <iostream>
#include <windows.h> 
#include <limits.h>
char* ErrorZero = "������� �� ���� ���������� !!!!!!!";
char* ErrorSize = "������ ������� ������������� ��� ����� 0";
char* ErrorInt = "�������� ������� ������� �� ��������";
using namespace std;
  
//����� array - ���������� ������������ ������ ����� �����
class Array
{
public:
	//����������� � ���������� size
    Array(int size);
	//����������
    ~Array();
	Array(Array &);
	//������� ��������� ����� ��������
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
	//���������
    int *arr;
	//������ �������
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
	//�������� ������ ��� ������ arr �������� size
	arr = new int[size];
	}
//����������
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
	//������������� f-�������� ������ ���� ��������� �������
	//�������� ������ out << ���������� �������� �stream&. 
ostream &operator<<(ostream &output, const Array &rhs)
{
	for (int i = 0; i < rhs.size; i++)
	{
		//����� �������
		output << rhs.arr[i] << " ";
	}
	return output;
}
	//������������� f-�������� ����� ���� ��������� �������
	//�������� ����� input >> ���������� �������� istream&. 
istream &operator>>(istream &input, const Array &rhs)
{
	for (int i = 0; i < rhs.size; i++)
	{
		//���� �������
		input >> rhs.arr[i];
	}
	return input;
}
//������������� �������� ">" ��� �������
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

bool Array::operator>(const int &rhs) //�������� ����������� ����
{
	try
	{
	for (int i=0; i<size; i++)
		if (arr [i] >rhs ) throw ErrorInt;
	return 0;
	}
		catch(char* v )
	{
	cout << "\n!!!!! ��������� �������������� ��������." << endl;
	cout << "������: ";
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
//	cout << "\n!!!!! ��������� �������������� ��������." << endl;
//	cout << "������: ";
//	cout << v  << endl;
//	return 1;
//	}
//}

//������������� �������� "<" ��� �������
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
bool Array::operator<(const int &rhs)  //�������� ����������� int
{
	try
	{
	for (int i=0; i<size; i++)
		if (arr [i] <rhs ) throw ErrorInt;
	return 0;
	}
		catch(char* v )
	{
	cout << "\n!!!!! ��������� �������������� ��������." << endl;
	cout << "������: ";
	cout << v  << endl;
	return 1;
	}
}

//������������� �������� "==" ��� �������
bool Array::operator==(const Array &rhs)
{	if (size !=rhs.size)   // ������������ ������� ������ ��������
		return 0;
	for (int i=0; i<size; i++)
		if (arr [i] !=rhs.arr[i] ) // �������� �������� �� �����
			return 0;
	return 1;                       // ������� �����
}

//������������� �������� "=" ��� �������
Array Array::operator=(const int &rhs)
{	
	for (int i = 0; i < size; i++)
	{
		arr[i] = rhs;
	}
	return *this;
}
//������������� �������� "-" ��� �������
Array Array::operator-(const int &rhs)
{
	Array x(*this);
	for (int i = 0; i < size; i++)
		x.arr[i]-= rhs;
	return x;
}
//������������� �������� "+" ��� �������
Array Array::operator+(const int &rhs)
{
	Array x(*this);
	for (int i = 0; i < size; i++)
		x.arr[i]+= rhs;
	return x;
}
//������������� �������� "*" ��� �������
Array operator*(const int &left, const Array &rhs)
{
	Array x(rhs.size); 
	for (int i = 0; i < rhs.size; i++)		
		x.arr[i] = left*rhs.arr[i];
	return x;
}

//������������� �������� "/" ��� �������
Array Array::operator/(const Array &rhs)
	{
		try
		{
		Array x(size< rhs.size? size : rhs.size);
		if(size>rhs.size) //���� � ������ �
		{
			for (int i = 0; i < rhs.size; i++)
			{
				if (rhs.arr[i]==0) throw ErrorZero;
				x.arr[i] = arr[i]/rhs.arr[i];
			}

		return x;		
		}
			else // ���� � ������ �
			for (int i = 0; i < x.size; i++)
			{
				if (rhs.arr[i]==0) throw ErrorZero;
				x.arr[i]=arr[i]/rhs.arr[i];
			}
		return x;
		}
	
	catch(char* v )
		{
		cout << "\n!!!!! ��������� �������������� ��������." << endl;
		cout << "������: ";
		cout << v  << endl;
		return 0;
		}
	}
