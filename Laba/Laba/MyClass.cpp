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
	
		cout << "-------- ���� #" << ++t << "--------" << endl;
		cout << "       ������� � 32"<<endl;
		cout << "    |a/b+11,   ���� a > b"<<endl;
		cout << "X = |-11,      ���� a = b"<<endl;
		cout << "    |(3*b-9)/a,   ���� a < b"<<endl<<endl;
		//try
		//{
		cout << "������� ������ ������� �: ";
		cin >> size_a;
		while (size_a<=0 || size_a>1000)
		{
			cout <<"������. ��������� ������ ������� �: ";
			cin >> size_a;
		}
		cout << "������� ������ ������� �: ";
		cin >> size_b;
		while (size_b<=0 || size_b>1000)
		{
			cout <<"������. ��������� ������ ������� B: ";
			cin >> size_b;
		}

		/*}	

	catch(char* v )
	{
	cout << "\n!!!!! ��������� �������������� ��������." << endl;
	cout << "������: ";
	cout << v  << endl;
	return 0;
	}*/

	Array a(size_a), b(size_b), c(size_a > size_b ? size_b : size_a);
	const int MIN=-INT_MIN;
	const int MAX=INT_MAX;
	if (size_a >= 10)
	{
		a.generate();
		cout <<"�������� ������� ��������������� ��������� �������:"<<endl;
		cout << "\n�������� ������� �:"<<endl;
		cout<<a; 
		cout<<endl;
	}
		else 
	{
		cout << "\n������� �������� ������� �:" << endl;
		cin>>a;
		cout<<endl;
			}

	if (size_b >= 10)
	{
	  b.generate();
      cout <<"�������� ������� ��������������� ��������� �������:"<<endl;
	  cout << "\n�������� ������� B:"<<endl;
	  cout<<b;
	  cout<<endl;
	}
		else
	{
	cout << "\n������� �������� ������� �:" << endl;
	cin>>b;
	cout<<endl;
	}

	if(a == b)
	{
	cout <<endl<< "������ � = ������� B"<<endl;
					c = -11;
					/*try
	{ 
		c.prov (MAX);
			}
		catch(char* v )
	{
	cout << "\n!!!!! ��������� �������������� ��������." << endl;
	cout << "������: ";
	cout << v  << endl;
	return 1;
	}*/
					cout<<"X: \n"<<c<<endl;

	}
	else
		if(a > b)
		{
			cout<<"������ A > ������� B"<<endl;
			c = ( a/ b) + 11;
			try
	{ c.prov (MAX);
			}
		catch(char* v )
	{
	cout << "\n!!!!! ��������� �������������� ��������." << endl;
	cout << "������: ";
	cout << v  << endl;
	return 1;
	}
			cout<<"X: \n"<<c<<endl;
		}
		else
		{
			cout<<"������ A < ������� B"<<endl;	
			c = (3*b-9)/a;
			try
	{ c.prov (MAX);
			}
		catch(char* v )
	{
	cout << "\n!!!!! ��������� �������������� ��������." << endl;
	cout << "������: ";
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
