#include <cmath>

enum class PointType{
	cartesian,
	polar
};

class Point{
	Point(float a, float b):x(a), y(b){

	}
public:
	class PointFactory{
	public:
		static Point NewCartesian(float x, float y){
			return Point{x, y};
		}

		static Point NewPolar(float r, float theta){
			return Point{r*cos(theta), r*sin(theta)};
		}
	};
	float x, y;
	static PointFactory pointFactory;
};


int main(){
	auto p = Point::pointFactory.NewCartesian(10, 20);
	return 0;
}

