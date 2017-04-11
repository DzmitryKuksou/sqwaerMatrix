#include<iostream>
#include"Matrixs.h"
using namespace std;
SquareMatrix::SquareMatrix(int t)
{
	RectangularMatrix(t, t);
}
SquareMatrix::SquareMatrix(const SquareMatrix& a)
{
	SquareMatrix(a.n);
	CopyMatrix(a);
}
void SquareMatrix::Transpose()
{
	double t;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; j++)
		{
			t = Matrix[i][j];
			Matrix[i][j] = Matrix[j][i];
			Matrix[j][i] = t;
		}
	}
}
void SquareMatrix::operator *(const SquareMatrix& b)
{
	for (int j1 = 0; j1 < b.n; j1++)
	{
		for (int j2 = 0; j2 < b.n; j2++)
		{
			for (int i5 = 0; i5 < b.n; i5++)
			{
				Matrix[j1][j2] += (Matrix[j1][i5] * b.Matrix[i5][j2]);
			}
		}
	}
}
SquareMatrix::~SquareMatrix()
{
	delete[]Matrix;
}
bool SquareMatrix::IsMatrixsEqual(SquareMatrix& a, SquareMatrix& b)
{
	if (a.n == b.n)return 1;
	return 0;
}