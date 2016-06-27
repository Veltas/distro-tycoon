#ifndef STRICT_INPUT_FILE_STREAM_HPP_INCLUDED
#define STRICT_INPUT_FILE_STREAM_HPP_INCLUDED

#include <fstream>
#include <stdexcept>

class Strict_input_file_stream: public std::ifstream {
public:
	Strict_input_file_stream(const char* filename) :
		std::ifstream{filename}
	{
		if (!is_open()) {
			throw std::runtime_error{std::string{"Failed to open file "} + filename};
		}
	}
};

#endif // STRICT_INPUT_FILE_STREAM_HPP_INCLUDED
