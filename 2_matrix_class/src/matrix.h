#pragma once
#include <vector>

template<typename T>
class Matrix{
public:
	Matrix(std::vector<std::vector<T>>&);
	Matrix(const Matrix<T>&);
	Matrix(int, int);

	Matrix<T>& operator=(const Matrix<T>& other);
	Matrix<T> operator+(const Matrix<T>& other);
	Matrix<T> operator-(const Matrix<T>& other);
	Matrix<T> operator*(const Matrix<T>& other);

	std::vector<std::vector<T>> getVector() const;

	std::pair<int, int> getDimensions() const;

	void print() const;

private:
	std::vector<std::vector<T>> data_;
	int r_, c_;
};
