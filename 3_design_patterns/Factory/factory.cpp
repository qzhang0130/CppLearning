#include <cmath>

enum class PointType{
	cartesian,
	polar
};

class Point{
	Point(float a, float b):x(x), y(x){

	}
public:
	float x, y;

	friend class PointFactory;
};

class PointFactory{
	static Point NewCartesian(float x, float y){
		return Point{x, y};
	}

	static Point NewPolar(float r, float theta){
		return Point{r*cos(theta), r*sin(theta)};
	}
};