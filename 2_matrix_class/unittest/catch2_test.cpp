#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../src/matrix.h"
#include "../src/matrix.cpp"
#include <iostream>
#include <vector>

TEST_CASE( "Basic Matrix Structure Test", "[general]"){
	std::vector<std::vector<int>> vec1{{1,2}, {3,4}};
	Matrix<int> mat1(vec1);
	std::pair<int, int> p{2, 2};
	REQUIRE(mat1.getDimensions() == p);

	std::vector<std::vector<int>> vec2{{1,2, 3}, {3,4, 5}};
	Matrix<int> mat2(vec2);
	std::pair<int, int> p1{2, 3};
	REQUIRE(mat2.getDimensions() == p1);
}

TEST_CASE( "Matrix addition subtraction", "[general]"){
	std::vector<std::vector<int>> vec1{{1,2}, {3,4}};
	Matrix<int> mat1(vec1);

	std::vector<std::vector<int>> vec2{{1,2}, {3,4}};
	Matrix<int> mat2(vec2);

	Matrix<int> mat3 = mat1 + mat2;

	auto res = mat3.getVector();
	std::vector<std::vector<int>> ans{{2, 4}, {6, 8}};
	REQUIRE(res == ans);

	Matrix<int> mat4 = mat1 - mat2;
	ans = {{0, 0}, {0, 0}};
	res = mat4.getVector();
	REQUIRE(ans == res);
}

TEST_CASE( "Matrix multiplication", "[general]"){
	std::vector<std::vector<int>> vec1{{1,2}, {3,4}};
	Matrix<int> mat1(vec1);

	std::vector<std::vector<int>> vec2{{1,2}, {3,4}};
	Matrix<int> mat2(vec2);

	Matrix<int> mat3 = mat1 * mat2;

	auto res = mat3.getVector();
	std::vector<std::vector<int>> ans{{7, 10}, {15, 22}};
	REQUIRE(res == ans);

	vec1 = {{1, 2, 3}, {4, 5, 6}};
	vec2 = {{3}, {2}, {1}};
	Matrix<int> mat4(vec1);
	Matrix<int> mat5(vec2);

	Matrix<int> mat6 = mat4*mat5;
	res = mat6.getVector();
	ans = {{10}, {28}};
	REQUIRE(res == ans);

}

TEST_CASE( "Matrix multiplication double", "[general]"){
	std::vector<std::vector<double>> vec1{{1,2}, {3,4}};
	Matrix<double> mat1(vec1);

	std::vector<std::vector<double>> vec2{{1,2}, {3,4}};
	Matrix<double> mat2(vec2);

	Matrix<double> mat3 = mat1 * mat2;

	auto res = mat3.getVector();
	std::vector<std::vector<double>> ans{{7, 10}, {15, 22}};
	REQUIRE(res == ans);

	vec1 = {{1, 2, 3}, {4, 5, 6}};
	vec2 = {{3}, {2}, {1}};
	Matrix<double> mat4(vec1);
	Matrix<double> mat5(vec2);

	Matrix<double> mat6 = mat4*mat5;
	res = mat6.getVector();
	ans = {{10}, {28}};
	REQUIRE(res == ans);

}

TEST_CASE( "Matrix output", "[output]"){
	std::vector<std::vector<int>> vec1{{1,2}, {3,4}};
	Matrix<int> mat1(vec1);

	REQUIRE_NOTHROW(std::cout<<mat1<<std::endl);
}