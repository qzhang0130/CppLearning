class Matrix{
	Matrix(vector<vector<int>>&);
	Matrix(const Matrix&)
	Matrix(int, int);

	Matrix& operator=(const Matrix& other);
	Matrix operator+(const Matrix& other);
	Matrix operator-(const Matrix& other);
	Matrix operator*(const Matrix& other);

	void print();

private:
	vector<vector<int>> data;
	int row_, col_;
};
