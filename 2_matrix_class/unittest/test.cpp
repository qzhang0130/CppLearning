#include "../src/matrix.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<vector<int>> vet1{{1,2}, {3,4}};
	vector<vector<int>> vet2{{1,3}, {2,4}};

	Matrix m1(vet1);
	m1.print();
	Matrix m2(vet2);
	m2.print();
	(m1*m2).print();

	Matrix c = m1 + m2;
	c.print();
	return 0;
}
