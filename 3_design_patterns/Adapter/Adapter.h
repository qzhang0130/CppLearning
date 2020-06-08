#include "Geometry.h"
#include <map>
#include <memory>

using namespace std;

vector<shared_ptr<VectorObject>> VectorObject{
	make_shared<VectorObject>(10, 10, 100, 100),
	make_shared<VectorObject>(30, 30, 60, 60)
};

struct LineToPointCachingAdapter{
	typedef vector<Point> Points;

	LineToPointCachingAdapter(Line& line){
		boost::hash<Line> hash;
		line_hash = hash(line);
		if(cache.find(line_hash) != cache.end())
			return;

		static int count = 0;

		Points points;

		int left = min(line.start.x, line.end.x);
		int right = max(line.start.x, line.end.x);
		int top = min(line.start.y, line.end.y);
		int bottom = max(line.start.y, line.end.y);
		int dx = right - left;
		int dy = line.end.y - line.start.y;

		if(dx == 0){
			for(int y = top; y <= bottom; ++y){
				points.emplace_back(Point{left, y});
			}
		}else if(dy == 0){
			for(int x = left; x <= right; ++x){
				points.emplace_back(Point{x, top});
			}
		}

		cache[line_hash] = points;
	}

	virtual Points::iterator begin() {return cache[line_hash].begin();}
	virtual Points::iterator end() {return cache[line_hash].end();}
private:
	size_t line_hash;
	static map<size_t, vector<Point>> cache;
};

map<size_t, vector<Point>> LineToPointCachingAdapter::cache;

struct LineToPointAdapter{
	typedef vector<Point> Points;

	LineToPointAdapter(Line& line){
		static int count = 0;

		int left = min(line.start.x, line.end.x);
		int right = max(line.start.x, line.end.x);
		int top = min(line.start.y, line.end.y);
		int bottom = max(line.start.y, line.end.y);

		int dx = right - left;
		int dy = line.end.y - line.start.y;

		if(dx == 0){
			for(int y = top; y <= bottom; ++y){
				points.emplace_back(Point{left, y});
			}
		}else if(dy == 0){
			for(int x = left; x <= right; ++x){
				points.emplace_back(Point{x, top});
			}
		}
	}

	virtual Points::iterator begin() { return points.begin();}
	virtual Points::iterator end() { return points.end();}
};