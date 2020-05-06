#pragma once
#include <vector>
#include <iostream>

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

	// friend std::ostream& operator<<(std::ostream& os, Matrix<T>&);

	friend std::ostream& operator<<(std::ostream& os, Matrix<T>& mat){
		auto dim = mat.getDimensions();
		for(int i = 0; i < dim.first; i++){
			for(int j = 0; j < dim.second; j++){
				os<<mat.data_[i][j]<<" ";
			}
			os<< std::endl;
		}
		return os;
	}

private:
	std::vector<std::vector<T>> data_;
	int r_, c_;
};
