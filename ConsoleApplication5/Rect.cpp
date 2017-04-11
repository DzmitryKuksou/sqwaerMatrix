#include<iostream>
#include"Matrixs.h"
using namespace std;
RectangularMatrix::RectangularMatrix()
{
	n = 0;
	m = 0;
	Matrix = new double*;
}
RectangularMatrix::RectangularMatrix(int n, int m)
{
	Set(n, m);
}
RectangularMatrix::RectangularMatrix(const RectangularMatrix& a)
{
	Set(a.n, a.m);
	CopyMatrix(a);
}
void RectangularMatrix::Set(int n, int m)
{
	SetStr(n);
	SetColumn(m);
	InitMatrix(n, m);
}
void RectangularMatrix::SetStr(int n)
{
	this->n = n;
}
void RectangularMatrix::SetColumn(int m)
{
	this->m = m;
}
void RectangularMatrix::InitMatrix(int n, int m)
{
	Matrix = new double*[n];
	for (int i = 0; i < m; i++)
	{
		Matrix[i] = new double[m];
	}
}
bool RectangularMatrix::IsMatrixsEqual(RectangularMatrix& a, RectangularMatrix& b)
{
	if (a.n == n&&a.m == m)return 1;
	return 0;
}
istream& operator>>(istream& s, RectangularMatrix& d)
{
	int k = 0, l = 0;
	while (true)
	{
		cout << "What matrix do you enter? (1)Rectangular or (2)Squared: ";
		cin >> k;
		if (k == 1)
		{
			cout << "EnterTheSize:\n";
			cin >> k;
			cin >> l;
			d.Set(k, l);
			break;
		}
		if (k == 2)
		{
			cout << "EnterTheSize:\n";
			cin >> l;
			d.Set(l, l);
			break;
		}
		cout << "enter 1 or 2\n";
		system("cls");
	}
		for (int i = 0; i < d.n; i++)
		{
			for (int j = 0; j < d.m; j++)
			{
				s >> d.Matrix[i][j];
			}
		}
	return s;
}
ostream& operator<<(ostream& s, RectangularMatrix& d)
{
	for (int i = 0; i < d.n; i++)
	{
		for (int j = 0; j < d.m; j++)
		{
			s  << d.Matrix[i][j] << " ";
		}
		s << endl;
	}
	return s;
}
void RectangularMatrix::CopyMatrix(const RectangularMatrix& a)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			Matrix[i][j] = a.Matrix[i][j];
		}
	}
}
RectangularMatrix RectangularMatrix:: operator +(const RectangularMatrix& a)
{
	RectangularMatrix b(n, m);
	for (int i = 0; i < a.n; i++)
	{
		for (int j = 0; j < a.m; j++)
		{
			b.Matrix[i][j] = Matrix[i][j] + a.Matrix[i][j];
		}
	}
	return b;
}
RectangularMatrix RectangularMatrix ::operator *(const double a)
{
	RectangularMatrix b(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			b.Matrix[i][j] = Matrix[i][j] * a;
	return b;
}
RectangularMatrix RectangularMatrix::TransposingLinesByInverses()
{
	int* a = new int[n];
	cout << "enter the vector of inverses(1,..." << n << "):\n";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	RectangularMatrix b(n, m);
	for (int i = 0; i < n; i++)
	{
		b.Matrix[i] = Matrix[a[i]];
	}
	return b;
}
RectangularMatrix RectangularMatrix::TransposingColumnsByInverses()
{
	int* a = new int[n];
	cout << "enter the vector of inverses(1,..." << n << "):\n";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	RectangularMatrix b;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b.Matrix[i][j] = Matrix[i][a[j]];
		}
	}
	return b;
}
RectangularMatrix::~RectangularMatrix()
{
	delete[]Matrix;
}