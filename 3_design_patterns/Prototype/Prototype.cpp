#include <vector>
#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct Address{
	string street;
	string city;
	int suite;

	friend std::ostream& operator<<(std::ostream& os, const Address& obj){
		return os
			<< "street: "<<obj.street
			<< " city: "<<obj.city
			<< " suite: "<<obj.suite;
	}
};

struct Contact{
	string name;
	Address* work_address;

	Contact(const string& name, Address* const work_address)
		:name(name), work_address(new Address(*work_address)){

	}

	~Contact(){
		delete work_address;
	}

	Contact(const Contact& other)
		:name(other.name), work_address(new Address(*other.work_address)){

	}

	friend std::ostream& operator<<(std::ostream& os, const Contact& obj){
		return os
			<< "name: " << obj.name
			<< " work_address: "<<*obj.work_address;
	}
};

struct EmployerFactory{
	static Contact main, aux;

	static unique_ptr<Contact> NewMainOfficeEmployee(string name, int suite){
		return NewEmployee(name, suite, main);
	}

	static unique_ptr<Contact> NewAuxOfficeEmployee(string name, int suite){
		return NewsEmployee(name, suite, aux);
	}

private:
	static unique_ptr<Contact> NewEmployee(string name, int suite, Contact& proto){
		auto result = make_unique<Contact>(proto);
		result->name = name;
		result->work_address->suite = suite;
		return result;
	}
};

Contact EmployerFactory::main{"", new Address{"123 East Dr", "New York", 0}};
Contact EmployerFactory::aux{"", new Address{"123 East Dr", "London", 0}};


int main(){
	auto john = EmployerFactory::NewMainOfficeEmployee("John", 20);
	auto jane = EmployerFactory::NewAuxOfficeEmployee("Jane", 30);

	cout << *john << endl << *jane <<endl;

	return 0;
}

