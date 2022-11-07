// Lab_7_1.cpp
// < прізвище, ім’я автора >
// Лабораторна робота No 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 0
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount,
	const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void Sort(int** a, const int rowCount, const int colCount, int j);
void Change(int** a, const int row1, const int row2, const int colCount, int j, int rowCount);
int Calc(int** a, const int rowCount, const int colCount, int i, int j, int S, int k);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -26;
	int High = 23;
	int rowCount = 8;
	int colCount = 6;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High, 0, 0);
	Print(a, rowCount, colCount, 0, 0);
	Sort(a, rowCount, colCount, 0);
	Print(a, rowCount, colCount, 0, 0);
	int S = 0;
	int k = 0;
	S = Calc(a, rowCount, colCount, 0, 0, S, k);
	cout << "S = " << S << endl;
	Print(a, rowCount, colCount, 0, 0);
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int rowCount, const int colCount,
	const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
}
void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}
void Sort(int** a, const int rowCount, const int colCount, int j)
{
	for (int i0 = 0; i0 < rowCount - 1; i0++)
		for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
			if ((a[i1][0] < a[i1 + 1][0])
				||
				(a[i1][0] == a[i1 + 1][0] &&
					a[i1][1] > a[i1 + 1][1])
				||
				(a[i1][0] == a[i1 + 1][0] &&
					a[i1][1] == a[i1 + 1][1] &&
					a[i1][3] < a[i1 + 1][3]))
	Change(a, i1, i1 + 1, colCount, 0, rowCount);
}
void Change(int** a, const int row1, const int row2, const int colCount, int j, int rowCount)
{
	int tmp;
	if (j < colCount)
	{
		tmp = a[row1][j];
		a[row1][j] = a[row2][j];
		a[row2][j] = tmp;
		j++;
	}
	Sort(a, rowCount, colCount, j);
}
int Calc(int** a, const int rowCount, const int colCount, int i, int j, int S, int k)
{
	if (a[i][j] % 2 != 0 && a[i][j] < 0)
	{
		S += a[i][j];
		k++;
	}
	if (j < colCount - 1)
		return Calc(a, rowCount, colCount, i, j + 1, S, k);
	else
		if (i < rowCount - 1)
			return Calc(a, rowCount, colCount, i + 1, 0, S, k);
		else
			cout << "k" << k<< endl;
			return S;
}