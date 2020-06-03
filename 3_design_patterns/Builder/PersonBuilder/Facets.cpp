#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

#include "Person.h"
#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

int main(){
	Person p = Person::create()
		.lives().at("ABC Road Apt 123").with_postcode("111111").in("Xihongshi")
		.works().at("ASoft").as_a("Analyst").earning(10e6);

	cout<<p<<endl;
	return 0;
}