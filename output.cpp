#include <iostream>
#include <stdlib.h>

using namespace std;

void exit();

void transpore(int** array, int quan)
{
	for (int j = 0; j < quan; j++)
	{
		int buf = array[j][0];
		array[j][0] = array[j][1];
		array[j][1] = buf;
	}
}

void out1(int** arr, int n, int m, int coun) 
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			bool f3 = false;
			for (int i1 = 0; i1 < coun; i1++)
			{
				if ((arr[i1][0] == i) && (arr[i1][1] == j))
				{
					if (arr[i1][2] > 9)
					{
						printf("%d ", arr[i1][2]);
						f3 = true;
					}
					else
					{
						printf(" %d ", arr[i1][2]);
						f3 = true;
					}
				}
			}
			if (f3 == true)
				continue;
			else
				printf(" 0 ");
		}
		cout << endl;
	}
}

void out2(int **arr, int n, int m, int coun)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < coun; j++)
		{
			if (arr[j][i] > 9)
				printf("%d ", arr[j][i]); 
			else
				printf(" %d ", arr[j][i]); 
		}
		cout << endl;
	}
}

void clearm(int** arr, int n)
{
	for (int i = 0; i < n; i++)
		free(arr[i]);
	free(arr);
}

void output(int** array1, int** array2, int** array3, int quantity_digits1, int quantity_digits2, int con, int n, int m)
{
	while (true)
	{
		system("cls");
		cout << " ---------------- Output ---------------- " << endl;
		cout << " 1. Output as a normal matrix " << endl;
		cout << " 2. Output as a normal matrix and transpose " << endl;	
		cout << " 3. Output as a coordinate-value pairs " << endl;
		cout << " 4. Output as a coordinate-value pairs and transpose " << endl;	
		cout << " 5. Back " << endl;
		cout << " 6. Exit " << endl;
		char flag;
		int f2 = 0;
		cin >> flag;
		switch (flag)
		{
			case'1':
			{
				system("cls");
				puts("\n Array 1 \n");
				out1(array1,n,m,quantity_digits1);				
				puts("\n Array 2 \n");
				out1(array2,n,m,quantity_digits2);
				puts("\n Array 3 \n");
				out1(array3,n,m,con);
				cout << endl << " Next step " << endl;
				cout << " 1. Back " << endl;
				cout << " 2. Exit " << endl;
				char flag;
				cin >> flag;		
				switch (flag)
				{
					case '1':
					{
						break;
					}
					case '2':
					{
						exit();
					}
				}
				break;
			}
			case'2':
			{
				system("cls");

				puts("\n Array 1 \n");
				transpore(array1, quantity_digits1);
				out1(array1,n,m,quantity_digits1);
				
				puts("\n Array 2 \n");
				transpore(array2, quantity_digits2);
				out1(array2,n,m,quantity_digits2);
				
				puts("\n Array 3 \n");
				transpore(array3, con);
				out1(array3,n,m,con);

				cout << endl << " Next step " << endl;
				cout << " 1. Back " << endl;
				cout << " 2. Exit " << endl;

				char flag;
				cin >> flag;
				switch (flag)
				{
					case '1':
					{
						break;
					}
					case '2':
					{
						exit();
					}
				}
				break;
			}
			case'3':
			{
				system("cls");
				cout << " First there are coordinates, then there are numbers, for example " << endl;
				cout << " row    " << endl;
				cout << " colum  " << endl;
				cout << " Number " << endl;
				puts("\n Array 1 \n");
				out2(array1, n, m, quantity_digits1);
				puts("\n Array 2 \n");
				out2(array2, n, m, quantity_digits2);
				puts("\n Array 3 \n");
				out2(array3, n, m, con);
				cout << endl << " Next step " << endl;
				cout << " 1. Back " << endl;
				cout << " 2. Exit " << endl;
				char flag;
				cin >> flag;
				switch (flag)
				{
					case '1':
					{
						break;
					}
					case '2':
					{
						exit();
					}
				}
				break;	
			}
			case'4':
			{
				system("cls");
				cout << " First there are coordinates, then there are numbers, for example " << endl;
				cout << " row    " << endl;
				cout << " colum  " << endl;
				cout << " Number " << endl;
				puts("\n Array 1 \n");
				transpore(array1, quantity_digits1);
				out2(array1, n, m, quantity_digits1);
				puts("\n Array 2 \n");
				transpore(array2, quantity_digits2);
				out2(array2, n, m, quantity_digits2);
				puts("\n Array 3 \n");
				transpore(array3, con);
				out2(array3, n, m, con);
				cout << endl << " Next step " << endl;
				cout << " 1. Back " << endl;
				cout << " 2. Exit " << endl;
				char flag;
				cin >> flag;
				switch (flag)
				{
					case '1':
					{
						break;
					}
					case '2':
					{
						exit();
					}
				}
				break;	
			}	
			case'5':
			{
				system("cls");
				f2 = 1;
				break;
			}		
			case'6':
			{
				exit();
			}
		}
		if (f2 == 1)
			break;
	}
}