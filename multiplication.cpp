#include <iostream>
// умножение и вывод сразу
void output(int** array1, int** array2, int** array3, int quantity_digits1, int quantity_digits2, int con, int n, int m);

void multiplication(int** array1, int** array2, int quantity_digits1, int quantity_digits2, int n, int m)
{
	if (n != m)
	{
		puts(" Matrices are size-incompatible ");
		return;
	}

	int size = 0;
	int** array3 = nullptr;

	auto extend = [] // динамическое выделение памяти 
	(int** &arr, int& size, int diff)
	{
		int size_new = size + diff;
		int** arr_new = new int* [size_new];
		for (int i = 0; i < size; ++i)
			arr_new[i] = arr[i];
		for (int i = size; i < size_new; ++i)
			arr_new[i] = new int[3];
		free(arr);
		arr = arr_new;
		size = size_new;
	};

	auto find_elem = [] // поиск элемента
	(int** arr, int elem_i, int elem_j, int n)
	{
		for (int i = 0; i < n; i++)
		{
			if (arr[i][0] == elem_i && arr[i][1] == elem_j)
				return arr[i][2];
		}
		return 0;
	};

	auto write_elem = [&] // запись отдельного элемента в конечную матрицу 
	(int** &arr, int elem_i, int elem_j, int &n, int x)
	{
		if (x == 0)
			return;
		extend(arr, n, 1);
		arr[n - 1][0] = elem_i;
		arr[n - 1][1] = elem_j;
		arr[n - 1][2] = x;
	};

	for (int i = 0; i < n; i++) //цикл умножения
	{
		for (int k = 0; k < n; k++)
		{
			int s = 0;
			for (int j = 0; j < n; ++j)
			{
				s += find_elem(array1, i, j, quantity_digits1) * find_elem(array2, j, k, quantity_digits2);
			}
			write_elem(array3, i, k, size, s);
		}
	}
	output(array1, array2, array3, quantity_digits1, quantity_digits2, size, n, m);
}
