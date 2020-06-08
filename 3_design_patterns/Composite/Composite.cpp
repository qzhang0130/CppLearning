#include <cstdio>
#include <memory>
#include <iostream>
#include <vector>
using namespace std;

struct Expression{
	virtual double eval() = 0;
	virtual void collect(vector<double>& v) = 0;
};

struct Literal: Expression{
	double value;
	explicit Literal(const double value): value{value}{

	}

	double eval() override{
		return value;
	}

	void collect(vector<double>& v) override{
		v.push_back(value);
	}
};

struct AdditionExpression: Expression{
	shared_ptr<Expression> left, right;

	AdditionExpression(const shared_ptr<Expression>& expression, const shared_ptr<Expression>& expression1)
	:left{expression}, right{expression1}{

	}

	double eval() override{
		return left->eval() + right->eval();
	}

	void collect(vector<double>& v) override{
		left->collect(v);
		right->collect(v);
	}
};

int main(){
	AdditionExpression sum{
		make_shared<Literal>(2),
		make_shared<AdditionExpression>(
			make_shared<Literal>(3),
			make_shared<Literal>(4)
			)
	};
	cout<<"2+(3+4) = "<< sum.eval() <<endl;

	vector<double> v;
	sum.collect(v);
	for(auto x: v){
		cout<< x << "\t";
	}
	cout<<endl;

}