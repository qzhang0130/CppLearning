#include <string>
#include <vector>

class Database{
private:
	Database(){}
	std::vector<std::string> lines;
public:
	static Database& get(){
		static Database db;
		return db;
	}

	std::string find_record(const std::string& name){
		return {};
	}
};

int main(){
	auto database = Database::get();
	return 0;
}