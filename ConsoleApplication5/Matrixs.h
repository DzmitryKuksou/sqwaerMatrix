#include<iostream>
using namespace std;
class RectangularMatrix
{
public:
	RectangularMatrix();
	RectangularMatrix(int, int);
	RectangularMatrix(const RectangularMatrix&);
	friend istream& operator>>(istream&, RectangularMatrix&);
	friend ostream& operator<<(ostream&, RectangularMatrix&);
	RectangularMatrix operator +(const RectangularMatrix&);
	RectangularMatrix operator *(const double);
	void CopyMatrix(const RectangularMatrix&);
	RectangularMatrix TransposingLinesByInverses();
	RectangularMatrix TransposingColumnsByInverses();
	virtual bool IsMatrixsEqual(RectangularMatrix&, RectangularMatrix&);
	virtual~RectangularMatrix();
protected:
	void Set(int, int);
	void SetStr(int);
	void SetColumn(int);
	void InitMatrix(int, int);
protected:
	int n, m;
	double** Matrix;
};
class SquareMatrix :public RectangularMatrix
{
public:
	SquareMatrix();
	SquareMatrix(int);
	SquareMatrix(const SquareMatrix&);
	void Transpose();
	void operator *(const SquareMatrix& b);
	bool IsMatrixsEqual(SquareMatrix&, SquareMatrix&);
	~SquareMatrix();
};