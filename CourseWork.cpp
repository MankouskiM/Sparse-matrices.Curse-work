#include <iostream>
#include <stdlib.h>

using namespace std;

#pragma warning(disable : 4996 );

void start();
void about();

void exit()
{
	puts("\n Bye! ");
	exit(0);
}

void main()
{
	while (true)
	{
		system("cls");

		cout << " ---------------- Menu ---------------- " << endl;
		cout << " 1. Start " << endl;
		cout << " 2. About " << endl;
		cout << " 3. Exit " << endl;

		char flag;
		cin >> flag;

		switch (flag)
		{
			case '1' :
			{
				puts("\n You've chosen \"Start\" ");
				start();
				break;
			}
			case '2' :
			{
				puts("\n You've chosen \"About\" ");
				about();
				break;
			}
			case '3' :
			{
				exit();
			}
		}
	}
}