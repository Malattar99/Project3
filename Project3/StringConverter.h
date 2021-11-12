#pragma once

#include <sstream>

class StringConverter
{
public:

	static int toInt(const std::string& str)
	{
		std::istringstream stream(str);
		int value;
		stream >> value;
		return value;
	}

	static std::string toString(int value)
	{
		std::ostringstream stream;
		stream << value;
		return stream.str();
	}
};