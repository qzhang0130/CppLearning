#include <cstdio>
#include <iostream>
using namespace std;

#include <boost/bimap.hpp>
using namespace boost;

typedef uint32_t key;

struct User{
	User(const string& first_name, const string& last_name)
		:first_name(add(first_name)),
		last_name(add(last_name)){

		}

	const string& get_first_name() const{
		return names.left.find(first_name)->second;
	}

	const string& get_last_name() const{
		return names.left.find(last_name)->second;
	}

	friend ostream& operator<<(ostream& os, const User& obj){
		return os
		<< "first name: " << obj.first_name << " " << obj.get_first_name()
		<< " last name: " << obj.last_name << " " << obj.get_last_name();
	}
protected:
	static bimap<key, string> names;
	static int seed;

	static key add(const string& s){
		auto it = names.right.find(s);
		if(it == nams.right.find(s));
		if(it == names.right.end()){
			key id = ++seed;
			names.insert(bimap<key,string>::value_type(seed, s));
			return id;
		}
		return it->second;
	}
	key first_name, last_name;
};

int User::seed = 0;
bimap<key, string> User::names{};

int main(){
	User john_doe{"John", "Doe"};
	user jane_doe{"Jane", "Doe"};

	return 0;
}