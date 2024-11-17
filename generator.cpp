#include <stdlib.h>
#include <math.h>
#include <time.h>

void gen(int** arr, int quan,int n ,int m)
{
	for (int j = 0; j < quan; j++)
	{
			arr[j][0] = rand() % n;
			arr[j][1] = rand() % m;
			do
				arr[j][2] = rand() % 10;
			while (arr[j][2] == 0);
	}
}

void check(int** &arr, int& quan)
{
	int count = 0;

	int** buf_arr = new int* [quan];
	for (int j = 0; j < quan; j++)
		buf_arr[j] = new int[3];

	for (int j = 0; j < quan; j++)
	{
		bool f = false;
		for (int j2 = 0; j2 < count; j2++)
		{
			if((arr[j][0] == buf_arr[j2][0]) && (arr[j][1] == buf_arr[j2][1]))
			{
				buf_arr[j][0] = arr[j][0];
				buf_arr[j][1] = arr[j][1];
				buf_arr[j][2] = buf_arr[j][2] + arr[j][2];
				f = true;
			}
		}
		if (f == true)
			break;
		else
		{
			buf_arr[j][0] = arr[j][0];
			buf_arr[j][1] = arr[j][1];
			buf_arr[j][2] = arr[j][2];
			count++;
		}
	}
	for (int j = 0; j < quan; j++)
		free(arr[j]);
	free(arr);

	arr = new int* [count];
	for (int j = 0; j < count; j++)
		arr[j] = new int[3];

	for (int j = 0; j < count; j++)
	{
		arr[j][0] = buf_arr[j][0];
		arr[j][1] = buf_arr[j][1];
		arr[j][2] = buf_arr[j][2];
	}
	quan = count;

	for (int j = 0; j < quan; j++)
		free(buf_arr[j]);
	free(buf_arr);
}

void generator(int** &array1, int** &array2, int &quantity_digits1, int &quantity_digits2, int n, int m)
{
	srand(time(NULL));
	
	gen(array1, quantity_digits1,n,m);
	gen(array2, quantity_digits2,n,m);

	check(array1, quantity_digits1);
	check(array2, quantity_digits2);
}
