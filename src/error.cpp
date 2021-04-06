#include "../include/error.h"

#include <iostream>

namespace ceres {
	void print_error(const Location& loc, const std::string& msg) {
		std::cout << "error: " << msg << ", at pos " << loc.col << ":" << loc.line << std::endl;
	}
}