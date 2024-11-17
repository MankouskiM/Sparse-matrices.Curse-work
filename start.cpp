#include <iostream>

using namespace std;

void generator(int**& array1, int**& array2, int &quantity_digits1, int &quantity_digits2, int n, int m);
void addition(int** array1, int** array2, int quantity_digits1, int quantity_digits2, int n, int m);
void multiplication(int** array1, int** array2, int quantity_digits1, int quantity_digits2, int n, int m);

void exit();
void check(int**& arr, int& quan);

void part1() 
{
	system("cls");
	cout << " Now you will have to type your array. Type it like this: " << endl;
	cout << " Firstly type in coordinate x " << endl;
	cout << " Secondly type in coordinate y " << endl;
	cout << " At last type in a number which is located at the coordinates [x,y] " << endl;
}

void part2() 
{
	system("cls");
	cout << " Choose what you will do with the arrays: " << endl;
	cout << " 1. Addition " << endl;
	cout << " 2. Multiplication " << endl;
	cout << " 3. Back " << endl;
	cout << " 4. Exit " << endl;
}

void start()
{

	while (true)
	{
		system("cls");
		cout << " ---------------- Start ---------------- " << endl;
		cout << " 1. Type in array by hand " << endl;
		cout << " 2. Create array automatically " << endl;
		cout << " 3. Back " << endl;
		cout << " 4. Exit " << endl;

		char flag1;
		int f = 0;
		cin >> flag1;

		switch (flag1)
		{
			case '1':
			{
				system("cls");
				puts(" Type in number of lines and colums on sparse matrix ");
				
				int n, m;
				int f2 = 0;
				cin >> n >> m;

				puts(" Type in maximum number of nonzero elements for both the first and second array ");
				
				int quantity_digits1, quantity_digits2;
				cin >> quantity_digits1 >> quantity_digits2;

				if (quantity_digits1 > (n * m))
				{
					puts(" Array index is out of paunts. Try again ");
					system("pause");
					f2 = 1;
					break;
				}
				if (quantity_digits2 > (n * m))
				{
					puts(" Array index is out of paunts. Try again");
					system("pause");
					f2 = 1;
					break;
				}
				
				int** array1 = new int* [quantity_digits1];
				for (int j = 0; j < quantity_digits1; j++)
					array1[j] = new int[3];
				
				int** array2 = new int* [quantity_digits2];
				for (int j = 0; j < quantity_digits2; j++)
					array2[j] = new int[3];

				part1();

				for (int j = 0; j < quantity_digits1;j++)
				{
					for (int i = 0; i < 3; i++)
					{
						cin >> array1[j][i];
					}
				}
			
				check(array1, quantity_digits1);

				part1();

				for (int j = 0; j < quantity_digits2; j++)
				{
					for (int i = 0; i < 3; i++)
					{
						cin >> array2[j][i];
					}
				}
				check(array2, quantity_digits2);

				part2();

				char flag4;
				cin >> flag4;

				switch (flag4)
				{		
					case '1':
					{
						puts(" You've chosen Addition ");
						addition(array1, array2, quantity_digits1, quantity_digits2, n, m);
					}
					case '2':
					{
						puts(" You've chosen Multiplication ");
						multiplication(array1, array2, quantity_digits1, quantity_digits2, n, m);
					}
					case '3':
					{
						system("cls");
						f2 = 1;
						break;
					}
					case '4':
					{
						exit();
					}
				}
				if (f2 == 1)
					break;
			}
			case '2':
			{
				system("cls");
				puts(" Type in number of lines and colums on sparse matrix ");

				int n, m;
				int f2 = 0;
				cin >> n >> m;

				puts(" Type in maximum number of nonzero elements for both the first and second array ");

				int quantity_digits1, quantity_digits2;
				cin >> quantity_digits1 >> quantity_digits2;

				if (quantity_digits1 > (n * m))
				{
					puts(" Array index is out of bounds. Try again ");
					system("pause");
					f2 = 1;
					break;
				}
				if (quantity_digits2 > (n * m))
				{
					puts(" Array index is out of bounds. Try again");
					system("pause");
					f2 = 1;
					break;
				}

				int** array1 = new int* [quantity_digits1];
				for (int j = 0; j < quantity_digits1; j++)
					array1[j] = new int[3];

				int** array2 = new int* [quantity_digits2];
				for (int j = 0; j < quantity_digits2; j++)
					array2[j] = new int[3];

				generator(array1, array2, quantity_digits1, quantity_digits2, n, m);
				
				part2();
				char flag4;
				cin >> flag4;

				switch (flag4)
				{
					case '1':
					{
						puts(" You've chosen Addition ");
						addition(array1, array2, quantity_digits1, quantity_digits2, n, m);
					}
					case '2':
					{
						puts(" You've chosen Multiplication ");
						multiplication(array1, array2, quantity_digits1, quantity_digits2, n, m);
					}
					case '3':
					{
						system("cls");
						f2 = 1;
						break;
					}
					case '4':
					{
						exit();
					}
				}
				if (f2 == 1)
					break;
			}
			case '3':
			{
				system("cls");
				f = 1;
				break;
			}
			case '4': 
			{
				exit();
			}
		}
		if (f == 1)
			break;
	}
}