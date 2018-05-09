#pragma once

#include <iostream>
#include <vector>


class Matrix
{
private:

	//Сама матрица
	std::vector<std::vector<double>> Data;

	// функции Друзья: Ввод 
	friend std::istream& operator >> (std::istream&, Matrix&);
	// функции Друзья: Вывод
	friend std::ostream& operator << (std::ostream&, const Matrix&);

public:
	// Инициализация матрицы
	Matrix(size_t n);

	//Проверка на размер
	//inline void size_check(const Matrix& other);

	// Возможность записывать матрицу через {}
	Matrix(const std::vector<std::vector<double>>& data) : Data(data) {}

	// Операция взятия индекса
	std::vector<double>& operator[](size_t i);
	const std::vector<double>& operator[](size_t i) const;


	// Операция сложения с числом
	Matrix& operator+=(double num);
	Matrix operator+(double num) const;


	// Операция вычитания числа
	Matrix& operator-=(double num);
	Matrix operator-(double num) const;


	// Операция умножения на число
	Matrix& operator*=(double num);
	Matrix operator*(double num) const;


	// Операция деления на число
	Matrix& operator/=(double num);
	Matrix operator/(double num) const;


	//Операция сложения матриц
	Matrix& operator+=(const Matrix& other);
	Matrix operator+(const Matrix& other) const;


	//Операция вычитания матриц
	Matrix& operator-=(const Matrix& other);
	Matrix operator-(const Matrix& other) const;


	//Операция умножения матриц
	Matrix operator*(const Matrix& other) const;

	
	//Недоделанный кусок кода
	double det();
};