#include "Matrix.h"
#include <cmath>

std::istream& operator >> (std::istream& stream, Matrix& matrix) 
{
	for (auto& i : matrix.Data)
		for (auto& j : i)
			stream >> j;
	return stream;
}

std::ostream & operator<<(std::ostream& stream, const Matrix& matrix)
{
	for (auto& i : matrix.Data)
	{
		for (auto& j : i) stream << j << " ";
		stream << std::endl;
	}
	return stream;
}

std::vector<double>& Matrix::operator[](size_t i)
{
	return Data[i];
}

Matrix::Matrix(size_t n) : Data(n)
{
	for (std::vector<double>& i : Data)
		i.resize(n);
}

/*inline void Matrix::size_check(Matrix other)
{

	for (std::vector<double>& i : other)
		
	if(Data.size() != other.size()) cout 
}*/


const std::vector<double>& Matrix::operator[](size_t i) const
{
	return Data[i];
}


Matrix& Matrix::operator+=(double num)
{
	for (auto& i : Data)
		for (auto& j : i)
			j += num;
	return *this;
}
Matrix Matrix::operator+(double num) const
{
	Matrix res(Data.size());
	for (size_t i = 0; i < Data.size(); ++i)
		for (size_t j = 0; j < Data.size(); ++j)
			res[i][j] = Data[i][j] + num;
	return res;
}


Matrix& Matrix::operator-=(double num)
{
	for (auto& i : Data)
		for (auto& j : i)
			j -= num;
	return *this;
}
Matrix Matrix::operator-(double num) const
{
	Matrix res(Data.size());
	for (size_t i = 0; i < Data.size(); ++i)
		for (size_t j = 0; j < Data.size(); ++j)
			res[i][j] = Data[i][j] - num;
	return res;
}

Matrix& Matrix::operator*=(double num)
{
	for (auto& i : Data)
		for (auto& j : i)
			j *= num;
	return *this;
}
Matrix Matrix::operator*(double num) const
{
	Matrix res(Data.size());
	for (size_t i = 0; i < Data.size(); ++i)
		for (size_t j = 0; j < Data.size(); ++j)
			res[i][j] = Data[i][j] * num;
	return res;
}


Matrix& Matrix::operator/=(double num)
{
	for (auto& i : Data)
		for (auto& j : i)
			j /= num;
	return *this;
}
Matrix Matrix::operator/(double num) const
{
	Matrix res(Data.size());
	for (size_t i = 0; i < Data.size(); ++i)
		for (size_t j = 0; j < Data.size(); ++j)
			res[i][j] = Data[i][j] / num;
	return res;
}


Matrix& Matrix::operator+=(const Matrix& other)
{
	for (size_t i = 0; i < Data.size(); ++i)
		for (size_t j = 0; j < Data.size(); ++j)
			Data[i][j] += other[i][j];
	return *this;
}
Matrix Matrix::operator+(const Matrix& other) const
{
	Matrix res(Data.size());
	for (size_t i = 0; i < Data.size(); ++i)
		for (size_t j = 0; j < Data.size(); ++j)
			res[i][j] = Data[i][j] + other[i][j];
	return res;
}


Matrix& Matrix::operator-=(const Matrix& other) 
{
	for (size_t i = 0; i < Data.size(); ++i)
		for (size_t j = 0; j < Data.size(); ++j)
			Data[i][j] -= other[i][j];
	return *this;
}
Matrix Matrix::operator-(const Matrix& other) const
{
	Matrix res(Data.size());
	for (size_t i = 0; i < Data.size(); ++i)
		for (size_t j = 0; j < Data.size(); ++j)
			res[i][j] = Data[i][j] - other[i][j];
	return res;
}


Matrix Matrix::operator*(const Matrix& other) const
{
	Matrix res(Data.size());
	double summ = 0;
	for (size_t i = 0; i < Data.size(); ++i)
		for (size_t j = 0; j < Data.size(); ++j)
		{
			for (size_t k = 0; k < Data.size(); k++)
				summ = summ + Data[i][k] * other[k][j];

			res[j][i] = summ;
			summ = 0;
		}
	return res;
}



double Matrix::det()
{
	size_t l;
	size_t n = Data.size();
	double Det;
	double sum11 = 1, sum12 = 0, sum21 = 1, sum22 = 0;

	for (size_t i = 0; i < n; i++)
	{
		sum11 = 1; l = 2 * n - 1 - i; sum21 = 1;
		for (size_t j = 0; j < n; j++)
		{
			sum21 *= Data[j][l%n];
			l--;
			sum11 *=  Data[j][(j + i) % (n)];
		}
		sum22 += sum21;
		sum12 += sum11;
	}
	Det = sum12 - sum22;
	return Det;
}


