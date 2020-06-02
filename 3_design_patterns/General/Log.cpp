#include <iostream>
#include <string>

class ILogger{
public:
	virtual void output(std::string s) = 0;
};

class ConsoleLogger: public ILogger{
public:
	void output(std::string s) override{
		std::cout<<s<<std::endl;
	}
};


int main(){
	ConsoleLogger cl;
	std::string s {"abc"};
	cl.output(s);
	return 0;
}