#include <vector>

class Matrix{
public:
	Matrix(std::vector<std::vector<int>>&);
	Matrix(const Matrix&);
	Matrix(int, int);

	Matrix& operator=(const Matrix& other);
	Matrix operator+(const Matrix& other);
	Matrix operator-(const Matrix& other);
	Matrix operator*(const Matrix& other);

	std::vector<std::vector<int>> getVector() const;

	std::pair<int, int> getDimensions() const;

	void print() const;

private:
	std::vector<std::vector<int>> data_;
	int r_, c_;
};
