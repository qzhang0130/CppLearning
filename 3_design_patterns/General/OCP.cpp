#include <iostream>
#include <string>
#include <vector>

enum class Color{Green, Blue, Red};
enum class Size{Small, Medium, Large};

struct Product{
	std::string name;
	Color color;
	Size size;
	Product(std::string name, Color color, Size size): name(name), color(color), size(size){}
};

template <typename T>
struct ISpecification{
	virtual bool is_satisfied(T* val) = 0;
};

template <typename T>
struct IFilter{
	virtual std::vector<T*> filter(std::vector<T*> items, ISpecification<T>& ispec) = 0;
};

struct BetterFilter: IFilter<Product>{
	typedef std::vector<Product*> Items;
	std::vector<Product*> filter(std::vector<Product*> items, ISpecification<Product>& spec) override{
		Items results;
		for(auto &i: items){
			if(spec.is_satisfied(i))
				results.push_back(i);
		}
		return results;
	}
};

struct ColorSpecification: ISpecification<Product>{
	Color color;

	explicit ColorSpecification(const Color color): color(color){

	}

	bool is_satisfied(Product* item) override{
		return item->color == color;
	}
};

struct SizeSpecification: ISpecification<Product>{
	Size size;
	explicit SizeSpecification(const Size size): size(size){

	}

	bool is_satisfied(Product* item) override{
		return item->size == size;
	}
};

template<typename T>
struct AddSpecification: ISpecification<T>
{
	ISpecification<T>& first;
	ISpecification<T>& second;

	explicit AddSpecification(ISpecification<T>& first, ISpecification<T>& second):first(first), second(second){

	}

	bool is_satisfied(Product* item) override{
		return first.is_satisfied(item) && second.is_satisfied(item);
	}
};

using std::cout;
using std::endl;

int main(){
	Product apple{"Apple", Color::Green, Size::Small};
	Product tree{"Tree", Color::Green, Size::Large};
	Product house("House", Color::Blue, Size::Large);

	std::vector<Product*> all{&apple, &tree, &house};

	BetterFilter bf;
	ColorSpecification green(Color::Green);

	auto green_things = bf.filter(all, green);

	for(auto& e: green_things){
		std::cout<<e->name<<" is green"<<std::endl;
	}

	SizeSpecification big(Size::Large);
	AddSpecification<Product> green_and_big(big, green);

	auto green_big_things = bf.filter(all, green_and_big);
	for(auto & e: green_big_things){
		std::cout<< e->name <<" is green and big"<<std::endl;
	}

	return 0;
}