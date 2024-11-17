void output(int** array1, int** array2, int** array3, int quantity_digits1, int quantity_digits2, int con, int n, int m);

void subtraction(int** array1, int** array2, int quantity_digits1, int quantity_digits2, int n, int m)
{
	int sizear3 = quantity_digits1 + quantity_digits2;

	int** array3 = new int* [sizear3];
	for (int j = 0; j < sizear3; j++)
		array3[j] = new int[3];

	int con = 0;
	// вычитание первого массива на элементы второго и сложение в третьий
	for (int j = 0; j < quantity_digits1; j++)
	{
		bool f = false;
		for (int j2 = 0; j2 < quantity_digits2; j2++)
		{
			if ((array2[j2][0] == array1[j][0]) && (array2[j2][1] == array1[j][1]))
			{
				array3[con][0] = array2[j2][0];
				array3[con][1] = array2[j2][1];
				array3[con][2] = array1[j][2] - array2[j2][2];
				con++;
				f = true;
			}
		}
		if (f == false)
		{
			array3[con][0] = array1[j][0];
			array3[con][1] = array1[j][1];
			array3[con][2] = - array1[j][2];
			con++;
		}
		else continue;
	}

	int coun = con;
	// проверка элементов второго массива на наличие в третьем после вычитания
	for (int j = 0; j < quantity_digits2; j++)
	{
		bool f2 = false;
		for (int j2 = 0; j2 < coun; j2++)
		{
			if ((array2[j][0] == array3[j2][0]) && (array2[j][1] == array3[j2][1]))
			{
				f2 = true;
				break;
			}
		}
		if (f2 == true)
			continue;
		else
		{
			array3[con][0] = array2[j][0];
			array3[con][1] = array2[j][1];
			array3[con][2] = array2[j][2];
			con++;
		}
	}
	// передача всего в вывод
	output(array1, array2, array3, quantity_digits1, quantity_digits2, con, n, m);
}