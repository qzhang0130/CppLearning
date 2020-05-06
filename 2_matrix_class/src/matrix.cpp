#include "matrix.h"
#include <iostream>
#include <utility>

template<typename T>
Matrix<T>::Matrix(std::vector<std::vector<T>>& data){
	data_ = std::move(data);
	r_ = data_.size();
	c_ = data_[0].size();
}

template<typename T>
Matrix<T>::Matrix(const Matrix& other){
	data_ = other.getVector();
	r_ = data_.size();
	c_ = data_[0].size();
}

template<typename T>	
Matrix<T>::Matrix(int r, int c):r_(r), c_(c), data_(r, std::vector<T>(c, 0)){
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other){
	data_ = other.data_;
	r_ = other.r_;
	c_ = other.c_;

	return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& other){
	Matrix<T> ans(*this);
	for(int i = 0; i < ans.r_; i++){
		for(int j = 0; j < ans.c_; j++){
			ans.data_[i][j] += other.data_[i][j];
		}
	}
	return ans;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix& other){
	Matrix<T> ans(*this);
	for(int i = 0; i < ans.r_; i++){
		for(int j = 0; j < ans.c_; j++){
			ans.data_[i][j] -= other.data_[i][j];
		}
	}
	return ans;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& other){
	auto dim2 = other.getDimensions();
	auto vec2 = other.getVector();

	int newR = r_, newC = dim2.second;
	std::vector<std::vector<T>> ans(newR, std::vector<T>(newC, 0));

	for(int i = 0; i < newR; i++){
		for(int j = 0; j < newC; j++){
			for(int k = 0; k < c_; k++){
				ans[i][j] += data_[i][k] * vec2[k][j];
			}
		}
	}
	return Matrix(ans);
}

template<typename T>
std::vector<std::vector<T>> Matrix<T>::getVector() const{
	return data_;
}

template<typename T>
std::pair<int, int> Matrix<T>::getDimensions() const{
	return {r_, c_};
}

template<typename T>
void Matrix<T>::print() const{
	for(int i = 0; i < r_; i++){
		for(int j = 0; j < c_; j++){
			std::cout<<data_[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}

template<typename T>
std::ostream& operator<<(std::ostream& os, Matrix<T>& mat){
	auto dim = mat.getDimensions();
	for(int i = 0; i < dim.first; i++){
		for(int j = 0; j < dim.second; j++){
			os<<mat[i][j]<<" ";
		}
		os<< std::endl;
	}
	return os;
}