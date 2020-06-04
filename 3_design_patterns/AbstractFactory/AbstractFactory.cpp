#include <iostream>
#include <memory>
#include <map>
#include "HotDrink.h"
#include "HotDrinkFactory.h"
#include "DrinkFactory.h"

using namespace std;

unique_ptr<HotDrink> make_drink(string type){
	unique_ptr<HotDrink> drink;

	if(type == "tea"){
		drink = make_unique<Tea>();
		drink->prepare(200);
	}else if(type == "coffee"){
		drink = make_unique<Coffee>();
		drink->prepare(50);
	}

	return drink;
}


int main(){
	auto d = make_drink("tea");

	DrinkFactory df;
	df.make_drink("coffee");

	DrinkWithVolumeFactory dvf;
	dvf.make_drink("tea");

	return 0;
}