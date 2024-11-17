#include <iostream>

using namespace std;

void exit();

void about()
{
	while (true)
	{
		system("cls");

		cout << " ---------------- About ---------------- " << endl;
		cout << " 1. Program " << endl;
		cout << " 2. Author " << endl;
		cout << " 3. Back " << endl;
		cout << " 4. Exit " << endl;

		int f = 0;
		char flag2;
		cin >> flag2;

		switch (flag2)
		{
			case '1.':	
			case '1' :	
			{
				system("cls");
				cout << " About Program: " << endl;
				cout << " This program adds or multiplies two sparse matrices and displays the result on the screen " << endl;				
				system("pause");
				break;
			}	
			case '2.':	
			case '2' :	
			{
				system("cls");
				cout << " About Author: " << endl;
				cout << " This program is written by the second year student Mankouski Mikhail " << endl;			
				system("pause");
				break;
			}	
			case '3.':	
			case '3' :	
			{
				system("cls");
				f = 1;
				break;
			}	
			case '4.':	
			case '4' :	
			{
				exit();
				break;

			}
		}
		if (f==1)
			break;
	}
}