#include "MyClass.h"
#include <conio.h>
#include <typeinfo.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(1251); 
	int size_a, size_b, size_c, ESC=27, r ,t=0;
	do
	{
	
		cout << "-------- Тест #" << ++t << "--------" << endl;
		cout << "       Вариант № 32"<<endl;
		cout << "    |a/b+11,   если a > b"<<endl;
		cout << "X = |-11,      если a = b"<<endl;
		cout << "    |(3*b-9)/a,   если a < b"<<endl<<endl;
		//try
		//{
		cout << "Введите размер вектора А: ";
		cin >> size_a;
		while (size_a<=0 || size_a>1000)
		{
			cout <<"Ошибка. Повторите размер вектора А: ";
			cin >> size_a;
		}
		cout << "Введите размер вектора В: ";
		cin >> size_b;
		while (size_b<=0 || size_b>1000)
		{
			cout <<"Ошибка. Повторите размер вектора B: ";
			cin >> size_b;
		}

		/*}	

	catch(char* v )
	{
	cout << "\n!!!!! Обработка исключительной ситуации." << endl;
	cout << "Ошибка: ";
	cout << v  << endl;
	return 0;
	}*/

	Array a(size_a), b(size_b), c(size_a > size_b ? size_b : size_a);
	const int MIN=-INT_MIN;
	const int MAX=INT_MAX;
	if (size_a >= 10)
	{
		a.generate();
		cout <<"Елементы массива сгенерированные случайным образом:"<<endl;
		cout << "\nЭлементы массива А:"<<endl;
		cout<<a; 
		cout<<endl;
	}
		else 
	{
		cout << "\nВведите элементы массива А:" << endl;
		cin>>a;
		cout<<endl;
			}

	if (size_b >= 10)
	{
	  b.generate();
      cout <<"Елементы массива сгенерированные случайным образом:"<<endl;
	  cout << "\nЭлементы вектора B:"<<endl;
	  cout<<b;
	  cout<<endl;
	}
		else
	{
	cout << "\nВведите элементы вектора В:" << endl;
	cin>>b;
	cout<<endl;
	}

	if(a == b)
	{
	cout <<endl<< "вектор А = вектору B"<<endl;
					c = -11;
					/*try
	{ 
		c.prov (MAX);
			}
		catch(char* v )
	{
	cout << "\n!!!!! Обработка исключительной ситуации." << endl;
	cout << "Ошибка: ";
	cout << v  << endl;
	return 1;
	}*/
					cout<<"X: \n"<<c<<endl;

	}
	else
		if(a > b)
		{
			cout<<"вектор A > вектора B"<<endl;
			c = ( a/ b) + 11;
			try
	{ c.prov (MAX);
			}
		catch(char* v )
	{
	cout << "\n!!!!! Обработка исключительной ситуации." << endl;
	cout << "Ошибка: ";
	cout << v  << endl;
	return 1;
	}
			cout<<"X: \n"<<c<<endl;
		}
		else
		{
			cout<<"вектор A < вектора B"<<endl;	
			c = (3*b-9)/a;
			try
	{ c.prov (MAX);
			}
		catch(char* v )
	{
	cout << "\n!!!!! Обработка исключительной ситуации." << endl;
	cout << "Ошибка: ";
	cout << v  << endl;
	return 1;
	}
			cout<<"X: \n"<<c<<endl;
		}
			
			r=_getch();
						
	}
	
	while(r!=27);

	return 0;

} 
