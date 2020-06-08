#pragma once
#include <string>

class IBuffer{
public:
	virtual ~IBuffer(){

	}

	virtual Size get_size() const = 0;
	virtual char operator()(uint32_t x, uint32_t y) = 0;
	virtual void add_string(const std::string& s) = 0;
};