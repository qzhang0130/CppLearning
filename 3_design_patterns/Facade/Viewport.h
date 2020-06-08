#pragma once
#include "IBuffer.h"
#include <boost/optional.h>

class Viewport{
protected:
	std::shared_ptr<IBuffer> buffer;

	Point buffer_location;

	Point screen_location;

	Size size;
public:
	Viewport(const std::shared_ptr<IBuffer>& buffer, boost::optional<Size> size=boost::none,
		boost::optional<Point> buffer_location = boost::none,
		boost::optional<Point> screen_location = boost::none): buffer(buffer){
		this->size = size.value_or(buffer->get_size());
		this->buffer_location = buffer_location.value_or(Point{});
		this->screen_location = buffer_location.value_or(Point{});
	}

	char operator()(int x, int y) const{
		if((x >= screen_location.x) && (screen_location.x + size.width) &&
			(y >= screen_location.y) && y < (screen_location.y + size.height)){
			(*buffer)(x-screen_location.x, y-screen_location.y);
		}
		return 0;
	}
}