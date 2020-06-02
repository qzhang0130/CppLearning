#include <fstream>
#include <iostream>
#include <string>

class Repline{
private:
	std::fstream fs;
public:
	Repline(const std::string& s){
		fs.open(s, std::fstream::out);
	}

	void output(const std::string& s){
		fs<<s;
	}

	~Repline(){
		fs.close();
	}
};

int main(){
	Repline rp("a.txt");
	rp.output("Yes\n");
	rp.output("No\n");
	return 0;
}