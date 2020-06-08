#include <cstdio>
#include <iostream>
#include <memory>

using namespace std;

struct Logger{
	virtual ~Logger() = default;
	virtual void info(const string& s) = 0;
	virtual int warn(const string& s) = 0;
};


struct ConsoleLogger: Logger{
	int count = 0;

	void info(const string& s) override{
		cout << "INFO: " << s << endl;
	}

	int warn(const string& s) override{
		cout << "WARNING!!! " << s << endl;
		return count++;
	}
};

struct NullLogger: Logger{
	int warning_count;

	explicit NullLogger(const int warning_count):warning_count(warning_count){

	}

	void info(const string& s) override{

	}

	int warn(const string& s) override{
		return warning_count;
	}
};


int main(){
	auto logger1 = make_shared<NullLogger>(10);
	auto logger2 = make_shared<ConsoleLogger>();

	logger1->info("logger1 here"s);
	logger2->info("logger2 here"s);

	return 0;
}