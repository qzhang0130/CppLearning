#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct Shape{
	virtual string str() const = 0;
};

struct Circle: Shape{
	float radius;

	Circle(){}

	explicit Circle(const float radius):radius(radius){

	}

	void resize(float factor){
		radius *= factor;
	}

	string str() const override{
		ostringstream oss;
		oss << "A circle of radius " << radius;
		return oss.str();
	}
};

struct Square: Shape{
	float side;

	Square(){}

	explicit Square(const float side):side{side}{

	}

	string str() const override{
		ostringstream oss;
		oss << "A square of with side " << side;
		return oss.str();
	}
};

struct ColoredShape: Shape{
	Shape& shape;
	string color;

	ColoredShape(Shape& shape, const string& color)
	:shape{shape},
	color{color}{

	}

	string str() const override{
		ostringstream oss;
		oss << shape.str() << " has the color " << color;
		return oss.str();
	}
};

struct TransparentShape: Shape{
	Shape& shape;
	uint8_t transparency;

	TransparentShape(Shape& shape, const uint8_t transparency)
	:shape{shape},
	transparency{transparency}{

	}

	string str() const override{
		ostringstream oss;

		oss << shape.str() << " has "
		<< static_cast<float>(transparency)/255.f*100.f
		<< "% transparency";

		return oss.str();
	}
};

template <typename T>
struct ColoredShape2: T{
	static_assert(is_base_of<Shape, T>::value,
		"Template argument must be a Shape");

	string color;

	ColoredShape2(){}

	explicit ColoredShape2(const string& color):color{color}{

	}

	string str() const override
	{
		ostringstream oss;
		oss << T::str() << " has the color "<<color;
		return oss.str();
	}
};

template<typename T>
struct TransparentShape2: T
{
	uint8_t transparency;

	template<typename...Args>
	TransparentShape2(const uint8_t transparency, Args ...args)
	: T(args...), transparency(transparency){

	}

	string str() const override{
		ostringstream oss;
		oss << T::str() << " has "
		<< static_cast<float>(transparency)/100.f*255.f
		<< "% transparency";

	return oss.str();
	}
};

int main(){
	Circle circle{5};
	cout<< circle.str() << endl;

	ColoredShape red_circle{circle, "red"};
	cout<<red_circle.str()<<endl;

	TransparentShape red_half_visible_circle{red_circle, 128};
	cout<< red_half_visible_circle.str() << endl;


	// mixin inheritance
	ColoredShape2<Circle> green_circle{"green"};
	green_circle.radius = 123;
	cout << green_circle.str() << endl;

	TransparentShape2<ColoredShape2<Square>> blue_invisible_square{0};
	blue_invisible_square.color = "blue";
	blue_invisible_square.side = 321;
	cout << blue_invisible_square.str() << endl;

	return 0;
}