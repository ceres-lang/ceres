#pragma once

#include <cstdint>
#include <cstddef>
#include <string>

namespace ceres {
	struct Location {
		size_t col;
		size_t line;
	public:
		Location(size_t col, size_t line): col(col), line(line) {}
	};

	void print_error(const Location& loc, const std::string& msg);
};