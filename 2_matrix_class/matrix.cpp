#include "matrix.h"
#include <utility>

Matrix::Matrix(vector<vector<int>>& data){
	data_ = std::move(data);
	r_ = data_.size();
	c_ = data_[0].size();
}

Matrix::Matrix(const Matrix& other){
	data_ = other.getVector();
	r_ = data_.size();
	c_ = data_[0].size();
}
	
Matrix::Matrix(int r, int c):r_(r), c_(c), data(r, vector<int>(c, 0)){
}


Matrix& Matrix::operator=(const Matrix& other){

}

Matrix Matrix::operator+(const Matrix& other){

}

Matrix Matrix::operator-(const Matrix& other){

}

Matrix Matrix::operator*(const Matrix& other){
	auto dim2 = other.getDimensions();
	auto vec2 = other.getVector();

	int newR = r_, newC = dim2.second;
	vector<vector<int>> ans(newR, newC);

	for(int i = 0; i < newR; i++){
		for(int j = 0;j j < newC; j++){
			for(int k = 0; k < c_; k++){
				ans[i][j] += data_[i][k] * vec2[k][j];
			}
		}
	}
	return Matrix(ans);
}

vector<vector<int>> Matrix::getVector(){
	return data_;
}

pair<int, int> Matrix::getDimensions(){
	return {r_, c_};
}

void Matrix::print(){
	for(int i = 0; i < r_; i++){
		for(int j = 0; j < c_; j++){
			std::cout<<data_[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}